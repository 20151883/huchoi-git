char			**ft_split(char const *s, char c)
{
	int		start;
	int		end;
	int		len;
	char	**split;
	start = 0;
	end = 0;
	len = 0;
	if (!s)
		return (NULL);
	if (!(split = (char **)malloc(sizeof(char *) * (ft_word_count(s, c) + 1))))
		return (NULL);
	while (s[end])
	{
		if (s[end] != c) 
		{
			start = end;
			while (s[end] != c)
				end++;
			len = end - start;
			*split = ft_substr(s, start, len);
			split++;
			if (s[end] == 0)   break;
		}
		end++;
	}
	*split = NULL;
	return (split);
}

int	main(void)
{
	char *s = "split   this   string !!!   !";
	char c = ' ';
	printf("%d\n", ft_word_count(s, c));   // ft_word_count 확인
	char **split = ft_split(s, c);
	for (int i = 0; i < ft_word_count(s, c); i++)
		printf("-%s-", split[i]);
	return (0);
}