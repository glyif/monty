#include "monty.h"

/**
 * popall - frees all in stack
 * @stack: pointer to stack
 */
void popall(stack_t **stack)
{
	stack_t *s, *t;

	s = *stack;
	while (s->prev != *stack)
	{
		t = s;
		s = s->prev;
		free(t);
	}
	free(s);
}

/**
 * freeall - frees all before exit
 * Return: exit status
 */
int freeall(void)
{
	int exit_code;

	exit_code = global_arginv->exit;
	if (global_arginv->stack != NULL)
		popall(&global_arginv->stack);
	free(global_arginv->input_commands);
	free(global_arginv);

	return (exit_code);
}

/**
 * buildarginv - initilalizes the global_arginv struct
 */
void buildarginv(void)
{
	global_arginv = malloc(sizeof(arg_inventory_t));
	global_arginv->input_commands = malloc(BUFSIZE * sizeof(char));
	global_arginv->buflimit = BUFSIZE;
	global_arginv->exit = EXIT_SUCCESS;
	global_arginv->stack = NULL;
	global_arginv->mode = 0;
}

/**
 * main - entry point
 * @argc: argument count
 * @argv: arguments
 *
 * Return: exit status
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	buildarginv();
	global_arginv->argument = argv[1];
	parse_monty();
	return (freeall());
}
