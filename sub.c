#include "monty.h"


void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->prev == NULL)
	{
		opcode_error("can't sub, ","stack too short", line_number);
		return;
	}
	(*stack)->prev->n -= (*stack)->n;
	pop(stack,line_number);
}
