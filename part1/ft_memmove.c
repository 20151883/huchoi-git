#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char arr[n];
	char *pdest;
	char *psrc;
	int count;

	pdest = (char *)dest;
	psrc = (const char *)src;
	while(count--)//루프불변성 생각하기!!
	{
		*(arr) = *(psrc++);
		*(pdest++) = *(arr++);
	}
	return (dest);
}
