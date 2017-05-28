#include "monty.h"


void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->prev == *stack)
	{
		opcode_error("can't sub, ","stack too short", line_number);
		return;
	}
	(*stack)->prev->n -= (*stack)->n;
	pop(stack,line_number);
}


void divide(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->prev == *stack)
	{
		opcode_error("can't div, ","stack too short", line_number);
		return;
	}
	if ((*stack)->n == 0)
	{
		opcode_error("division by zero", NULL, line_number);
		return;
	}
	(*stack)->prev->n /= (*stack)->n;
	pop(stack,line_number);
}

void mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->prev == *stack)
	{
		opcode_error("can't mul, ","stack too short", line_number);
		return;
	}
	(*stack)->prev->n *= (*stack)->n;
	pop(stack,line_number);
}

void mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->prev == *stack)
	{
		opcode_error("can't mod, ","stack too short", line_number);
		return;
	}
	if ((*stack)->n == 0)
	{
		opcode_error("division by zero", NULL, line_number);
		return;
	}
	(*stack)->prev->n %= (*stack)->n;
	pop(stack,line_number);
}
