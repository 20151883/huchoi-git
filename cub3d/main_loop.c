#include "cub3d.h"

int		main_loop(t_syn *p_syn)
{
	int		idx;
	int		i;
	double	weight;

	i = 0;
	make_over(p_syn);
	make_under(p_syn);
	while (i < p_syn->R[0])
	{
		weight = 2 * i / (double)p_syn->R[0] - 1;
		p_syn->tri.dda.raydir_x = p_syn->tri.dir[0] + \
		p_syn->tri.plane[0] * weight;
		p_syn->tri.dda.raydir_y = p_syn->tri.dir[1] + \
		p_syn->tri.plane[1] * weight;
		make_block(p_syn, &idx, i);
		p_syn->ZBuffer[i] = p_syn->tri.dda.walldist;
		i++;
	}
	make_sprite(p_syn);
	mlx_put_image_to_window(p_syn->tri.mlx_ptr, \
	p_syn->tri.win_ptr, p_syn->img.img_ptr, 0, 0);
	if (p_syn->bmp_flag == 1)
	{
		ft_bitmap(p_syn);
		message_exit();
	}
	return (0);
}