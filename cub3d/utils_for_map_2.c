#include "cub3d.h"
#include "get_next_line.h"

int		**renewer_map(t_syn *p_syn, int **map, char *add_line)
{
	int	**new_map;
	int *temp;
	int size;
	int idx;

	size = 0;
	idx = -1;
	while (map[size] != NULL)
		size++;
	if (NULL == (new_map = (int **)calloc(1, sizeof(int *) * (size + 2))))
		message_exit();
	if (NULL == (temp = malloc(sizeof(int) * ft_strlen(add_line))))
		message_exit();
	while (add_line[++idx])
	{
		manage_news_sprite(p_syn, add_line, size, idx);
		temp[idx] = add_line[idx] - '0';
	}
	make_new_map(new_map, map, temp, size);
	return (new_map);
}

void	get_first(int fd, char *cur_buf)
{
	while (strcmp(cur_buf, "") == 0)
		get_next_line(fd, &cur_buf);
	while (ft_strchr(cur_buf, ' '))
		*(ft_strchr(cur_buf, ' ')) = '1';
}

void check_upper_zero_is_null(char *cur, char *before)
{
	int idx;
	
	idx = -1;
	while (cur[++idx])
	{
		if (cur[idx] == '0' && ft_strlen(before) - 1 < idx)
			message_exit();
	}
}

int		valid_check(t_syn *p_syn, char **p_cur_buf, \
char **p_before_buf, int flag)
{
	while (ft_strchr(*p_cur_buf, ' '))
		*(ft_strchr(*p_cur_buf, ' ')) = '1';
	printf("%s\n", *p_cur_buf);
	if (is_only_zero_blank_one(*p_cur_buf) != 1)
		message_exit();
	if (((*p_cur_buf)[0] != '1') || \
	((*p_cur_buf)[ft_strlen(*p_cur_buf) - 1] != '1'))
		message_exit();
	//check_upper_zero_is_null(*p_cur_buf, *p_before_buf);
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
