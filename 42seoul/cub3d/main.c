/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 10:40:52 by huchoi            #+#    #+#             */
/*   Updated: 2021/04/02 16:40:39 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_texture_sprite(t_tri *p_tri, int idx)
{
	p_tri->tex[idx].ptr = mlx_xpm_file_to_image(p_tri->mlx_ptr, \
	p_tri->tex[idx].path, &(p_tri->tex[idx].width), &(p_tri->tex[idx].height));
	p_tri->tex[idx].data = (int *)mlx_get_data_addr(p_tri->tex[idx].ptr, \
	&p_tri->tex[idx].bpp, &p_tri->tex[idx].size_l, &p_tri->tex[idx].endian);
	free(p_tri->tex[idx].path);
}

void	check_path(t_syn *p_syn, char *path)
{
	int		fd;
	char	*p;

	if (-1 == (fd = is_valid_path(path)))
		message_exit();
	if (ft_strlen(path) >= 4)
	{
		p = ft_strchr(path, '.');
		if (ft_strlen(p) != 4)
			message_exit();
		else if (ft_strncmp(p, ".cub", 4) != 0)
			message_exit();
	}
	else
		message_exit();
	p_syn->cub_path = ft_strdup(path);
}

void	check_path_save(t_syn *p_syn, char *path, char *s)
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

int		close_function(void)
{
	exit(0);
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
	syn.tri.win_ptr = mlx_new_window(syn.tri.mlx_ptr, syn.r[0], \
	syn.r[1], "cub3D");
	syn.img.img_ptr = mlx_new_image(syn.tri.mlx_ptr, syn.r[0], syn.r[1]);
	syn.img.data_ptr = mlx_get_data_addr(syn.img.img_ptr, \
	&(syn.img.bpp), &(syn.img.lenth), &(syn.img.endian));
	init_tri(&syn);
	mlx_hook(syn.tri.win_ptr, 2, 0, &key_func, &syn);
	mlx_hook(syn.tri.win_ptr, 17, 0, &close_function, &syn);
	mlx_loop_hook(syn.tri.mlx_ptr, &main_loop, &syn);
	mlx_loop(syn.tri.mlx_ptr);
	return (0);
}
