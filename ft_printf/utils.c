#include "ft_printf.h"
//minus integer case is not managed....
//hex case does not manage minus...

char *ten_small_hex(unsigned int num)
{
	char *hex;
	char temp[12];
	char *ret;
	int i;
	int j;

	i = 0;
	if (0 == (hex = malloc(sizeof(char) *17)))
		return (0);
	ft_strlcpy(hex, "0123456789abcdef",17);
	while(num / 16 != 0)
	{
		temp[i++] = hex[num % 16];
		num = num / 16;
	}
	temp[i] = hex[num % 16];
	if (0 == (ret = malloc(sizeof(char) * (i + 1))))
		return (0);
	j = 0;
	while(i >= 0)
		ret[j++] = temp[i--];
	ret[j] = '\0';
	free(hex);
	return (ret);
}

char *ten_big_hex(unsigned int num)
{//%p할떄랑은 다른 방식을 취해야하는게 맞다..
	char *hex;
	char temp[12];
	char *ret;
	int i;
	int j;

	i = 0;
	//num = (unsigned int)ft_atoi(str);//just labeling
	if (0 == (hex = malloc(sizeof(char) *17)))
		return (0);
	ft_strlcpy(hex, "0123456789ABCDEF",17);
	while(num / 16 != 0)
	{
		temp[i++] = hex[num % 16];
		num = num / 16;
	}
	temp[i] = hex[num % 16];
	if (0 == (ret = malloc(sizeof(char) * (i + 1))))
		return (0);
	j = 0;
	while(i >= 0)
		ret[j++] = temp[i--];
	ret[j] = '\0';
	free(hex);
	return (ret);
}

char *ten_unsigned(unsigned int num)
{
	char *arr;
	char *ret;
	int i;
	int j;

	i = 0;
	if (0 == (arr = malloc(sizeof(char) * 15)))
		return (NULL);
	while (num > 0)
	{
		arr[i++] = num % 16;
		num = num / 16;
	}
	if (0 == (ret = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ret[i] = '\0';
	j = 0;
	while (i >= 0)
		ret[j++] = arr[i--];
	return (ret);
}

char *no_precision_int(char **line, int plus, int size, int lenth)
{
	char *ret;
	int i;

	i = 0;
	ret = malloc(sizeof(char) * (lenth + 1));
	ret[lenth] = '\0';
	ft_memset(ret, ' ', lenth);
	if (ft_strchr(line[1], '-') != 0)
	{
		while (i < plus)
			ret[i++] = '0';
		ft_strlcpy(&ret[i], line[5], size + 1);
		if (i + size != lenth)
			ret[i + size] = ' ';
	}
	else
	{
		i = lenth - size - plus;
		while (i < lenth - size)
			ret[i++] = '0';
		ft_strlcpy(&ret[i], line[5], size + 1);
	}
	return (ret);
}

char *precision_int(char **line, int plus, int size, int lenth)
{
	char *ret;
	int i;

	i = 0;
	if (0 == (ret = malloc(sizeof(char) * (lenth + 1))))
		return (0);
	ret[lenth] = '\0';
	if (ft_strchr(line[1], '0') != 0)
		ft_memset(ret, '0', lenth);
	else
		ft_memset(ret, ' ', lenth);
	if(ft_strchr(line[1], '-') != 0)
	{
		ft_strlcpy(ret, line[5], size + 1);
		if (ft_strchr(line[1], '0') != 0)
			ret[size] = '0';
		else
			ret[size] = ' ';
	}
	else
		ft_strlcpy(&ret[lenth - size], line[5], size + 1);
	return (ret);
}