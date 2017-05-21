#include "monty.h"

void parse_monty(char *filename, stack_t **stack, int fd)
{
	char *buffer, *p;
	int line_number;
	
	line_number = 1;
	buffer = malloc(1024);

	while((len = _readline(fd, &buffer)) != 0)
	{
		while (len && buffer[len - 1] == '\n')
			line[--len] = '\0';

		p = buffer;

		while (*p == ' ' || *p == '\t')
			p++;

		if (p[0] != '\0')
		{
			parse_line();
		}

		line_number++;
		memreset(line, 1024)
	}
	free(buffer);
}
