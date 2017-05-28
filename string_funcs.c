#include "monty.h"

void pchar(stack_t **stack, unsigned int line_number) 
{
	if (*stack == NULL)
	{
		opcode_error("can't pchar, ","stack empty",line_number);
		return;
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		opcode_error("can't pchar, ","value out of range",line_number);  
		return;
	}
	putchar((*stack)->n);
	puts("");
}

void pstr(stack_t **stack, unsigned int line_number) 
{
	stack_t *s;

	(void)line_number;
	s = *stack;
	if (s != NULL)
    {
	    while (s->prev != *stack)
	    {
        	if (s->n <= 0 || s->n > 127)
        	    break;
        	putchar(s->n);
		    s = s->prev;
	    }
    	if (s->n > 0 && s->n <= 127)
    	    putchar(s->n);
    }
	puts("");
}
