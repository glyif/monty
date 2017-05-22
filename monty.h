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
ssize_t _readline(int fd, char **buffer);

char *parse_tok(char *str);
void parse_monty();
void parse_line();
int parse_int(char *str);

int _atoi(char *s);
int write_uint(unsigned int n);
void opcode_error(char *msg1, char *msg2, int line_number);

void push(stack_t **stack,unsigned int line_number);
void pall(stack_t **stack,unsigned int line_number);
void pint(stack_t **stack,unsigned int line_number);
void pop(stack_t **stack,unsigned int line_number);

#endif
