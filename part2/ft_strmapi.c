#include <stdlib.h>

char *ft_strmapi(char const *s, char (f)(unsigned int, char))
{
	int idx;
	int size;
	char *ret;

	while(s[size])
		size++;
	ret = (char *)malloc(sizeof(char) * (size + 1));
	idx = 0;
	while(idx < size)
		ret[idx] = f(idx, s[idx++]);
	return (ret);
}
