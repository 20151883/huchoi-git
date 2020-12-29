int	ft_isalpha(int c)
{
	char ch;

	ch = c;
	if('A' <= ch && ch <= 'Z')
		return (1);
	else if('a' <= ch && ch <='z')
		return (2);
	else
		return (0);
}
