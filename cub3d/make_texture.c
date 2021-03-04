#include "cub3d.h"

void	draw_the_block(t_syn *p_syn, int *p_idx, int i)
{
	int y;

	y = p_syn->drawStart;
	while (y < p_syn->drawEnd)
	{
		p_syn->texY = (int)p_syn->texPos & (p_syn->tri.tex[*p_idx].height - 1);
		p_syn->texPos += p_syn->step;
		p_syn->color = p_syn->tri.tex[*p_idx].data[p_syn->\
		tri.tex[*p_idx].height * p_syn->texY + p_syn->texX];
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
	p_syn->lineHeight = (double)H / (p_syn->tri.dda.walldist);
	p_syn->drawStart = -p_syn->lineHeight / 2 + p_syn->R[1] / 2;
	if (p_syn->drawStart < 0)
		p_syn->drawStart = 0;
	p_syn->drawEnd = p_syn->lineHeight / 2 + p_syn->R[1] / 2;
	if (p_syn->drawEnd >= H)
		p_syn->drawEnd = H - 1;
	if (p_syn->tri.dda.side == 0)
		p_syn->wallX = p_syn->tri.pos[1] + \
		p_syn->tri.dda.walldist * p_syn->tri.dda.raydir_y;
	else
		p_syn->wallX = p_syn->tri.pos[0] + \
		p_syn->tri.dda.walldist * p_syn->tri.dda.raydir_x;
	p_syn->wallX -= floor((p_syn->wallX));
	news(p_syn, p_idx);
	p_syn->texPos = (p_syn->drawStart - H / 2 + \
	p_syn->lineHeight / 2) * p_syn->step;
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
	p_syn->texX = (int)(p_syn->wallX * (double)p_syn->tri.tex[3].width);
	if (p_syn->tri.dda.side == 0 && p_syn->tri.dda.raydir_x > 0)
		p_syn->texX = p_syn->tri.tex[3].width - p_syn->texX - 1;
	if (p_syn->tri.dda.side == 1 && p_syn->tri.dda.raydir_y < 0)
		p_syn->texX = p_syn->tri.tex[3].width - p_syn->texX - 1;
	p_syn->step = 1.0 * p_syn->tri.tex[3].height / p_syn->lineHeight;
}
