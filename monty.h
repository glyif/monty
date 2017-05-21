#ifndef _MONTY_
#define _MONTY_
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "base_structs.h"
ssize_t _readline(int fd, char **buffer);
#endif
