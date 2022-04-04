/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_integer_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 17:05:51 by huchoi            #+#    #+#             */
/*   Updated: 2021/02/07 17:08:26 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

char	*case_p(t_node *p_node, char **line)
{
	int		lenth;
	int		size;
	char	*ret;
	char	*save;

	ret = NULL;
	save = trim_the_zero(line);0x000000FDA231  0xFD231 = save 
	size = ft_strlen(save);
	lenth = define_lenth(p_node, line, size);
	p_node->count += lenth;
	if (0 == (ret = (char *)ft_calloc(sizeof(char), (lenth + 1))))
		return (0);
	ft_memset(ret, ' ', lenth);
	if (ft_strchr(line[1], '-'))
	{
		ft_strlcpy(ret, save, size + 1);
		if (size != lenth)
			ret[size] = ' ';
	}
	else
		ft_strlcpy(&ret[lenth - size], save, size + 1);
	free(save);
	return (is_precision_zero(ret, line, lenth, p_node));
}

int		define_lenth(t_node *p_node, char **line, int size)
{
	int width;

	width = atoi_positive(line[2]);
	if (atoi_positive(line[2]) > size)
		return (width);
	else if (p_node->p_p == 0)
	{
		if (p_node->is_precision == 1 && width <= 2)
			return (2);
		else if (width <= 3 && p_node->is_precision == 1)
			return (3);
	}
	return (size);
}

char	*is_precision_zero(char *ret, char **line, int lenth, t_node *p_node)
{
	if (p_node->p_p == 0)
	{
		if (p_node->is_precision == 1 && ft_atoi(line[3]) <= 2)
			make_0x(line, ret, lenth);
		else
			make_0x0(line, ret, lenth);
	}
	return (ret);
}

void	make_0x(char **line, char *ret, int lenth)
{
	ft_memset(ret, ' ', lenth);
	if (ft_strchr(line[1], '-'))
	{
		ret[0] = '0';
		ret[1] = 'x';
		if (atoi_positive(line[2]) <= 2)
			ret[2] = 0;
	}
	else
	{
		ret[lenth - 2] = '0';
		ret[lenth - 1] = 'x';
	}
}

void	make_0x0(char **line, char *ret, int lenth)
{
	ft_memset(ret, ' ', lenth);
	if (ft_strchr(line[1], '-'))
	{
		ret[0] = '0';
		ret[1] = 'x';
		ret[2] = '0';
		if (atoi_positive(line[2]) <= 3)
			ret[3] = 0;
	}
	else
	{
		ret[lenth - 3] = '0';
		ret[lenth - 2] = 'x';
		ret[lenth - 1] = '0';
	}
}
