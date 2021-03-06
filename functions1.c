#include "monty.h"
/**
 * push - push a number onto the stack
 * @stack: pointer to stack
 * @line_number: line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *s;

	if (!parse_int(global_arginv->argument))
	{
		global_arginv->exit = EXIT_FAILURE;
		opcode_error("usage: ", "push integer", line_number);
		return;
	}
	s = malloc(sizeof(stack_t));
	if (s == NULL)
	{
		perror("malloc failed\n");
		freeall();
		exit(EXIT_FAILURE);
	}
	s->n = _atoi(global_arginv->argument);

	if (*stack != NULL)
	{
		s->next = (*stack)->next;
		(*stack)->next->prev = s;
		s->prev = (*stack);
		(*stack)->next = s;
	}
	else
	{
		s->next = s;
		s->prev = s;
		*stack = s;
	}

	if (global_arginv->mode == STACK)
		*stack = s;
}
/**
 * pall - prints all the values on the stack
 * @stack: pointer to stack
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *s;

	(void)line_number;
	s = *stack;
	if (s == NULL)
		return;
	while (s->prev != *stack)
	{
		write_uint(s->n);
		puts("");
		s = s->prev;
	}
	write_uint(s->n);
	puts("");
}
/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to stack
 * @line_number: line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		opcode_error("can't pint, ", "stack empty", line_number);
		return;
	}
	write_uint((*stack)->n);
	puts("");
}
/**
 * pop - removes the top element of the stack
 * @stack: pointer to stack
 * @line_number: line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *s;

	if (*stack == NULL)
	{
		opcode_error("can't pop an empty stack", NULL, line_number);
		return;
	}
	s = (*stack)->prev;
	if (s != *stack)
	{
		s->next = (*stack)->next;
		(*stack)->next->prev = s;
	}
	else
		s = NULL;

	free(*stack);
	*stack = s;
}
/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to stack
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int n;

	if (*stack == NULL || (*stack)->prev == *stack)
	{
		opcode_error("can't swap, ", "stack too short", line_number);
		return;
	}

	n = (*stack)->n;
	(*stack)->n = (*stack)->prev->n;
	(*stack)->prev->n = n;
}
