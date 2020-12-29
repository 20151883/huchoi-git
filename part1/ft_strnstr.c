char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	int count;
	int i;
	int j;

	count=0;
	
	while(big[count] != '\0' && count < len)//모든 상황을 고려한것인가? 증명해보시오..!
	{	
		i = count;
		j = 0;
		while(i < len && small[j] != '\0')// count <len과 더불어  i<len 조건도 해주어야함.
		{
			if(big[i++] != small[j++])
				break;
		}
		if(i <= len && small[j] == '\0')
			return (&big[count]);
		count++;
	}
	return ('\0');
}
