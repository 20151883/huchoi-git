#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int ret;

	ret = 0;
	while (str[ret])
		ret++;
	return (ret);
}

char *ft_strchr(char *src, char ch)
{
	while (*src)
	{
		if (*src == ch)
			return (src);
		src++;
	}
	return (NULL);
}

char *ft_strdup(char *src)
{
	char *ret;
	int lenth = 0;

	lenth = ft_strlen(src);
	ret = malloc(sizeof(char) * (lenth + 1));
	ret[lenth--] = 0;
	while (lenth >=0)
	{
		ret[lenth] = src[lenth];
		lenth--;
	}
	return (ret);
}

char *ft_strjoin(char *src, char *dest)
{
	int src_size = ft_strlen(src);
	int dest_size = ft_strlen(dest);
	char *ret = malloc(src_size + dest_size + 1);
	int idx=0;

	while (idx < src_size)
	{
		ret[idx] = src[idx];
		idx++;
	}
	while (idx < src_size + dest_size)
	{
		ret[idx] = dest[idx - src];
		idx++;
	}
	ret[idx] = 0;
	return (ret);
}
