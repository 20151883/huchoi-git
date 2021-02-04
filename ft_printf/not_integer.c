#include "ft_printf.h"

char *case_c(t_node *p_node, char **line, char**p_temp)//dot procedure is needed
{
    int lenth;
    char *ret;
    int idx;

    if (ft_strchr(line[1], '0') != 0 || *line[3] != '\0')//error처리
        return (0);
    if (*line[2] != '\0')
        lenth = atoi_positive(line[2]);
    else
        lenth = 1;
    ret = malloc(sizeof(char) * (lenth + 1));//[0] ~ [size-1]
	ret[lenth] = '\0';
	(p_node->count)+=lenth;
    idx = 0;
    while(idx < lenth)
        ret[idx++] = ' ';
    if (ft_strchr(line[1], '-') != 0)
        ret[0] = *line[5];
    else
        ret[lenth - 1] = *line[5];
    return (ret);
}//malloc fail then return 0...
//but if (in case malloc fail) we just ret = 0;
//then return (ret)....??  

char *case_p(t_node *p_node, char **line, char**p_temp)
{
	char *ret;
	int lenth;
	int size;
	int plus;
	char *save;

	save = line[5];
	save+=2;
	while (*save != '0')
		save++;//done
	size = ft_strlen(save) + 2;//0x//only number of character
	if (atoi_positive(line[2]) > size)
		lenth = atoi_positive(line[2]);
	else
		lenth = size;
	ret = (char *)ft_calloc(sizeof(char), (lenth + 1));
	ft_memset(ret, ' ', lenth);
	if (ft_strchr(line[1], '-'))//0 flag is not used...?
		ft_strlcpy(ret, line[5], size + 1);
	else
		ft_strlcpy(&ret[lenth - size], line[5], size + 1);
	printf("\nTEST : ret = %s\n", ret);
    return (ret);
}

char *case_s(t_node *p_node, char **line, char**p_temp)
{
	int size;//character number
	int lenth;//buffer size
	char *ret;
	int i;

	i = 0;
	size = ft_strlen(line[5] );
	if ((0 < ft_atoi(line[3])) && (ft_atoi(line[3]) < size))
	{
		size = ft_atoi(line[3]);
	}
	//printf("atoi(line[3] = %d   ft_strlen(line[5] = %d", ft_atoi(line[3]), ft_atoi(line[5]));
	lenth = size;
	if (lenth < atoi_positive(line[2]) && *line[2] != '\0')
	{
		lenth = atoi_positive(line[2]);
	}
	else
	{
		lenth = lenth + 0;
	}//[0] ~ [size] but  at [size] NULL ...so [0] ~ [size-1] ///[0]start or [size-lenth]start
	if (ft_atoi(line[3]) == 0 && p_node->is_precision == 1)
	{
		if (ft_atoi(line[3]) == 0)
		{
			lenth = 0;
			//lenth = 1???
			size = 0;
			//ft_putchar_fd(' ', 1);
		}
		if ((atoi_positive(line[2]) > 0))// && ft_strchr(line[2], '-')) //&& *line[1] == '\0')
		{
			p_node->count += atoi_positive(line[2]);
			while (size++ < atoi_positive(line[2]))
				ft_putchar_fd(' ', 1);
			char *test;
			test = ft_calloc(1,1);
			return (test);
		}
	}
	if (0 == (ret = malloc(sizeof(char) * (lenth + 1))))
		free_ret_zero(line, *p_temp, 0, 6);
	ret[lenth] = '\0';//needed...!!!
	(p_node->count)+=lenth;
	if(ft_strchr(line[1], '0') != 0)
	{
		while (i < lenth)
			ret[i++] = ' ';
	}	//return (NULL);//ssh printf는 출력은 시키던데...???
	else
	{
		while(i < lenth)
			ret[i++] = ' ';
	}
	if (ft_strchr(line[1], '-') != 0)
	{
		ft_strlcpy(&ret[0], line[5], size + 1);
		if (size != lenth)
			ret[size] = ' ';
	}
	else
		ft_strlcpy(&ret[lenth - size], line[5], size + 1);
    return (ret);
}

char *case_percent(t_node *p_node, char **line, char**p_temp)
{
	int lenth;
	char *ret;

	lenth = 1;
	if (atoi_positive(line[2]) > lenth)
		lenth = atoi_positive(line[2]);
	if (0 == (ret = malloc(sizeof(char) * (lenth + 1))))
		free_ret_zero(line, *p_temp, 0, 6);
	ret[lenth] = '\0';
	(p_node->count)+=lenth;
	if(ft_strchr(line[1], '0') != 0)
		ft_memset(ret, '0', lenth);
	else
		ft_memset(ret, ' ', lenth);
	if (ft_strchr(line[1], '-') != 0)
		ret[0] = '%';
	else
		ret[lenth - 1] = '%';
    return (ret);
}
