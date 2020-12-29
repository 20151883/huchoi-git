char	*ft_strjoin(char const *s1, char const *s2)
{
	int len;
	int i;
	char *p;

	len = 0;
	i = 0;
	while(s1[i++] != '\0')
		len++;
	i = 0;
	while(s2[i++] != '\0')
		len++;
	p = (char *)malloc(sizeof(char) * (len + 1));

	i = 0;
	while(*(s1) != '\0')
		p[i++] = *(s1++);
	while(i < len)
		p[i++] = *(s2++);
	return (p);
}
