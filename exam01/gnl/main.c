#include "gnl.h"
#include <stdio.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
	int fd = open("test.txt", O_RDONLY);
	char *line;

	while (get_next_line(fd, &line))
	{
		printf("%s\n",line);
		free(line);
	}
	printf("%s\n",line);
	free(line);
	return (0);
}
