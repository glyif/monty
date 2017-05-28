#ifndef _MONTY_
#define _MONTY_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "base_structs.h"
#define BUFSIZE 1024
#define STACK 0
#define QUEUE 1
ssize_t _readline(int fd, char **buffer);
int freeall(void);

char *parse_tok(char *str);
void parse_monty(void);
void parse_line(void);
int parse_int(char *str);

int _atoi(char *s);
int write_uint(unsigned int n);
void opcode_error(char *msg1, char *msg2, int line_number);
arg_inventory_t *global_arginv;
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
#endif
