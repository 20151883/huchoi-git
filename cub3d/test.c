#include <stdio.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h>
#include <stdlib.h>
int get_next_line(int fd, char **line);
int main(void)
{
	char *line;
	int fd = open("val.cub", O_RDONLY);
	while (get_next_line(fd, &line))
	{
			printf("%s????\n", line);
			free(line);
	}
	free(line);
	while (1)
		printf("");
	return (0);
}