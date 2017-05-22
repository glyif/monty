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
void parse_file();
void parse_line();

void print_hi(stack_t **stack, unsigned int line_number);

#endif
