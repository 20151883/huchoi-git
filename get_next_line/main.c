#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    char *line;

    int fd = open("test.txt", O_RDONLY);
    while(get_next_line(fd, &line))
	{
		printf("%s\n", line);
		free(line);
	}
    return (0);
}
