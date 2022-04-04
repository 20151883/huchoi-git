/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TRI_dda.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 10:59:27 by huchoi            #+#    #+#             */
/*   Updated: 2021/03/08 10:59:51 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	renewer_tri(t_tri *test, int *new_pos, int *new_dir)
{
	if (new_pos != NULL)
	{
		test->pos[0] = new_pos[0];
		test->pos[1] = new_pos[1];
	}
	if (new_dir != NULL)
	{
		test->dir[0] = new_dir[0];
		test->dir[1] = new_dir[1];
	}
}

void	get_tri(t_tri *p_tria)
{
	int pos_x;
	int pos_y;
	int dir_x;
	int dir_y;

	pos_x = p_tria->pos[0];
	pos_y = p_tria->pos[1];
	dir_x = p_tria->dir[0];
	dir_y = p_tria->dir[1];
}

int		get_x_rotate(double *vec, double theta)
{
	int y;
	int x;

	x = vec[0];
	y = vec[1];
	return (x * cos(theta) - y * sin(theta));
}

int		get_y_rotate(int *vec, double theta)
{
	int x;
	int y;

	x = vec[0];
	y = vec[1];
	return (x * sin(theta) + y * cos(theta));
}

void	abs_must_equal_one(t_tri *p_tri)
{
	double weight;

	weight = sqrt(pow(p_tri->dir[0], 2) + pow(p_tri->dir[1], 2));
	if (weight != 1)
	{
		p_tri->dir[0] /= weight;
		p_tri->dir[1] /= weight;
	}
}
