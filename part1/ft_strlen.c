#include <stdio.h>

size_t ft_strlen(const char *s)
{
	const char *p;
	int count;

	p = s;
	count = 0;
	while(1)//아무 근거없이 p++ 연산하지말고 일단 최대한 긴 코드 구상하고 거기서 종속성 판단해서 짧은 코드로 바꾸기.
	{
		if(*p++ == '\0')
			return (count);
		count++:
	}
}
