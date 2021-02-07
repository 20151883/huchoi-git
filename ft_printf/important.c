/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   important.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 16:25:45 by huchoi            #+#    #+#             */
/*   Updated: 2021/02/07 16:33:00 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int		important(t_node *p_node, char **line, char **p_temp)
{
	if (42 == (p_node->ret = contact_with_format(p_node, line, p_temp)))
		return (1);
	else if (p_node->ret == 0)
		return (0);
	if (0 == (p_node->buf = ft_itoa(va_arg(g_ap, int))))
		return (free_ret_zero(line, *p_temp, 0, p_node->my_case));
	if (over_star(p_node, line, p_temp) == 0)
		return (0);
	return (1);
}

int		contact_with_format(t_node *p_node, char **line, char **p_temp)
{
	int	case_my;

	case_my = p_node->my_case;
	if (case_my != what_my_case((p_node->string)[p_node->idx], case_my))
	{
		if (!case_changed(line, p_temp, &(p_node->my_case)))
			return (0);
		return (42);
	}
	if (ft_strchr(".-0", p_node->string[p_node->idx]) != 0)
	{
		if (flag_precise(line, p_temp, p_node))
			return (42);
		else
			return (0);
	}
	if (p_node->string[p_node->idx] != '*')
	{
		if (1 == not_star(line, (char*)p_node->string, p_temp, p_node))
			return (42);
		else
			return (0);
	}
	return (1);
}

int		case_changed(char **line, char **p_temp, int *p_my_case)
{
	if (0 == (line[*p_my_case] = ft_strdup(*p_temp)))
		return (free_ret_zero(line, *p_temp, 0, *p_my_case));
	(*p_my_case)++;
	ft_memset(*p_temp, '\0', ft_strlen(*p_temp));
	**p_temp = '\0';
	return (1);
}

int		flag_precise(char **line, char **p_temp, t_node *p_node)
{
	char	two[2];
	char	*arr;
	char	*str;

	str = p_node->string;
	two[1] = '\0';
	if (str[p_node->idx] == '.')
	{
		(p_node->idx)++;
		p_node->is_precision = 1;
	}
	else if (str[p_node->idx] == '-' || str[p_node->idx] == '0')
	{
		two[0] = str[p_node->idx];
		if (0 == (arr = ft_strjoin(*p_temp, two)))
			return (free_ret_zero(line, *p_temp, 0, p_node->my_case));
		(p_node->idx)++;
		free(*p_temp);
		*p_temp = arr;
	}
	return (1);
}
