#include "monty.h"

char _isspace(char c)
{
	int i;

	switch (c)
	{
	case ' ': case '\t': case '\n':
	case '\v': case '\f': case '\r':
		i = 1;
		break;
	default:
		i = 0;
		break;
	}

	return (i);
}

/**
 * parse_tok - tokenizes a command
 * @str: line to tokenize
 * 
 * Return: pointer to the second part of the token
*/
char *parse_tok(char *str)
{
	char *p;

	p = str;

	while (*p && _isspace(*p))
		p++;

	if(!*p)
		return (p);

	while (*p && _isspace(*p))
		p++;

	return (p);
}

void parse_monty(char *filename, stack_t **stack)
{
	int fd;
	char *buffer, *p;
	int line_number;
	int len;
	chanco_t args;
	
	line_number = 1;
	buffer = malloc(1024);

	fd = open(filename, O_RDONLY);
	len = 0;
	while((len = _readline(fd, &buffer)) != 0)
	{
		while (len && buffer[len - 1] == '\n')
			buffer[--len] = '\0';

		p = buffer;

		while (*p == ' ' || *p == '\t')
			p++;

		if (p[0] != '\0')
		{
			args.stack = stack;
			args.current_line = buffer;
			args.argument = NULL;
			parse_line(p, stack, line_number, &args);
		}

		line_number++;
		memset(buffer, '\0', 1024);
	}
	free(buffer);
	close(fd);
}

void parse_line(char *buffer, stack_t **stack, int line_number, chanco_t *args)
{
	int inst;

	instruction_t instructions[] = {
		{"print_hi", print_hi},
		{NULL, NULL}
	};

	args->argument = parse_tok(buffer);
	inst = -1;

	while(instructions[inst].f != NULL)
	{
		if (!strcmp(buffer, instructions[inst].opcode))
		{
			parse_tok(args->argument);
			instructions[inst].f(stack, args, line_number);
			return;
		}
		inst++;
	}
}
