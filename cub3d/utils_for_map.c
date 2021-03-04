#include "cub3d.h"

void	get_dir(t_syn *p_syn, int idx, char *add_line)
{
	p_syn->tri.pos[1] = idx + 0.5;
	p_syn->tri.dir[0] = 0;
	p_syn->tri.dir[1] = 0;
	p_syn->tri.plane[0] = 0;
	p_syn->tri.plane[1] = 0;
	if (add_line[idx] == 'N')
	{
		p_syn->tri.dir[0] = +1;
		p_syn->tri.plane[1] = 0.66;
	}
	if (add_line[idx] == 'E')
	{
		p_syn->tri.dir[1] = 1;
		p_syn->tri.plane[0] = 0.66;
	}
	if (add_line[idx] == 'W')
	{
		p_syn->tri.dir[1] = -1;
		p_syn->tri.plane[0] = 0.66;
	}
	if (add_line[idx] == 'S')
	{
		p_syn->tri.dir[0] = -1;
		p_syn->tri.plane[1] = 0.66;
	}
}

int		renewer_sprites(t_syn *p_syn, int size, int idx)
{
	int		x;
	double	**new_sprites;

	x = 0;
	p_syn->num_of_sprite++;
	while (p_syn->sprites[x] != NULL)
		x++;
	if (NULL == (new_sprites = (double **)ft_calloc(x + 2, sizeof(double *))))
		message_exit();
	new_sprites[x + 1] = NULL;
	if (0 == (new_sprites[x] = malloc(sizeof(int) * 2)))
		message_exit();
	new_sprites[x][0] = (double)size + 0.5;
	new_sprites[x][1] = (double)idx + 0.5;
	while (--x >= 0)
		new_sprites[x] = p_syn->sprites[x];
	free(p_syn->sprites);
	p_syn->sprites = new_sprites;
	return (1);
}

void	make_new_map(int **new_map, int **map, int *new_line, int size)
{
	new_map[size + 1] = NULL;
	new_map[size] = new_line;
	while (--size >= 0)
		new_map[size] = map[size];
	free(map);
}

void	manage_news_sprite(t_syn *p_syn, char *add_line, int size, int idx)
{
	if (ft_strchr("NEWS", add_line[idx]) != 0)
	{
		get_dir(p_syn, idx, add_line);
		p_syn->tri.pos[0] = size + 0.5;
		add_line[idx] = '0';
		if (p_syn->dir_alpha_is_exist == 1)
			message_exit();
		p_syn->dir_alpha_is_exist = 1;
	}
	else if (add_line[idx] == '2')
		renewer_sprites(p_syn, size, idx);
}
