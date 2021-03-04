#include "cub3d.h"
#include "get_next_line.h"

static	void	init_the_var(int *p_idx, t_syn *p_syn)
{
	*p_idx = 0;
	if (NULL == (p_syn->sprites = (double **)\
	ft_calloc(1, sizeof(double *))))
		message_exit();
	p_syn->num_of_sprite = 0;
	p_syn->dir_alpha_is_exist = 0;
	if (NULL == (p_syn->tri.test_map = \
	(int **)ft_calloc(1, sizeof(int *))))
		message_exit();
}

int				is_valid_map(int fd, t_syn *p_syn)
{
	int		ret;
	int		idx;
	int		*temp;
	char	*cur_buf;
	char	*before_buf;

	init_the_var(&idx, p_syn);
	get_next_line(fd, &cur_buf);
	get_first(fd, cur_buf);
	if (-1 == (check_first(cur_buf, &(p_syn->dir_alpha_is_exist))))
		message_exit();
	if (NULL == (p_syn->tri.test_map = \
	renewer_map(p_syn, p_syn->tri.test_map, cur_buf)))
		message_exit();
	before_buf = cur_buf;
	while (get_next_line(fd, &(cur_buf)))
		ret = valid_check(p_syn, &cur_buf, &before_buf, ret);
	if (p_syn->dir_alpha_is_exist == 0)
		message_exit();
	ret = get_last(p_syn, cur_buf, before_buf, ret);
	return (ret);
}
