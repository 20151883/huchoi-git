#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	char *p;
	int count;

	p = (char*)s;
	count = n;

	while (count--)
		*(p++) = '\0';
}	
