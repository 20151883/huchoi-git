#include "get_next_line.h"
​
int	ft_strlen(char *str)
{
	int i;
​
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
​
char	*ft_strdup(const char *src)
{
	char	*temp;
	int		i;
​
	i = 0;
	temp = (char *)malloc((unsigned int)(ft_strlen((char *)src) + 1));
	if (temp == 0)
		return (0);
	while (src[i] != '\0')
	{
		temp[i] = src[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
​
char	*ft_strndup(const char *src, int index)
{
	char	*temp;
	int		i;
​
	i = 0;
	if (!(temp = (char *)malloc(index + 1)))
		return (0);
	while (i < index)
	{
		temp[i] = src[i];
		i++;
	}
	temp[index] = '\0';
	return (temp);
}
​
void	*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	void			*temp;
	const void		*s;
	unsigned int	i;
​
	temp = dest;
	s = src;
	i = 0;
	if (n == 0 || dest == src)
		return (dest);
	while (i < n)
	{
		*((char *)temp + i) = *((char *)s + i);
		i++;
	}
	return (dest);
}
​
char	*ft_strjoin(char const *s1, char const *s2)
{
	char				*temp;
	unsigned int		sum;
​
	if (s1 == 0 || s2 == 0)
		return (0);
	sum = 0;
	sum += ft_strlen((char *)s1) + ft_strlen((char *)s2);
	if (!(temp = (char *)malloc(sum + 1)))
		return (0);
	ft_memcpy(temp, s1, ft_strlen((char *)s1) + 1);
	ft_memcpy(temp + ft_strlen((char *)s1), s2, ft_strlen((char *)s2) + 1);
	return (temp);
}