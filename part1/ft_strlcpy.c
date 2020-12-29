size_t ft_strlcpy(char *dst, char *src, size_t size)
{
	int ret;
	
	ret = 0;
	while(size--)
	{
		if(*src == 0)
			return ret;
		*(dst++) = *(src++);
	}
	while(*(src++) == 0)
		ret++;
	return (ret);
}
