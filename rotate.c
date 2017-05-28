#include "monty.h"

/**
 * rotl - rotl opcode
 * @stack: stack
 * @line_number: line number in file
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack == NULL)
		return;

	*stack = (*stack)->prev;
}

/**
 * rotr - rotr opcode
 * @stack: stack
 * @line_number: line number in file
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack == NULL)
		return;

	*stack = (*stack)->next;
}
