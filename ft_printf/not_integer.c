#include "includes/ft_printf.h"

char *case_c(t_node *p_node, char **line, char**p_temp)
{
    int lenth;
    char *ret;
    int idx;

	if (check_null(p_node, line, p_temp, &lenth) == 1)
		return (ft_strdup(""));
    if (ft_strchr(line[1], '0') != 0 || *line[3] != '\0')
        return (0);
    if (*line[2] != '\0')
        lenth = atoi_positive(line[2]);
    else
        lenth = 1;
    ret = malloc(sizeof(char) * (lenth + 1));
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
}

char *case_p(t_node *p_node, char **line, char**p_temp)
{
	char *ret;
	int lenth;
	int size;
	int plus;
	char *save;

	save = trim_the_zero(line);
	size = ft_strlen(save);
	if (atoi_positive(line[2]) > size)
		lenth = atoi_positive(line[2]);
	else
		lenth = size;
	p_node->count+=lenth;
	ret = (char *)ft_calloc(sizeof(char), (lenth + 1));
	ft_memset(ret, ' ', lenth);
	if (ft_strchr(line[1], '-'))//0 flag is not used...?00...
	{
		ft_strlcpy(ret, save, size + 1);
		if (size != lenth)
			ret[size] = ' ';
	}
	else
		ft_strlcpy(&ret[lenth - size], save, size + 1);
	free(save);
    return (ret);
}

char *case_s(t_node *p_node, char **line, char**p_temp)
{
	int size;//character number
	int lenth;//buffer size
	char *ret;
	int i;

	i = 0;
	if (compute_lenth(p_node, line, &size, &lenth) == 0)
		return (ft_strdup(""));
	if (0 == (ret = malloc(sizeof(char) * (lenth + 1))))
		free_ret_zero(line, *p_temp, 0, 6);
	ret[lenth] = '\0';//needed...!!!
	(p_node->count)+=lenth;
	while (i < lenth)
		ret[i++] = ' ';
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
