#include "monty.h"

/**
 * _readline - reads a line from a file
 * @fd: file descriptor to read from
 * @buffer: buffer to read to
 *
 * Return: number of chars read
 */
ssize_t _readline(int fd, char **buffer)
{
	unsigned int i, j;
	ssize_t count;

	count = 0;
	i = -1;
	j = 0;

	while (i != 0)
	{
		i = read(fd, (*buffer + j), 1);

		if (i <= 0)
			break;

		count++;

		if ((*buffer + j++)[0] == '\n')
			break;
	}

		return(count);
}
