#include "monty.h"

/**
 * _isspace - checks for space characters
 * @c: char to check
 *
 * Return: 1 for space, 0 for not space
 */
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
 * parse_int - finds the integer
 * @str: command string
 *
 * Return: 0 if not found, 1 if found
 */
int parse_int(char *str)
{
	char *p;

	p = str;
	if (*p == '-' || *p == '+')	/*skip sign*/
		p++;

	if (!*p)
		return (0);

	while (*p)
	{
		if (*p < '0' || *p > '9')	/* if it's not a digit, fail*/
			return (0);
		p++;
	}
	return (1);	/* if we reach this point the number is valid */
}

/**
 * parse_token - tokenizes command line
 * @str: command line
 *
 * Return: pointer to second part of string
 */
char *parse_token(char *str)
{
	char *p;

	p = str;
	while (*p && !_isspace(*p))
		p++;

	if (!*p)
		return (p);

	*(p++) = '\0';

	while (*p && _isspace(*p))
		p++;

	return (p);
}

/**
 * parse_line - parses a command line
 */
void parse_line(void)
{
	char *line;
	int inst, n;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", divide},
		{"mul", mul},
		{"mod", mod},
		{"nop", nop},
		{"stack", stack},
		{"queue", queue},
		{"rotl", rotl},
		{"rotr", rotr},
		{"pchar", pchar},
		{"pstr", pstr}
	};

	n = sizeof(instructions) / sizeof(instruction_t);
	line = global_arginv->argument;
	global_arginv->argument = parse_token(line);
	inst = -1;

	while ((++inst) < n)
	{
		if (!strcmp(line, instructions[inst].opcode))
		{
			parse_token(global_arginv->argument);
			instructions[inst].f(&global_arginv->stack, global_arginv->line_number);
			return;
		}
	}
	opcode_error("unknown instruction ", line, global_arginv->line_number);
}

/**
 * parse_monty - parses monty file
 */
void parse_monty(void)
{
	char *p;
	int fd;
	int len;

	fd = open(global_arginv->argument, O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Can't open file %s\n", global_arginv->argument);
		freeall();
		exit(EXIT_FAILURE);
	}
	global_arginv->line_number = 1;

	while (global_arginv->exit != EXIT_FAILURE
		  && (len = _readline(fd, &global_arginv->input_commands)) != 0)
	{
		if (len)
		{
			while (len && global_arginv->input_commands[len - 1] == '\n')
				global_arginv->input_commands[--len] = '\0';

			p = global_arginv->input_commands;

			while (*p == ' ' || *p == '\t')
				p++;
			if (p[0] != 0 && p[0] != '#') /* ignore commented lines */
			{
				global_arginv->argument = p;
				parse_line();
			}
		}
		global_arginv->line_number++;
		memset(global_arginv->input_commands, '\0', global_arginv->buflimit);
	}
	close(fd);
}
