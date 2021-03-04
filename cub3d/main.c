#include "cub3d.h"

void	init_tri(t_syn *p_syn)
{
	t_tri	*p_tri;

	p_tri = &p_syn->tri;
	p_syn->ZBuffer = (double*)malloc(sizeof(double) * p_syn->R[0]);
	load_texture_sprite(p_tri, 0);
	load_texture_sprite(p_tri, 1);
	load_texture_sprite(p_tri, 2);
	load_texture_sprite(p_tri, 3);
	load_texture_sprite(p_tri, 4);
}

void	load_texture_sprite(t_tri *p_tri, int idx)
{
	p_tri->tex[idx].ptr = mlx_xpm_file_to_image(p_tri->mlx_ptr, \
	p_tri->tex[idx].path, &(p_tri->tex[idx].width), &(p_tri->tex[idx].height));
	p_tri->tex[idx].data = (int *)mlx_get_data_addr(p_tri->tex[idx].ptr, \
	&p_tri->tex[idx].bpp, &p_tri->tex[idx].size_l, &p_tri->tex[idx].endian);
	free(p_tri->tex[idx].path);
}

void	dda_init(t_tri *p_tri)
{
	t_dda *p_dd;

	p_dd = &(p_tri->dda);
	p_dd->map_x = (int)p_tri->pos[0];
	p_dd->map_y = (int)p_tri->pos[1];
	p_dd->deltadist_x = fabs(1 / p_dd->raydir_x);
	p_dd->deltadist_y = fabs(1 / p_dd->raydir_y);
	if (p_dd->raydir_x > 0)
		p_dd->sidedist_x = (p_dd->map_x + 1 - \
		p_tri->pos[0]) * p_dd->deltadist_x;
	else
		p_dd->sidedist_x = (p_tri->pos[0] - p_dd->map_x) * p_dd->deltadist_x;
	if (p_dd->raydir_y > 0)
		p_dd->sidedist_y = (p_dd->map_y + 1 - \
		p_tri->pos[1]) * p_dd->deltadist_y;
	else
		p_dd->sidedist_y = (p_tri->pos[1] - p_dd->map_y) * p_dd->deltadist_y;
}

void	dda_init_second(t_tri *p_tri)
{
	t_dda *p_dd;

	p_dd = &(p_tri->dda);
	if (p_tri->dda.raydir_x > 0)
		p_dd->step_x = 1;
	else
		p_dd->step_x = -1;
	if (p_tri->dda.raydir_y > 0)
		p_dd->step_y = 1;
	else
		p_dd->step_y = -1;
}

void check_path(t_syn *p_syn, char *path)
{
	int fd;
	if (-1 == (fd = is_valid_path(path)))
		message_exit();
	p_syn->cub_path = ft_strdup(path);
}

void check_path_save(t_syn *p_syn, char *path, char *s)
{
	int fd;

	if (-1 == (fd = is_valid_path(path)))
		message_exit();
	p_syn->cub_path = ft_strdup(path);
	if (ft_strncmp("--save", s, 6) == 0 && ft_strlen(s) == 6)
		p_syn->bmp_flag = 1;
	else 
		message_exit();
}

int		main(int argc, char *argv[])
{
	t_syn	syn;

	if (argc == 2)
		check_path(&syn, argv[1]);
	else if (argc == 3)
		check_path_save(&syn, argv[1], argv[2]);
	else
		message_exit();
	par(&syn);
	syn.tri.mlx_ptr = mlx_init();
	syn.tri.win_ptr = mlx_new_window(syn.tri.mlx_ptr, syn.R[0], \
	syn.R[1], "cub3D");
	syn.img.img_ptr = mlx_new_image(syn.tri.mlx_ptr, syn.R[0], syn.R[1]);
	syn.img.data_ptr = mlx_get_data_addr(syn.img.img_ptr, \
	&(syn.img.bpp), &(syn.img.lenth), &(syn.img.endian));
	init_tri(&syn);
	mlx_hook(syn.tri.win_ptr, 2, 0, &key_func, &syn);
	mlx_loop_hook(syn.tri.mlx_ptr, &main_loop, &syn);
	mlx_loop(syn.tri.mlx_ptr);
	return (0);
}
