#ifndef BASE_STRUCTS
#define BASE_STRUCTS
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

typedef struct chanco_s
{
	char *argument;
	char *current_line;
	stack_t **stack;
} chanco_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack,unsigned int line_number);
} instruction_t;

typedef struct arg_inventory
{
	char   *input_commands;
	char   *argument;
	size_t buflimit;
	int	   line_number;
	stack_t *stack;
	
	int exit;
} arg_inventory_t;

arg_inventory_t *global_arginv;	/* global argument inventory */
#endif
