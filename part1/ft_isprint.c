int	ft_isprint(int c)
{
	if (0 <= c && c <= 31)
		return (0);
	else
		return (1);
}
