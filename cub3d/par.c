#include "cub3d.h"

void	get_tex_path_by_idx(t_syn *p_syn, char **split, int idx)
{
	if (0 == (p_syn->tri.tex[idx].path = strdup(split[1])))
		message_exit();
	if (idx == 0)
		p_syn->no_flag = 1;
	else if (idx == 1)
		p_syn->ea_flag = 1;
	else if (idx == 2)
		p_syn->we_flag = 1;
	else if (idx == 3)
		p_syn->so_flag = 1;
	else if (idx == 4)
		p_syn->s_flag = 1;
	p_syn->no_flag = 1;
}

int		check_news_sprite(char **split, t_syn *p_syn)
{
	if (is_valid_path(split[1]) == -1)
		return (-1);
	else if (strcmp(split[0], "NO") == 0 && p_syn->no_flag == 0)
		get_tex_path_by_idx(p_syn, split, 0);
	else if (strcmp(split[0], "EA") == 0 && p_syn->ea_flag == 0)
		get_tex_path_by_idx(p_syn, split, 1);
	else if (strcmp(split[0], "WE") == 0 && p_syn->we_flag == 0)
		get_tex_path_by_idx(p_syn, split, 2);
	else if (strcmp(split[0], "SO") == 0 && p_syn->so_flag == 0)
		get_tex_path_by_idx(p_syn, split, 3);
	else if (strcmp(split[0], "S") == 0 && p_syn->s_flag == 0)
		get_tex_path_by_idx(p_syn, split, 4);
	else
		message_exit();
	return (1);
}

int		check_r(char **split, t_syn *p_syn)
{
	if (*split[0] == 'R' && strlen(split[0]) == 1)
	{
		if ((0 > atoi(split[1]) || atoi(split[1]) >= 2560))
			p_syn->R[0] = 2560;
		else
			p_syn->R[0] = ft_atoi(split[1]);
		if ((0 > ft_atoi(split[2]) || ft_atoi(split[2]) > 1440))
			p_syn->R[1] = 1440;
		else
			p_syn->R[1] = atoi(split[2]);
		p_syn->r_flag = 1;
	}
	else
		return (-1);
	return (1);
}

int		check_f_c(char **split, t_syn *p_syn)
{
	p_syn->color = 0;
	if (-1 == is_valid_color(split))
		return (-1);
	if (*split[0] == 'F' && strlen(split[0]) == 1)
	{
		p_syn->f_color += (atoi(split[1]) << 16);
		p_syn->f_color += (atoi(split[2]) << 8);
		p_syn->f_color += (atoi(split[3]));
		p_syn->f_flag = 1;
	}
	else if (*split[0] == 'C' && strlen(split[0]) == 1)
	{
		p_syn->c_color += (atoi(split[1]) << 16);
		p_syn->c_color += (atoi(split[2]) << 8);
		p_syn->c_color += (atoi(split[3]));
		p_syn->c_flag = 1;
	}
	else
		return (-1);
	return (1);
}

int		par(t_syn *p_syn)
{
	int		fd;
	int		count;
	int		lenth;
	char	*buf;
	char	**split;

	count = 0;
	if (-1 == (fd = open(p_syn->cub_path, O_RDONLY)))
		message_exit();
	free(p_syn->cub_path);
	while (get_next_line(fd, &buf) && count < 8)
	{
		printf(">>\n");
		lenth = 0;
		if (*buf == '\0')
			continue;
		if (is_only_zero_blank_one(buf) == 1)
			message_exit();
		split = ft_split(buf, ' ');
		free(buf);
		while (split[lenth] != 0)
			lenth++;
		case_by_lenth(split, p_syn, lenth);
		while (--lenth >= 0)
			free(split[lenth]);
		free(split);
		count++;
	}
	free(buf);
	check_flag(p_syn);
	is_valid_map(fd, p_syn);
	return (1);
}
