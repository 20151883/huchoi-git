int	ft_isalnum(int c)
{
	char ch;

	ch = c;
	if('0' <= ch && ch <= '9')
		return (1);
	else if('A' <= ch && ch <= '9')
		return (1);
	else if('a' <= ch && ch <= 'z')
		return (1);
	else
		return (0);
}
