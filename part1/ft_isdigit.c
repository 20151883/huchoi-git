int ft_isdigit(int c)
{
	char ch;

	ch = c;
	if('0' <= ch && ch <= '9')
		return (1);
	else
		return (0);
}
