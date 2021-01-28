#include "ft_printf.h"

char *case_c(char **line)
{
    int size;
    char *ret;
    int idx;

    if (ft_strchr(line[1], '0') != 0 || *line[3] != '\0')//error처리
        return (0);
    if (*line[2] != '\0')
        size = ft_atoi(line[2]);
    else
        size = 1;
    ret = malloc(sizeof(char) * (size + 1));//[0] ~ [size-1]
	ret[size] = '\0';
    idx = 0;
    while(idx < size)
        ret[idx++] = ' ';
    if (ft_strchr(line[1], '-') != 0)
        ret[0] = *line[5];
    else
        ret[size - 1] = *line[5];
    return (ret);
}

char *case_p(char **line)
{
    return (0);
}
char *case_s(char **line)
{
	int size;//character number
	int lenth;//buffer size
	char *buf;
	char *temp;
	char *ret;
	int i;

	i = 0;
	size = ft_strlen(line[5]);
	if (size > ft_atoi(line[3]) && *line[3] != '\0')
		size = ft_atoi(line[3]);
	lenth = size;
	if (lenth < ft_atoi(line[2]) && *line[2] != '\0')
	{
		lenth = ft_atoi(line[2]);
	}
	else
	{
		lenth = lenth + 0;
	}//[0] ~ [size] but  at [size] NULL ...so [0] ~ [size-1] ///[0]start or [size-lenth]start
	ret = malloc(sizeof(char) * (lenth + 1));
	ret[lenth] = '\0';//needed...!!!
	if(ft_strchr(line[1], '0') != 0)
		return (NULL);
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
char *case_percent(char **line)
{
    return (0);
}
