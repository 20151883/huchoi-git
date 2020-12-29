char	*strrchr(const char *s, int c)
{
	char *save;
	char ch;

	save = '\0';
	ch = (char)c;

	while(*s != '\0')// do not understand this code but the eqal code....!!!
	{
		if(*s == ch)
			save = (s++);
		else
			s++;;
	}
	return (save);
}
