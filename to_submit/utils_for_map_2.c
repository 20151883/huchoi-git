/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_map_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:00:46 by huchoi            #+#    #+#             */
/*   Updated: 2021/03/10 13:42:10 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_first(int fd, char **p_cur_buf)
{
	while (**p_cur_buf == '\0')
	{
		free(*p_cur_buf);
		get_next_line(fd, p_cur_buf);
	}
	while (ft_strchr(*p_cur_buf, ' '))
		*(ft_strchr(*p_cur_buf, ' ')) = '1';
}

void	check_upper_zero_is_null(char *cur, char *before)
{
	int idx;

	idx = -1;
	while (cur[++idx])
	{
		if (cur[idx] == '0' && ft_strlen(before) - 1 < idx)
			message_exit();
	}
}

void	check_upper_is_longer(char *cur, char *before)
{
	int cur_lenth;
	int before_lenth;
	int idx;

	cur_lenth = ft_strlen(cur);
	before_lenth = ft_strlen(before);
	if (before_lenth > cur_lenth)
	{
		idx = cur_lenth;
		while (before[idx])
		{
			if (before[idx++] == '0')
				message_exit();
		}
	}
}

int		valid_check(t_syn *p_syn, char **p_cur_buf, \
char **p_before_buf, int flag)
{
	while (ft_strchr(*p_cur_buf, ' '))
		*(ft_strchr(*p_cur_buf, ' ')) = '1';
	if (is_only_zero_blank_one(*p_cur_buf) != 1)
		message_exit();
	if (((*p_cur_buf)[0] != '1') || \
	((*p_cur_buf)[ft_strlen(*p_cur_buf) - 1] != '1'))
		message_exit();
	check_upper_zero_is_null(*p_cur_buf, *p_before_buf);
	check_upper_is_longer(*p_cur_buf, *p_before_buf);
	free(*p_before_buf);
	if (NULL == (p_syn->tri.test_map = \
	renewer_map(p_syn, p_syn->tri.test_map, *p_cur_buf)))
		message_exit();
	*p_before_buf = *p_cur_buf;
	if (flag == -1)
		message_exit();
	return (1);
}

int		get_last(t_syn *p_syn, char *cur_buf, char *before_buf, int ret)
{
	if (-1 == (check_last(before_buf)))
		message_exit();
	free(before_buf);
	while (ft_strchr(cur_buf, ' '))
		*(ft_strchr(cur_buf, ' ')) = '1';
	p_syn->tri.test_map = renewer_map(p_syn, p_syn->tri.test_map, cur_buf);
	free(cur_buf);
	if (ret == -1)
		message_exit();
	return (1);
}
