/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 10:49:29 by huchoi            #+#    #+#             */
/*   Updated: 2021/04/02 17:25:28 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_tex_path_by_idx(t_syn *p_syn, char **split, int idx)
{
	if (0 == (p_syn->tri.tex[idx].path = ft_strdup(split[1])))
		message_exit();
	if (split[2] != NULL)
		message_exit();
	else if (idx == 2)
		p_syn->no_flag = 1;
	else if (idx == 0)
		p_syn->ea_flag = 1;
	else if (idx == 3)
		p_syn->we_flag = 1;
	else if (idx == 1)
		p_syn->so_flag = 1;
	else if (idx == 4)
		p_syn->s_flag = 1;
	else
		message_exit();
}

int		check_news_sprite(char **split, t_syn *p_syn)
{
	if (is_valid_path(split[1]) == -1)
		message_exit();
	else if (ft_strncmp(split[0], "NO", 2) == 0 && p_syn->no_flag == 0)
		get_tex_path_by_idx(p_syn, split, 2);
	else if (ft_strncmp(split[0], "EA", 2) == 0 && p_syn->ea_flag == 0)
		get_tex_path_by_idx(p_syn, split, 0);
	else if (ft_strncmp(split[0], "WE", 2) == 0 && p_syn->we_flag == 0)
		get_tex_path_by_idx(p_syn, split, 3);
	else if (ft_strncmp(split[0], "SO", 2) == 0 && p_syn->so_flag == 0)
		get_tex_path_by_idx(p_syn, split, 1);
	else if (ft_strncmp(split[0], "S", 1) == 0 && p_syn->s_flag == 0)
		get_tex_path_by_idx(p_syn, split, 4);
	else
		message_exit();
	return (1);
}

int		check_r(char **split, t_syn *p_syn)
{
	if (*split[0] == 'R' && ft_strlen(split[0]) == 1)
	{
		if ((0 > ft_atoi(split[1]) || ft_atoi(split[1]) >= 2560))
			p_syn->r[0] = 2560;
		else
			p_syn->r[0] = ft_atoi(split[1]);
		if ((0 > ft_atoi(split[2]) || ft_atoi(split[2]) > 1440))
			p_syn->r[1] = 1440;
		else
			p_syn->r[1] = ft_atoi(split[2]);
		p_syn->r_flag = 1;
	}
	else
		message_exit();
	return (1);
}

int		check_f_c(char **split, t_syn *p_syn)
{
	p_syn->color = 0;
	if (-1 == is_valid_color(split))
		return (-1);
	if (*split[0] == 'F' && ft_strlen(split[0]) == 1)
	{
		p_syn->f_color = 0;
		p_syn->f_color += (ft_atoi(split[1]) << 16);
		p_syn->f_color += (ft_atoi(split[2]) << 8);
		p_syn->f_color += (ft_atoi(split[3]));
		p_syn->f_flag = 1;
	}
	else if (*split[0] == 'C' && ft_strlen(split[0]) == 1)
	{
		p_syn->c_color = 0;
		p_syn->c_color += (ft_atoi(split[1]) << 16);
		p_syn->c_color += (ft_atoi(split[2]) << 8);
		p_syn->c_color += (ft_atoi(split[3]));
		p_syn->c_flag = 1;
	}
	else
		message_exit();
	return (1);
}

void	par(t_syn *p_syn)
{
	int		fd;
	int		count;
	char	*buf;
	char	**split;
	char	nb;

	split = NULL;
	count = 0;
	if (-1 == (fd = open(p_syn->cub_path, O_RDONLY)))
		message_exit();
	free(p_syn->cub_path);
	init_flags(p_syn);
	while ((nb = get_next_line(fd, &buf)) && count < 8)
	{
		if (*buf == '\0')
			free(buf);
		else
		{
			par_the_line(p_syn, split, buf);
			count++;
		}
	}
	check_lines(nb, buf, count);
	check_flag(p_syn);
	is_valid_map(fd, p_syn);
}
