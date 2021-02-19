/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_integer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:08:12 by huchoi            #+#    #+#             */
/*   Updated: 2021/02/07 17:21:24 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

<<<<<<< HEAD
char *case_c(t_node *p_node, char **line)//check zero 하는건 어느 case에서나 다 해야하나 보다
=======
char	*case_c(t_node *p_node, char **line)
>>>>>>> 183c5b5879a29f93c13d8c85eb8c408746acdd63
{
	int		idx;
	int		lenth;
	char	*ret;

	if (check_is_zero(p_node, line, &lenth) == 1)
		return (ft_strdup(""));
	if (ft_strchr(line[1], '0') != 0 || *line[3] != '\0')
		return (0);
	if (atoi_positive(line[2]) > 0)
		lenth = atoi_positive(line[2]);
	else
		lenth = 1;
	if (0 == (ret = malloc(sizeof(char) * (lenth + 1))))
		return (0);
	ret[lenth] = '\0';
	(p_node->count) += lenth;
	idx = 0;
	while (idx < lenth)
		ret[idx++] = ' ';
	if (ft_strchr(line[1], '-') != 0 || ft_atoi(line[2]) < 0)
		ret[0] = *line[5];
	else
		ret[lenth - 1] = *line[5];
	return (ret);
}

int		check_is_zero(t_node *p_node, char **line, int *p_lenth)
{
	int i;

	i = 0;
	if (ft_strncmp(line[5], "(null)", 10) == 0)
	{
		*p_lenth = 1 > atoi_positive(line[2]) ? 1 : atoi_positive(line[2]);
		if (ft_strchr(line[1], '-'))
		{
			ft_putchar_fd(0, 1);
			while ((i++ < *p_lenth - 1) && p_node->two_star == 0)
				ft_putchar_fd(' ', 1);
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

char	*case_s(t_node *p_node, char **line, char **p_temp)
{
	int		i;
	int		size;
	int		lenth;
	char	*ret;

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

int		s_lenth_size(t_node *p_node, char **line, int *p_size, int *p_lenth)
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

<<<<<<< HEAD
char *case_percent(t_node *p_node, char **line, char**p_temp)
=======
char	*case_percent(t_node *p_node, char **line, char **p_temp)
>>>>>>> 183c5b5879a29f93c13d8c85eb8c408746acdd63
{
	int		lenth;
	char	*ret;

	lenth = 1;
	if (atoi_positive(line[2]) > lenth)
		lenth = atoi_positive(line[2]);
	if (0 == (ret = malloc(sizeof(char) * (lenth + 1))))
		free_ret_zero(line, *p_temp, 0, 6);
	ret[lenth] = '\0';
<<<<<<< HEAD
	(p_node->count)+=lenth;
	if(ft_strchr(line[1], '0') && !ft_strchr(line[1], '-'))//뒤에 조건 왜썼는지 순간 생각이 안남
=======
	(p_node->count) += lenth;
	if (ft_strchr(line[1], '0') && !ft_strchr(line[1], '-'))
>>>>>>> 183c5b5879a29f93c13d8c85eb8c408746acdd63
		ft_memset(ret, '0', lenth);
	else
		ft_memset(ret, ' ', lenth);
	if (ft_strchr(line[1], '-') != 0)
		ret[0] = '%';
	else
		ret[lenth - 1] = '%';
	return (ret);
}
