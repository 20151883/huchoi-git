#include "ft_printf.h"
//minus integer case is not managed....
char *ten_small_hex(char *str)
{
	unsigned int num;
	char *hex;
	char temp[12];
	char *ret;
	int i;
	int j;

	i = 0;
	num = (unsigned int)ft_atoi(str);
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
	unsigned int num;
	char *hex;
	char temp[12];
	char *ret;
	int i;
	int j;

	i = 0;
	num = (unsigned int)ft_atoi(str);//just label
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

char *precision_int(char **p_ret, char *flag, char *precion)
{
	return (0);
}
