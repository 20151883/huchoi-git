/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 01:06:15 by huchoi            #+#    #+#             */
/*   Updated: 2021/03/10 10:59:12 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_sprites(t_syn *p_syn)
{
	p_syn->y = p_syn->drawstarty;
	while (p_syn->y < p_syn->drawendy)
	{
		p_syn->d = (p_syn->y) * 256 - p_syn->r[1] * 128 + \
		p_syn->spriteheight * 128;
		p_syn->texy = ((p_syn->d * p_syn->tri.tex[4].height) / \
		p_syn->spriteheight) / 256;
		p_syn->color = p_syn->tri.tex[4].data[p_syn->tri.tex[4].width \
		* p_syn->texy + p_syn->texx];
		if ((p_syn->color & 0x00FFFFFF) != 0)
			my_mlx_pixel_put(&(p_syn->img), \
			p_syn->stripe, p_syn->y, p_syn->color);
		p_syn->y++;
	}
}

void	procedure_for_sprite(t_syn *p_syn)
{
	p_syn->stripe = p_syn->drawstartx;
	while (p_syn->stripe < p_syn->drawendx)
	{
		p_syn->texx = (int)(256 * (p_syn->stripe - (-p_syn->spritewidth / 2 + \
		p_syn->spritescreenx)) * p_syn->tri.tex[4].width / \
		p_syn->spritewidth) / 256;
		if (p_syn->transformy > 0 && p_syn->stripe > 0 && p_syn->stripe < \
		p_syn->r[0] && p_syn->transformy < p_syn->zbuffer[p_syn->stripe])
			get_sprites(p_syn);
		p_syn->stripe++;
	}
}

void	make_sprite(t_syn *p_syn)
{
	int i;

	sort_sprites(p_syn);
	i = -1;
	while (++i < p_syn->num_of_sprite)
	{
		init_for_sprite(p_syn, i);
		procedure_for_sprite(p_syn);
	}
}
