#include <stdio.h>

void	*memchr(const void *s, int c, size_t n)
{
	unsigned char ch;
	unsigned char *p;
	int count;

	ch = (unsigned char)c;
	p = (unsigned char*)s;
	count = n;

	while(count--)
	{
		if(*(p++) == ch)
			return ((void *)--p);
	}
	return (0);
}
