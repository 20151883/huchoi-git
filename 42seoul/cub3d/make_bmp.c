/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 10:45:54 by huchoi            #+#    #+#             */
/*   Updated: 2021/04/02 17:41:32 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		set_header(unsigned char *header, int param)
{
	header[0] = (unsigned char)(param);
	header[1] = (unsigned char)(param >> 8);
	header[2] = (unsigned char)(param >> 16);
	header[3] = (unsigned char)(param >> 24);
}

void		imgbmp(t_syn *m, t_bmp *bmp)
{
	int i;
	int j;
	int x;
	int y;
	int *d;

	j = -1;
	while (++j < m->r[1])
	{
		i = -1;
		while (++i < m->r[0])
		{
			x = i;
			y = m->r[1] - 1 - j;
			d = (int*)(m->img.data_ptr + (y * m->img.lenth + \
			x * (m->img.bpp / 8)));
			set_header(bmp->color, *d);
			write(bmp->fd, bmp->color, 4);
		}
	}
}

void		ft_header(t_syn *m, t_bmp *bmp)
{
	int i;

	i = 0;
	while (i < 14)
		bmp->header[i++] = 0;
	bmp->header[0] = 'B';
	bmp->header[1] = 'M';
	set_header(&bmp->header[2], bmp->size);
	bmp->header[10] = 54;
	i = 0;
	while (i < 40)
		bmp->info[i++] = 0;
	bmp->info[0] = 40;
	set_header(&bmp->info[4], m->r[0]);
	set_header(&bmp->info[8], m->r[1]);
	bmp->info[12] = 1;
	bmp->info[14] = 32;
	write(bmp->fd, bmp->header, 14);
	write(bmp->fd, bmp->info, 40);
}

void		ft_bitmap(t_syn *m)
{
	t_bmp	bmp;
	int		imgsize;

	imgsize = 4 * m->r[0] * m->r[1];
	bmp.size = 54 + imgsize;
	bmp.fd = open("cub3D.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (bmp.fd == -1)
		message_exit();
	ft_header(m, &bmp);
	imgbmp(m, &bmp);
	close(bmp.fd);
	exit(0);
}
