#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    char *line;
	int i = 0;

    int fd = open("test.txt", O_RDONLY);
    while(get_next_line(fd, &line))
	{
		printf("%s\n", line);
		free(line);
		i++;
	}
	printf("%d",i);
    return (0);
}
