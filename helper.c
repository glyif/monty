#include "monty.h"

/**
 * _atoi - string to int
 * @s: string to convert
 *
 * Return: integer converted from string
 */
int _atoi(char *s)
{
	int result = 0, sign = 0, c;

	for (c = 0; s[c] != '\0'; c++)
	{
		if (s[c] == '-')
			sign++;
		if (s[c] > 47 && s[c] < 58)
		{
			while (s[c] > 47 && s[c] < 58)
				result = result * 10 - (s[c++] - 48);
			break;
		}
	}
	return (result *= sign % 2 == 0 ? -1 : 1);
}

/**
 * write_uint - prints unsigned int
 * @n: integer to print
 *
 * Return: number of chars written
 */
int write_uint(unsigned int n)
{
	unsigned int copy, size;
	int nth, chars_written = 0;

	size = 1;
	copy = n;
	if (n < 10)
	{
		putchar('0' + n);
		return (1);
	}
	while (copy / 10 != 0)
		copy /= 10, size *= 10;
	while (size > 0)
	{
		nth = n / size;
		putchar('0' + nth);
		n -= nth * size;
		size /= 10;
		chars_written++;
	}
	return (chars_written);
}

/**
 * opcode_error - prints error for a line monty
 * @msg1: unknown instrtuction
 * @msg2: actual instruction string
 * @line_number: line number the error happened
 */
void opcode_error(char *msg1, char *msg2, int line_number)
{
	printf("L");
	write_uint(line_number);
	printf(": ");
	printf("%s", msg1);
	if (msg2)
		printf("%s", msg2);
	printf("\n");
	global_arginv->exit = EXIT_FAILURE;
}
