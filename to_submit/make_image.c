/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 10:47:58 by huchoi            #+#    #+#             */
/*   Updated: 2021/03/10 11:38:57 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	make_under(t_syn *p_syn)
{
	int i;
	int j;

	i = p_syn->r[1] / 2;
	while (i < p_syn->r[1])
	{
		j = 0;
		while (j < p_syn->r[0])
			my_mlx_pixel_put(&(p_syn->img), j++, i, p_syn->f_color);
		i++;
	}
}

void	make_over(t_syn *p_syn)
{
	int	i;
	int	j;

	i = 0;
	while (i < p_syn->r[1] / 2)
	{
		j = 0;
		while (j < p_syn->r[0])
			my_mlx_pixel_put(&(p_syn->img), j++, i, p_syn->c_color);
		i++;
	}
}

void	my_mlx_pixel_put(t_img *p_img, int x, int y, int color)
{
	char	*dst;

	dst = p_img->data_ptr + (y * p_img->lenth + x * (p_img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	ft_close(t_syn *p_syn)
{
	mlx_destroy_window(p_syn->tri.mlx_ptr, p_syn->tri.win_ptr);
	exit(0);
}

int		key_func(int keycode, t_syn *p_syn)
{
	double	temp;
	double	speed;

	speed = 0.3;
	ctrl_pos(keycode, p_syn);
	ctrl_dir(keycode, p_syn);
	if (keycode == KEY_ESC || keycode == KEY_1)
		ft_close(p_syn);
	return (0);
}
