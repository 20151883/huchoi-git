#include "cub3d.h"

void	change_uclied_vertical(t_tri *p_tri)
{
	t_dda *p_dd;

	p_dd = &(p_tri->dda);
	if (p_tri->dda.side == 0) 
		p_dd->walldist = (p_dd->map_x - p_tri->pos[0] + (1 - p_dd->step_x) / 2) / (p_dd->raydir_x);
	else
		p_dd->walldist = (p_dd->map_y - p_tri->pos[1] + (1 - p_dd->step_y) / 2) / (p_dd->raydir_y);
}

void	dda_loop(t_tri *p_tri)//&(p_tri->dda) = p_dd
{
	t_dda	*p_dd;
	int		hit;

	hit = 0;
	p_dd = &(p_tri->dda);
	while (hit == 0)
	{
		if (p_dd->sidedist_x <= p_dd->sidedist_y)
		{
			p_dd->sidedist_x += p_dd->deltadist_x;
			p_dd->side = 0;
			p_dd->map_x += p_dd->step_x; 
		}
		else
		{
			p_dd->sidedist_y += p_dd->deltadist_y;
			p_dd->side = 1;
			p_dd->map_y += p_dd->step_y; 
		}
		if (p_tri->test_map[p_dd->map_x][p_dd->map_y] == 1)
			hit = 1;
    }
}