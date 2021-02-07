#include "./includes/ft_printf.h"
char *precision_int(char **line, int plus, int size, int lenth)
{
	char *ret;
	int i;

	i = 0;
	if ( 0 == (ret = malloc(sizeof(char) * (lenth + 1))))
		return (0);
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
	return (minus_manage(line, &ret));
}

char *minus_manage(char **line, char **p_ret)
{
	if (ft_atoi(line[5]) < 0)
	{
		if (ft_strchr(*p_ret, '0') != 0)
		{
			*(ft_strchr(*p_ret, '0')) = '-';
			*(ft_strrchr(*p_ret, '-')) = '0';
			return (*p_ret);
		}
	}
	return (*p_ret);
}

char *precision_unsigned(char **line, int plus, int size, int lenth)
{
	char *ret;
	int i;
	
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
	return (ret);
}

char *no_precision_int(char **line, int size, int lenth)
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
		if (size != lenth)
			ft_memset(&ret[size], ' ', lenth - size);
	}
	else
		ft_strlcpy(&ret[lenth - size], line[5], size + 1);
	return (minus_manage(line, &ret));
}

char *no_precision_unsigned(char **line, int size, int lenth)
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
		if (size != lenth)
			ft_memset(&ret[size], ' ', lenth - size);
	}
	else
		ft_strlcpy(&ret[lenth - size], line[5], size + 1);
	return (ret);
}