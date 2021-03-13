/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_sprites_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 10:48:07 by huchoi            #+#    #+#             */
/*   Updated: 2021/03/08 11:37:21 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sort_sprites(t_syn *p_syn)
{
	ft_mergesort(p_syn, p_syn->sprites, 0, p_syn->num_of_sprite - 1);
}

double	compute_dis(t_syn *p_syn, double *sprite)
{
	double	ret;
	double	x_pos;
	double	y_pos;

	x_pos = sprite[0];
	y_pos = sprite[1];
	ret = (x_pos - p_syn->tri.pos[0]) * (x_pos - p_syn->tri.pos[0]);
	ret += (y_pos - p_syn->tri.pos[1]) * (y_pos - p_syn->tri.pos[1]);
	ret = sqrt(ret);
	return (ret);
}

void	ft_merge(t_syn *p_syn, double **arr, int start, int end)
{
	double	*temp[end - start + 1];
	int		idx;
	int		left;
	int		right;
	int		mid;

	mid = (start + end) / 2;
	idx = 0;
	left = start;
	right = mid + 1;
	while (left <= mid && right <= end)
	{
		if (compute_dis(p_syn, arr[left]) > compute_dis(p_syn, arr[right]))
			temp[idx++] = arr[left++];
		else
			temp[idx++] = arr[right++];
	}
	while (left <= mid)
		temp[idx++] = arr[left++];
	while (right <= end)
		temp[idx++] = arr[right++];
	idx = start - 1;
	while (++idx <= end)
		arr[idx] = temp[idx - start];
}

void	ft_mergesort(t_syn *p_syn, double **arr, int start, int end)
{
	int	mid;

	if (start == end)
		return ;
	mid = (start + end) / 2;
	ft_mergesort(p_syn, arr, start, mid);
	ft_mergesort(p_syn, arr, mid + 1, end);
	ft_merge(p_syn, arr, start, end);
}

void	init_for_sprite(t_syn *p_syn, int i)
{
	p_syn->spritex = p_syn->sprites[i][0] - p_syn->tri.pos[0];
	p_syn->spritey = p_syn->sprites[i][1] - p_syn->tri.pos[1];
	p_syn->invdet = 1.0 / (p_syn->tri.plane[0] * p_syn->tri.dir[1] - \
			p_syn->tri.dir[0] * p_syn->tri.plane[1]);
	p_syn->transformx = p_syn->invdet * (p_syn->tri.dir[1] * \
			p_syn->spritex - p_syn->tri.dir[0] * p_syn->spritey);
	p_syn->transformy = p_syn->invdet * (-p_syn->tri.plane[1] * \
	p_syn->spritex + p_syn->tri.plane[0] * p_syn->spritey);
	p_syn->spritescreenx = (int)((p_syn->r[0] / 2) * \
			(1 + p_syn->transformx / p_syn->transformy));
	p_syn->spriteheight = abs((int)(p_syn->r[1] / (p_syn->transformy)));
	p_syn->drawstarty = -p_syn->spriteheight / 2 + p_syn->r[1] / 2;
	if (p_syn->drawstarty < 0)
		p_syn->drawstarty = 0;
	p_syn->drawendy = p_syn->spriteheight / 2 + p_syn->r[1] / 2;
	if (p_syn->drawendy >= p_syn->r[1])
		p_syn->drawendy = p_syn->r[1] - 1;
	p_syn->spritewidth = abs((int)(p_syn->r[1] / (p_syn->transformy)));
	p_syn->drawstartx = -p_syn->spritewidth / 2 + p_syn->spritescreenx;
	if (p_syn->drawstartx < 0)
		p_syn->drawstartx = 0;
	p_syn->drawendx = p_syn->spritewidth / 2 + p_syn->spritescreenx;
	if (p_syn->drawendx >= p_syn->r[0])
		p_syn->drawendx = p_syn->r[0] - 1;
}
