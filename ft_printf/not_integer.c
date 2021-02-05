/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_integer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:08:12 by huchoi            #+#    #+#             */
/*   Updated: 2021/02/05 15:08:13 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

char *case_c(t_node *p_node, char **line)//dot procedure is needed
{
    int lenth;
    char *ret;
    int idx;

	if (check_is_zero(p_node, line, &lenth) == 1)
		return (ft_strdup(""));
    if (ft_strchr(line[1], '0') != 0 || *line[3] != '\0')//error처리
        return (0);
    if (atoi_positive(line[2]) > 0)
        lenth = atoi_positive(line[2]);
    else
        lenth = 1;
    ret = malloc(sizeof(char) * (lenth + 1));//[0] ~ [size-1]
	ret[lenth] = '\0';
	(p_node->count)+=lenth;
    idx = 0;
    while(idx < lenth)
        ret[idx++] = ' ';
    if (ft_strchr(line[1], '-') != 0 || ft_atoi(line[2]) < 0)
        ret[0] = *line[5];
    else
        ret[lenth - 1] = *line[5];
    return (ret);
}

int check_is_zero(t_node *p_node, char **line, int *p_lenth)
{
	int i;

	i = 0;
	if (ft_strncmp(line[5], "(null)", 10) == 0)
	{
		*p_lenth = 1 > atoi_positive(line[2]) ? 1 : atoi_positive(line[2]);
		if (ft_strchr(line[1], '-'))
		{
			ft_putchar_fd(0,1);
			while ((i++ < *p_lenth - 1) && p_node->two_star == 0)
				ft_putchar_fd(' ' ,1);
		}
		else
		{
			while ((i++ < *p_lenth - 1) && p_node->two_star == 0)
				ft_putchar_fd(' ', 1);
			ft_putchar_fd(0, 1);
		}
		p_node->count += *p_lenth;
		return (1);
	}
	return (0);
}

char *case_p(t_node *p_node, char **line)
{
	char *ret;
	int lenth;
	int size;
	char *save;

	save = trim_the_zero(line);
	//printf("TEST : %s", save);
	size = ft_strlen(save);
	if (atoi_positive(line[2]) > size)
		lenth = atoi_positive(line[2]);
	else
		lenth = size;
	p_node->count += lenth;
	if (p_node->p_p == 0 && (p_node->is_precision == 1) && (ft_atoi(line[3]) == 0))
		return (ft_strdup("0x"));
	ret = (char *)ft_calloc(sizeof(char), (lenth + 1));
	ret[lenth] = '\0';
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
    return (is_precision_zero(&ret, line, lenth));
}

char *is_precision_zero(char **p_ret, char **line, int lenth)
{
	/*if (p_node->is_precision == 1 && ft_atoi(line[3]) == 0 && 0)
	{
		*p_ret[2] = '0';
		*p_ret[3] = '\0';
	}*/
	if ((ft_strncmp(line[5], "0x0", 3) == 0) && (ft_strlen(line[5]) == 3))
	{
		ft_memset(*p_ret, ' ', lenth);
		*p_ret[0] = '0';
		*p_ret[1] = 'x';
		*p_ret[2] = '0';
	}
	return (*p_ret);
}
char *case_s(t_node *p_node, char **line, char**p_temp)
{
	int size;//character number
	int lenth;//buffer size
	char *ret;
	int i;

	i = 0;
	if (0 == s_lenth_size(p_node, line, &size, &lenth))
		return ((char *)ft_calloc(1, 1));
	if (0 == (ret = malloc(sizeof(char) * (lenth + 1))))
		free_ret_zero(line, *p_temp, 0, 6);
	ret[lenth] = '\0';
	(p_node->count) += lenth;
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

int s_lenth_size(t_node *p_node, char **line, int *p_size, int *p_lenth)
{
	*p_size = ft_strlen(line[5]);
	if ((0 < ft_atoi(line[3])) && (ft_atoi(line[3]) < *p_size))
		*p_size = ft_atoi(line[3]);
	*p_lenth = *p_size;
	if (*p_lenth < atoi_positive(line[2]) && *line[2] != '\0')
		*p_lenth = atoi_positive(line[2]);
	if (ft_atoi(line[3]) == 0 && p_node->is_precision == 1)
	{
		if (ft_atoi(line[3]) == 0)
		{
			*p_lenth = 0;
			*p_size = 0;
		}
		if ((atoi_positive(line[2]) > 0))
		{
			p_node->count += atoi_positive(line[2]);
			while ((*p_size)++ < atoi_positive(line[2]))
				ft_putchar_fd(' ', 1);
			return (0);
		}
	}
	return (1);
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
	if(ft_strchr(line[1], '0') && !ft_strchr(line[1], '-'))
		ft_memset(ret, '0', lenth);
	else
		ft_memset(ret, ' ', lenth);
	if (ft_strchr(line[1], '-') != 0)
		ret[0] = '%';
	else
		ret[lenth - 1] = '%';
    return (ret);
}
