int	ft_tolower(int c)
{
	int diff;

	diff = 'a' - 'A';
	if('A' <= c && c <= 'Z')
		return (c + diff);
	else
		return (c);
}
