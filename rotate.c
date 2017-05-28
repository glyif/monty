#include "base_stucts.h"

void rotl(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	
	if (*stack == NULL)
		return;

	*stack = (*stack)->prev;
}

void rotr(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack == NULL)
		return;

	*stack = (*stack)-next;
}
