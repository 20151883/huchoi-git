/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_par.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:04:04 by huchoi            #+#    #+#             */
/*   Updated: 2021/03/08 11:04:06 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_flag(t_syn *p_syn)
{
	int num;

	num = 0;
	num += p_syn->r_flag;
	num += p_syn->c_flag;
	num += p_syn->f_flag;
	num += p_syn->s_flag;
	num += p_syn->no_flag;
	num += p_syn->so_flag;
	num += p_syn->we_flag;
	num += p_syn->ea_flag;
	if (num != 8)
		message_exit();
}

void	init_flags(t_syn *p_syn)
{
	p_syn->we_flag = 0;
	p_syn->so_flag = 0;
	p_syn->ea_flag = 0;
	p_syn->no_flag = 0;
	p_syn->s_flag = 0;
	p_syn->c_flag = 0;
	p_syn->f_flag = 0;
	p_syn->r_flag = 0;
}

int		is_valid_color(char **split)
{
	if ((0 > ft_atoi(split[1]) || ft_atoi(split[1]) > 255))
		return (-1);
	if ((0 > ft_atoi(split[2]) || ft_atoi(split[2]) > 255))
		return (-1);
	if ((0 > ft_atoi(split[3]) || ft_atoi(split[3]) > 255))
		return (-1);
	return (1);
}

int		case_by_lenth(char **split, t_syn *p_syn, int lenth)
{
	int ret;

	if (lenth == 2)
		ret = check_news_sprite(split, p_syn);
	else if (lenth == 3)
		ret = check_r(split, p_syn);
	else if (lenth == 4)
		ret = check_f_c(split, p_syn);
	else
		message_exit();
	return (1);
}

int		is_valid_path(char *path)
{
	int fd;
	int ret;

	ret = 1;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		message_exit();
	close(fd);
	return (ret);
}
