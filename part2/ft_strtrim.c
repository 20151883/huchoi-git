static int excluded_lenth(char const *s1, char const *set)
{
	int ret;
	int i;
	int j;

	i = 0;
	ret = 0;
	while(s1[i] != '\0')
	{
		ret++;//아님말구식...
		j = 0;
		while(set[j] != '\0')
		{
			if(set[i] == set[j])
			{
				ret--;
				break;
			}
			j++;
		}
		i++;
	}
	return (ret);
}

static int in_set(char c, char const *set)
{
	int i;
	
	i = 0;
	while(set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int i;
	char *p;
	int len;

	len = excluded_lenth(s1,set);
	p = malloc(sizeof(char) * (len + 1));
	while(s[i] != '\0')
	{
		if(!in_set(s[i], set))
			p[i] = s[i];
		i++;
	}
	p[i] = '\0';
}
