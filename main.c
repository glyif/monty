#include "monty.h"

int main(void)
{
	int fd;
	char *buffer;

	buffer = malloc(1024);
	fd = open("/home/vagrant/monty/test", O_RDONLY);

	while (_readline(fd, &buffer) > 0)
	{
		printf("%s", buffer);
	}

	return (0);
}
