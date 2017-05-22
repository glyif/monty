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

int parse_int(char *str)
{
	char *p;
	
	p = str;
	if (*p == '-' || *p == '+')	/*skip sign*/
		p++;

	if (!*p)
		return 0;

	while (*p)
	{
		if(*p < '0' || *p > '9')	/* if it's not a digit, fail*/
			return 0;
		p++;
	}
	return (1);	/* if we reach this point the number is valid */
}

char *parse_token(char *str)
{
	char *p;
	
	p = str;
	while (*p && !_isspace(*p))
		p++;

	if (!*p)
		return p;

	*(p++)='\0';

	while(*p && _isspace(*p))
		p++;

	return (p);
}

void parse_line()
{
	char *line;
	int inst,n;
	instruction_t instructions[] =
	{
		{"push",push},
		{"pall",pall},
		{"pint",pint},
		{"pop",pop},
		{"swap",swap},
		{"add",add},
		{"nop",nop}
	};

	n = sizeof(instructions) / sizeof(instruction_t);
	line = global_arginv->argument;
	global_arginv->argument = parse_token(line);
	inst = -1;

	while ((++inst) < n)
	{
		if (!strcmp(line,instructions[inst].opcode))
		{
			parse_token(global_arginv->argument); /* to insert end of string at the end of next token */
			instructions[inst].f(&global_arginv->stack,global_arginv->line_number);						
			return;
		}
	}  
}

void parse_monty() 
{
	char *p;
	int fd; 
	int len;

	if ((fd = open(global_arginv->argument,O_RDONLY))==-1)
	{
		perror("Error: Can't open file ");
		perror(global_arginv->argument);
		perror("\n");
		freeall();
		exit(EXIT_FAILURE);
	}
	global_arginv->line_number = 1;

	while(global_arginv->exit != EXIT_FAILURE
		  && (len=_readline(fd,&global_arginv->input_commands))!=0)
	{
		if (len) 
		{
			while(len && global_arginv->input_commands[len - 1] == '\n')
			    global_arginv->input_commands[len--] = '\0';

			p = global_arginv->input_commands;

			while(*p==' ' || *p=='\t')
				p++;
			if(p[0]!=0) 
			{
				global_arginv->argument=p;
				parse_line();
			}
		}
		global_arginv->line_number++;
		memset(global_arginv->input_commands, '\0', global_arginv->buflimit);
  	}
	close(fd);
}
