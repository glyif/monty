#include "monty.h"

void push(stack_t **stack, unsigned int line_number) 
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
	s->n = _atoi(global_arginv->argument);

	if(*stack!=NULL)
	{
        s->next = (*stack)->next;
        (*stack)->next->prev=s;
        s->prev = * stack;
		(*stack)->next = s;
	}
    else
    {
        s->next=s;
        s->prev=s;
    	*stack = s;    	
    }
    if(global_arginv->mode == STACK)
    	*stack = s;    	
}

void pall(stack_t **stack, unsigned int line_number) 
{
	stack_t *s;

	(void)line_number;
	s = *stack;
	if(s == NULL)
	    return;
	while(s->prev != *stack)
	{
		write_uint(s->n);
		puts("");
		s = s->prev;
	}
	write_uint(s->n);
	puts("");
}

void pint(stack_t **stack, unsigned int line_number) 
{
	if(*stack == NULL)
	{
		opcode_error("can't pint, ","stack empty",line_number);
		return;
	}
	write_uint((*stack)->n);
	puts("");
}

void pop(stack_t **stack, unsigned int line_number) 
{
	stack_t *s;

	if (*stack == NULL)
	{
		opcode_error("can't pop an empty stack",NULL,line_number);  
		return;
	}
	s = (*stack)->prev;
	if (s != *stack)
	{
		s->next = (*stack)->next;
		(*stack)->next->prev=s;
    }
    else
        s=NULL;
	free(*stack);
	*stack = s;
}

void swap(stack_t **stack, unsigned int line_number) 
{
	int n;

	if (*stack == NULL || (*stack)->prev == *stack)
	{
		opcode_error("can't swap, ","stack too short",line_number);  
		return;
	}
	
	n = (*stack)->n;
	(*stack)->n = (*stack)->prev->n;
	(*stack)->prev->n = n;
}

void add(stack_t **stack, unsigned int line_number) 
{
	if (*stack == NULL || (*stack)->prev == *stack)
	{
		opcode_error("can't add, ","stack too short",line_number);  
		return;
	}
	(*stack)->prev->n += (*stack)->n;
	pop(stack,line_number);
}

void nop(stack_t **stack, unsigned int line_number) 
{
	(void)stack;
	(void)line_number;
}

void stack(stack_t **stack, unsigned int line_number) 
{
	(void)stack;
	(void)line_number;
    global_arginv->mode = STACK;
}

void queue(stack_t **stack, unsigned int line_number) 
{
	(void)stack;
	(void)line_number;
    global_arginv->mode = QUEUE;
}
