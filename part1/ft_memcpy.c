#include <stdio.h>

void	*memcpy(void *dest, void *src, size_t n)
{
	char *pdest;
	char *psrc;
	int count;

	pdest = (char *)dest; 
	psrc = (char *)src;
	count = n;
	while(count--)
		*(pdest++) = *(psrc++);
	return (dest);
}
