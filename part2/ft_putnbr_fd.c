#include <unistd.h>
#include <stdlib.h>

static char *my_itoa(int n)
{
	char arr[12];
	int idx;
	int nb;
	char *ret;

	nb = n;
	if(nb < 0)
		nb = nb * (-1);
	idx = 0;
	while(nb / 10)
	{
		arr[idx++] = (nb % 10) + '0';
		nb = nb / 10;
	}
	arr[idx] = (nb % 10) + '0';
	if(nb < 0)
		arr[++idx] = '-';
	ret = malloc(sizeof(char) * (idx+1));
	nb = 0;
	while(idx >= 0)
		ret[nb++] = arr[idx--];
	ret[nb] = '\0';
	return (ret);
}

void	*ft_putnbr_fd(int n, int fd)
{
	char arr;

	arr = my_itoa(n);
	while(*arr)
		write(fd, arr++, sizeof(char));
}
