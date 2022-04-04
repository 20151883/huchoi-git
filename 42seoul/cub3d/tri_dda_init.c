/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_dda_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 10:42:40 by huchoi            #+#    #+#             */
/*   Updated: 2021/03/10 13:47:26 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_tri(t_syn *p_syn)
{
	t_tri	*p_tri;

	p_tri = &p_syn->tri;
	p_syn->zbuffer = (double*)malloc(sizeof(double) * p_syn->r[0]);
	load_texture_sprite(p_tri, 0);
	load_texture_sprite(p_tri, 1);
	load_texture_sprite(p_tri, 2);
	load_texture_sprite(p_tri, 3);
	load_texture_sprite(p_tri, 4);
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
