#include <unistd.h>

void ft_putendl_fd(char *s, int fd)
{
	char c;
	
	c = '\n';
	while(*s)
		write(fd, s++, sizeof(char));
	
	write(fd, &c, sizeof(char));
}
