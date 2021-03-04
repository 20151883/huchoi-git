/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 01:06:15 by huchoi            #+#    #+#             */
/*   Updated: 2021/03/04 09:55:30 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_sprites(t_syn *p_syn)
{
	p_syn->y = p_syn->drawStartY;
	while (p_syn->y < p_syn->drawEndY)
	{
		p_syn->d = (p_syn->y) * 256 - H * 128 + p_syn->spriteHeight * 128;
		p_syn->texY = ((p_syn->d * p_syn->tri.tex[4].height) / \
		p_syn->spriteHeight) / 256;
		p_syn->color = p_syn->tri.tex[4].data[p_syn->tri.tex[4].width \
		* p_syn->texY + p_syn->texX];
		if ((p_syn->color & 0x00FFFFFF) != 0)
			my_mlx_pixel_put(&(p_syn->img), \
			p_syn->stripe, p_syn->y, p_syn->color);
		p_syn->y++;
	}
}

void	procedure_for_sprite(t_syn *p_syn)
{
	p_syn->stripe = p_syn->drawStartX;
	while (p_syn->stripe < p_syn->drawEndX)
	{
		p_syn->texX = (int)(256 * (p_syn->stripe - (-p_syn->spriteWidth / 2 + \
		p_syn->spriteScreenX)) * p_syn->tri.tex[4].width / \
		p_syn->spriteWidth) / 256;
		if (p_syn->transformY > 0 && p_syn->stripe > 0 && p_syn->stripe < \
		p_syn->R[0] && p_syn->transformY < p_syn->ZBuffer[p_syn->stripe])
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
