/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 10:48:57 by huchoi            #+#    #+#             */
/*   Updated: 2021/03/10 14:09:06 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_the_block(t_syn *p_syn, int *p_idx, int i)
{
	int y;

	y = p_syn->drawstart;
	while (y < p_syn->drawend)
	{
		p_syn->texy = (int)p_syn->texpos & (p_syn->tri.tex[*p_idx].height - 1);
		p_syn->texpos += p_syn->step;
		p_syn->color = p_syn->tri.tex[*p_idx].data[p_syn->\
		tri.tex[*p_idx].height * p_syn->texy + p_syn->texx];
		my_mlx_pixel_put(&(p_syn->img), i, y, p_syn->color);
		y++;
	}
}

void	make_block(t_syn *p_syn, int *p_idx, int i)
{
	dda_init(&(p_syn->tri));
	dda_init_second(&(p_syn->tri));
	dda_loop(&(p_syn->tri));
	change_uclied_vertical(&(p_syn->tri));
	p_syn->lineheight = (double)p_syn->r[1] / (p_syn->tri.dda.walldist);
	p_syn->drawstart = -p_syn->lineheight / 2 + p_syn->r[1] / 2;
	if (p_syn->drawstart < 0)
		p_syn->drawstart = 0;
	p_syn->drawend = p_syn->lineheight / 2 + p_syn->r[1] / 2;
	if (p_syn->drawend >= p_syn->r[1])
		p_syn->drawend = p_syn->r[1] - 1;
	if (p_syn->tri.dda.side == 0)
		p_syn->wallx = p_syn->tri.pos[1] + \
		p_syn->tri.dda.walldist * p_syn->tri.dda.raydir_y;
	else
		p_syn->wallx = p_syn->tri.pos[0] + \
		p_syn->tri.dda.walldist * p_syn->tri.dda.raydir_x;
	p_syn->wallx -= floor((p_syn->wallx));
	news(p_syn, p_idx);
	p_syn->texpos = (p_syn->drawstart - p_syn->r[1] / 2 + \
	p_syn->lineheight / 2) * p_syn->step;
	draw_the_block(p_syn, p_idx, i);
}

void	news(t_syn *p_syn, int *p_idx)
{
	if ((p_syn->tri.dda.raydir_x >= 0) && p_syn->tri.dda.side == 0)
	{
		*p_idx = 1;
		before_make_texture(p_syn, p_idx);
	}
	else if (p_syn->tri.dda.raydir_x <= 0 && p_syn->tri.dda.side == 0)
	{
		*p_idx = 2;
		before_make_texture(p_syn, p_idx);
	}
	else if (p_syn->tri.dda.raydir_y >= 0 && p_syn->tri.dda.side == 1)
	{
		*p_idx = 0;
		before_make_texture(p_syn, p_idx);
	}
	else if (p_syn->tri.dda.raydir_y <= 0 && p_syn->tri.dda.side == 1)
	{
		*p_idx = 3;
		before_make_texture(p_syn, p_idx);
	}
	else
		return ;
}

void	before_make_texture(t_syn *p_syn, int *p_idx)
{
	p_syn->texx = (int)(p_syn->wallx * (double)p_syn->tri.tex[3].width);
	if (p_syn->tri.dda.side == 0 && p_syn->tri.dda.raydir_x > 0)
		p_syn->texx = p_syn->tri.tex[3].width - p_syn->texx - 1;
	if (p_syn->tri.dda.side == 1 && p_syn->tri.dda.raydir_y < 0)
		p_syn->texx = p_syn->tri.tex[3].width - p_syn->texx - 1;
	p_syn->step = 1.0 * p_syn->tri.tex[3].height / p_syn->lineheight;
}
