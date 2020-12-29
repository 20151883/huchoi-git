#include <stdio.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)i//you must think like divide and quanqer!!!
{
	char ch;
	char *pdest;
	char *psrc;
	int count;

	ch = (char)c;
	pdest = (char *)dest;
	psrc = (char *)src;
	count = n;

	while(count--)//일반적인 경우를 먼저 생각하자(기법...!), 루프 불변성을 생각 
	{
		if((*psrc) == ch)
		{
			*(pdest++) = *(psrc++);
			return ((void *)pdest);
		}
		*(pdest++) = *(psrc++);//pdest and psrc has same index!!!루프 불변성!
	}
	return (0);
}
