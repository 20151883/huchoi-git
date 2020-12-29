#include <unistd.h>

void ft_put_char(char c, int fd)
{
	write(fd, c, sizeof(char));
}
