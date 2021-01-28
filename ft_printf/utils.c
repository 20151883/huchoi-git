#include "ft_printf.h"
//minus integer case is not managed....
char *ten_small_hex(char *str)
{
	int num;
	char *hex;
	char temp[12];
	char *ret;
	int i;
	int j;

	i = 0;
	num = ft_atoi(str);
	hex = malloc(sizeof(char) *17);
	ft_strlcpy(hex, "0123456789abcdef",17);
	while(num / 16 != 0)
	{
		temp[i++] = hex[num % 16];
		num = num / 16;
	}
	temp[i] = hex[num % 16];
	ret = malloc(sizeof(char) * (i + 1));
	j = 0;
	while(i >= 0)
		ret[j++] = temp[i--];
	ret[j] = '\0';
	free(hex);
	return (ret);
}

char *ten_big_hex(char *str)
{
	int num;
	char *hex;
	char temp[12];
	char *ret;
	int i;
	int j;

	i = 0;
	num = ft_atoi(str);
	hex = malloc(sizeof(char) *17);
	ft_strlcpy(hex, "0123456789ABCDEF",17);
	while(num / 16 != 0)
	{
		temp[i++] = hex[num % 16];
		num = num / 16;
	}
	temp[i] = hex[num % 16];
	ret = malloc(sizeof(char) * (i + 1));
	j = 0;
	while(i >= 0)
		ret[j++] = temp[i--];
	ret[j] = '\0';
	free(hex);
	return (ret);
}
