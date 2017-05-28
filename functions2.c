#include "monty.h"
/**
 * add - adds the top two elements of the stack
 * @stack: pointer to stack
 * @line_number: line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->prev == *stack)
	{
		opcode_error("can't add, ", "stack too short", line_number);
		return;
	}
	(*stack)->prev->n += (*stack)->n;
	pop(stack, line_number);
}
/**
 * nop - doesn't do anything
 * @stack: pointer to stack
 * @line_number: line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * stack - sets the format of the data to a stack (LIFO)
 * @stack: pointer to stack
 * @line_number: line number
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	global_arginv->mode = STACK;
}
/**
 * queue - sets the format of the data to a queue (FIFO)
 * @stack: pointer to stack
 * @line_number: line number
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	global_arginv->mode = QUEUE;
}
