int	ft_atoi(const char *s)//다시 짜야함...!!
{
	int idx;
	int ret;

	idx = 0;
	ret = 0;
	while('0' <= s[idx] && s[idx] <= '9')//수학적인 계산법이 가미되는...!
	{	
		ret = ret * 10;	
		ret += (s[idx] - '0');
		idx++;
	}
	return (ret);
}
