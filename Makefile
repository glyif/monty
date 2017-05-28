CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic
LIBS=
EXENAME=monty

CFILES=\
	parse.c\
	readline.c\
	helper.c\
	functions.c\
	math_funcs.c\
	rotate.c\
	string_funcs.c

GLOBAL_HEADERS=\
	monty.h

# Make goals
all: $(GLOBAL_HEADERS) $(CFILES) main.c
	$(CC) $(CFLAGS) $(CFILES) main.c -o $(EXENAME) $(LIBS)

debug: $(GLOBAL_HEADERS) $(CFILES) main.c
	$(CC) $(CFLAGS) $(CFILES) main.c -o $(EXENAME) $(LIBS) -g

clean:
	rm -f $(EXENAME)
