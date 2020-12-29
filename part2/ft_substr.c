char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int count;
	int idx;
	char *ret;

	count = 0;
	idx = start;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if(ret == 0)
		return ('\0');

	while((count < len) && (s[idx] != '\0'))//모든 상황을 고려한것인지 일일이 증명하든가, 아니면 동치관계 먼저 증명한 다음에 본과정 진행하든가.	
	{// 루프 불변성, 액션, ~일때까지 == ~상태까지.(논리적 기술, 기법....)
		ret[count] = s[idx];
		count++;
		idx++;
	}
	ret[count] = '\0';
	return (ret);
}
