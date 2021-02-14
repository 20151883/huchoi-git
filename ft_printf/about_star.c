/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_star.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 16:03:52 by huchoi            #+#    #+#             */
/*   Updated: 2021/02/07 18:31:55 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int		not_star(char **line, char *str, char **p_temp, t_node *p_node)
{
	char	two[2];
	char	*arr;

	two[1] = '\0';
	two[0] = str[p_node->idx];
	if (0 == (arr = ft_strjoin(*p_temp, two)))
		return (free_ret_zero(line, *p_temp, NULL, p_node->my_case));
	free(*p_temp);
	*p_temp = arr;
	(p_node->idx)++;
	return (1);
}

int		over_star(t_node *p_node, char **line, char **p_temp)
{
	if (0 == star(line, p_temp, p_node->buf, p_node))
		return (0);
	p_node->buf = 0;
	line[p_node->my_case] = *p_temp;
	if (what_my_case(p_node->string[++(p_node->idx)], \
				p_node->my_case) == p_node->my_case)
		return (free_ret_zero(line, *p_temp, NULL, p_node->my_case));
	return (1);
}

int		star(char **line, char **p_temp, char *buf, t_node *p_node)
{
	int		case_my;
	char	*arr;
	char	*test;

	case_my = p_node->my_case;
	if (buf == 0)
		return (0);
	if (0 == (arr = malloc(ft_strlen(buf) + 1)))
		return (free_ret_zero(line, *p_temp, buf, case_my));
	if (case_my == 2 && (ft_strchr(buf, '-')))
	{
		if (0 == (test = ft_strjoin(line[1], "-")))
			return (free_ret_zero(line, *p_temp, buf, case_my));
		free(line[1]);
		line[1] = test;
	}
	if (case_my == 3)
		p_node->two_star = 1;
	if (0 == (arr = ft_strjoin(*p_temp, buf)))
		return (free_ret_zero(line, *p_temp, buf, case_my));
	free(*p_temp);
	free(buf);
	*p_temp = arr;
	return (1);
}
