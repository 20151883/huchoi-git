int strncmp(const char *s1, const char *s2, size_t len)
{
	int idx;

	idx = 0;

	while(idx < len)
	{
		if(s1[idx] != s2[idx])
			break;
		idx++;
	}
	if(idx == len)
		return (0);
	return (s1[idx] - s2[idx]) ;
}
