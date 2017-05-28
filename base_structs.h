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
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct arg_inventory - input arguments struct
 * @input_commands: input command
 * @argument: input number
 * @buflimit: buffer limit
 * @line_number: line number
 * @stack: stack struct
 * @mode: 0 for stack, 1 for queue
 * @exit: exit status, failure or success
 */
typedef struct arg_inventory
{
	char *input_commands;
	char *argument;
	size_t buflimit;
	int line_number;
	stack_t *stack;
	int mode;
	int exit;
} arg_inventory_t;

#endif
