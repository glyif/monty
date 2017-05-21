#ifndef _MONTY_
#define _MONTY_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "base_structs.h"
ssize_t _readline(int fd, char **buffer);

char *parse_tok(char *str);
void parse_monty(char *filename, stack_t **stack);
void parse_line(char *buffer, stack_t **stack, int line_number, chanco_t *vars);

void print_hi(stack_t **stack, chanco_t *args, unsigned int line_number);

#endif
