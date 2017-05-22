#include "monty.h"

void push(stack_t **stack,unsigned int line_number) 
{
	stack_t *s;

	if(!parse_int(global_arginv->argument))
	{
		global_arginv->exit=EXIT_FAILURE;
		opcode_error("usage: ","push integer",line_number);
		return;
	}
	if ((s = malloc(sizeof(stack_t)))==NULL)
	{
		perror("malloc failed\n");
		freeall();
		exit(EXIT_FAILURE);
	}
	s->prev = *stack;
	s->next = NULL;
	s->n = _atoi(global_arginv->argument);

	if(*stack!=NULL)
		(*stack)->next = s;

	*stack = s;
}

void pall(stack_t **stack,unsigned int line_number) 
{
	stack_t *s;

	(void)line_number;
	s = *stack;
	while(s)
	{
		write_uint(s->n);
		puts("");
		s = s->prev;
	}
}

void pint(stack_t **stack,unsigned int line_number) 
{
	if(*stack == NULL)
	{
		opcode_error("can't pint, ","stack empty",line_number);
		return;
	}
	write_uint((*stack)->n);
	puts("");
}

void pop(stack_t **stack,unsigned int line_number) 
{
	stack_t *s;

	if (*stack == NULL)
	{
		opcode_error("can't pop an empty stack",NULL,line_number);  
		return;
	}
	s = (*stack)->prev;
	if (s != NULL)
		s->next = NULL;

	free(*stack);
	*stack = s;
}
