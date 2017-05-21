#include "monty.h"

int main(int argc,char **argv)
{
	stack_t *stack;

	stack=NULL;
	parse_monty(argv[1],&stack);
	return (0);
}
