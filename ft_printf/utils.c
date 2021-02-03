#include "ft_printf.h"
//minus integer case is not managed....
//hex case does not manage minus...

char *ten_small_hex(unsigned long long num)
{
	char *hex;
	char temp[15];
	char *ret;
	int i;
	int j;
	unsigned int as;

	as = num;
	i = 0;
	if (0 == (hex = malloc(sizeof(char) *17)))
		return (0);
	ft_strlcpy(hex, "0123456789abcdef",17);
	while(as > 0)
	{
		temp[i++] = hex[as % 16];
		as = as / 16;
	}
	if (0 == (ret = malloc(sizeof(char) * (i-- + 1))))
		return (0);
	j = 0;
	while(i >= 0)
		ret[j++] = temp[i--];
	ret[j] = '\0';
	free(hex);
	if (num == 0)
	{
		free(ret);
		ret = malloc(sizeof(char) * 2);
		ret[0] = '0';
		ret[1] = '\0';
	}
	return (ret);
}

char *ten_big_hex(unsigned long long num)
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
	if (num == 0)
	{
		free(ret);
		ret = malloc(sizeof(char) * 2);
		ret[0] = '0';
		ret[1] = '\0';
	}
	return (ret);
}

char *ten_unsigned(unsigned long long num)
{
	char arr[16];
	char *ret;
	int i;
	int j;
	unsigned int as;

	as = num;
	i = 0;
	while (as > 0)
	{
		arr[i++] = (as % 10) + '0';
		as = as / 10;
	}
	if (0 == (ret = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	j = 0;
	i--;
	while (i >= 0)
		ret[j++] = arr[i--];
	ret[j] = '\0';
	if (num == 0)
	{
		free(ret);
		ret = malloc(sizeof(char) * 2);
		ret[0] = '0';
		ret[1] = '\0';
	}
	return (ret);
}

char *precision_int(char **line, int plus, int size, int lenth)
{
	char *ret;
	int i;
	char save;
	i = 0;
	ret = malloc(sizeof(char) * (lenth + 1));
	ft_memset(ret, ' ', lenth);
	ret[lenth] = '\0';
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
	//printf("TEST : [%s]", ret);
	//printf("size : %d plus : %d lenth : %d", size,plus,lenth);
	if (ft_atoi(line[5]) < 0)
	{
		if(ft_strchr(ret, '0') != 0)
		{
			*(ft_strchr(ret, '0')) = '-';
			*(ft_strrchr(ret, '-')) = '0';
		}
		/*swap = ret[lenth - size - plus];
		ret[lenth -size - plus] = ret[lenth - size];
		ret[lenth - size] = swap;*/
	}
	return (ret);
}

char *no_precision_int(char **line, int plus, int size, int lenth)
{
	char *ret;
	int i;
	unsigned int num;
	char two[2];

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
		if (size != lenth)
			ft_memset(&ret[size], ' ', lenth - size);
	}
	else
		ft_strlcpy(&ret[lenth - size], line[5], size + 1);
	//in_minus_case_in_check(char **line, char **p_ret)
	two[1] = '\0';
	char *arr;
	/*if (ft_atoi(line[5]) < 0)
	{
		two[0] = '-';
		*(ft_strchr(ret, '-')) = '0';
		arr = ft_strjoin(two, ret);
		free(ret);
		ret = arr;
		//return (0);//change his
	}*/
	//else
		//return (0);
	if (ft_atoi(line[5]) < 0)
	{
		if(ft_strchr(ret, '0') != 0)
		{
			*(ft_strchr(ret, '0')) = '-';
			*(ft_strrchr(ret, '-')) = '0';
		}
		/*char swap;
		swap = ret[lenth - size - plus];
		ret[lenth -size - plus] = ret[lenth - size];
		ret[lenth - size] = swap;*/
	}
	return (ret);
}

int check_zero(char **line, int *p1, int *p2, int *p3)
{
	if (ft_atoi(line[5]) == 0 && ft_atoi(line[3]) == 0)
	{
		*p1 = 0;
		*p2 = 0;
		*p3 = 0;
		return (1);
	}
	else
		return (0);
}

int atoi_positive(char *str)
{
	int num;

	//printf("before action : %d", ft_atoi(str));
	if (ft_strchr(str, '-'))
		*(ft_strchr(str, '-')) = '0';
	num = ft_atoi(str);
	//printf("after... : %d", num);
	return (num);
}