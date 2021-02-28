#include "cub3d.h"

int		get_next_line(int fd, char **line);
void	my_clear(char **lst)
{
	int		i;
	char	*cur;
	char	*del;

	i = 0;
	del = lst[i];
	if (del == 0)
	{
		free(del);
		return ;
	}
	else
	{
		cur = lst[++i];
		free(del);
		while (cur != 0)
		{
			del = cur;
			cur = lst[++i];
			free(del);
		}
	}
}

int		ft_atoi(const char *str)
{
	int sign;
	int res;

	sign = 1;
	res = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v' ||
			*str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= (-1);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (res * sign);
}

int		give_start(char const *s1, char const c, int end)
{
	int ret;
	int i;

	ret = end + 1;
	if (s1[ret] == '\0')
		return (-1);
	i = 0;
	while (s1[ret + i] != '\0')
	{
		if (s1[ret + i] != c)
			return (ret + i);
		else
			i++;
	}
	return (-1);
}

int		give_end(char const *s1, char const c, int start)
{
	int ret;
	int i;

	if (start == -1)
		return (-1);
	ret = start;
	i = 0;
	while (s1[ret + i] != '\0')
	{
		if (c == (s1[ret + i]))
			return (ret + i - 1);
		else
			i++;
	}
	return (ret + i - 1);
}

char	**new_ret(char **ret, char const *s1, int start, int end)
{
	int		i;
	int		len;
	char	**return_value;
	char	*str;

	len = 0;
	while (ret[len] != 0)
		len++;
	return_value = (char **)malloc(sizeof(char *) * (len + 2));
	if (return_value == 0)
	{
		my_clear(ret);
		return (0);
	}
	i = -1;
	while (ret[++i] != '\0')
		return_value[i] = ret[i];
	free(ret);
	str = (char *)malloc(sizeof(char) * (end - start + 2));
	strlcpy(str, &s1[start], end - start + 2);
	return_value[i++] = str;
	return_value[i] = 0;
	return (return_value);
}

char	**ft_split(char const *s1, char const c)
{
	char	**ret;
	int		start;
	int		end;

	ret = (char **)malloc(sizeof(char *) * 1);
	if (ret == 0)
		return (0);
	*ret = 0;
	start = give_start(s1, c, -1);
	end = give_end(s1, c, start);
	while (start != -1)
	{
		ret = new_ret(ret, s1, start, end);
		if (ret == 0)
			return (0);
		start = give_start(s1, c, end);
		end = give_end(s1, c, start);
	}
	return (ret);
}

int		is_valid_path(char *path)
{
	int fd;
	int ret;

	ret = 1;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		message_exit;
	close(fd);
	return (ret);
}

void get_tex_path_by_idx(t_syn *p_syn, char **split, int idx)
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
	{
		get_tex_path_by_idx(p_syn, split, 0);
		/*p_syn->tri.tex[0].path = strdup(split[1]);
		p_syn->no_flag = 1;*/
	}
	else if (strcmp(split[0], "EA") == 0)
	{
		get_tex_path_by_idx(p_syn, split, 1);
		/*p_syn->tri.tex[1].path = strdup(split[1]);
		p_syn->ea_flag = 1;*/
	}
	else if (strcmp(split[0], "WE") == 0)
	{
		get_tex_path_by_idx(p_syn, split, 2);
		/*p_syn->tri.tex[2].path = strdup(split[1]);
		p_syn->we_flag = 1;*/
	}
	else if (strcmp(split[0], "SO") == 0)
	{
		get_tex_path_by_idx(p_syn, split, 3);
		/*p_syn->tri.tex[3].path = strdup(split[1]);
		p_syn->so_flag = 1;*/
	}
	else if (strcmp(split[0], "S") == 0)
	{
		get_tex_path_by_idx(p_syn, split, 4);
		/*p_syn->tri.tex[4].path = strdup(split[1]);
		p_syn->s_flag = 1;*/
	}
	else
		return (-1);
	return (1);
}

int		check_r(char **split, t_syn *p_syn)
{
	if (*split[0] == 'R' && strlen(split[0]) == 1)
	{
		if ((0 > atoi(split[1]) || atoi(split[1]) > 7680))
			return (-1);
		p_syn->R[0] = atoi(split[1]);
		if ((0 > atoi(split[2]) || atoi(split[2]) > 4320))
			return (-1);
		p_syn->R[1] = atoi(split[2]);
		p_syn->r_flag = 1;
	}
	else
		return (-1);
	return (1);
}

int		is_valid_color(char **split)
{
	if ((0 > atoi(split[1]) || atoi(split[1]) > 255))
		return (-1);
	if ((0 > atoi(split[2]) || atoi(split[2]) > 255))
		return (-1);
	if ((0 > atoi(split[3]) || atoi(split[3]) > 255))
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

int		is_only_zero_blank_one(char *arr)
{
	int idx;

	idx = 0;
	while (arr[idx])
	{
		if (strchr("012 NEWS", arr[idx++]) == 0)
			return (-1);
	}
	return (1);
}

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

int		par(t_syn *p_syn)
{
	int		fd;
	int		count;
	int		lenth;
	char	*buf;
	char	**split;

	count = 0;
	if (-1 == (fd = open("test.txt", O_RDONLY)))
		message_exit();
	while (get_next_line(fd, &buf) && count < 8)
	{
		lenth = 0;
		if (strcmp(buf, "") == 0)
			continue;
		if (is_only_zero_blank_one(buf) == 1)
			message_exit();
		split = ft_split(buf, ' ');
		while (split[lenth] != 0)
			lenth++;
		case_by_lenth(split, p_syn, lenth);
		count++;
	}
	check_flag(p_syn);
	is_valid_map(fd, p_syn);
	return (1);
}
