int	ft_toupper(int c)
{
	int diff;

	diff = 'a' - 'A';
	if('a' <= c && c <= 'z')
		return (c - diff);
	else
		return (c);
}
