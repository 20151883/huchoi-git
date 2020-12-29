char	*ft_strchr(const char *s, int c)
{
	char ch;
	char *p;
	
	ch = (char)c;
	p = s;
	while(*p != '\0')
	{
		if (*p == c)
			return (p);
		else
			p++;
	}
	return ('\0');
}
