size_t ft_strlcat(char *dst, const char *src, size_t size)
{
	int count;
	
	count = 0;
	while(*dst != '\0' && count++ < size)//이 루프의 동치관계인 코드를 생각해보라!!
		dst++;
	while((count++ < size) && (*src != '\0'))
		*(dst++) = *(src++);
	while((*src++) != '\0')
		count++;
	return (count);
}
