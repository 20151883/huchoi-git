void	*ft_memset(void *s, int c, size_t n)// size_t 에 대해 알아볼것.
{
	int count;
	char *p;
	char ch;

	count = n;
	p = (char *)s;
	ch = (char)c;

	while(count)
		*(p++) = ch;
	return (s);
}
