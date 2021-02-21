#include <stdio.h>

extern width = 1080;
extern divide = width;

void dda_loop(t_tri *p_tri)
{
    int hit = 0;
    t_dda *p_dd = &(p_tri->dda);

    while (hit == 0)
    {
        if (p_dd->sidedist_x <= p_dd->sidedist_y)
        {
            p_dd->sidedist_x += p_dd->deltadist_x;
            p_dd->map_x += p_dd->step_x;
            p_dd->side = 0;
        }
        else
        {
            p_dd->sidedist_y += p_dd->deltadist_y;
            p_dd->map_y += p_dd->step_y;
            p_dd->side = 1;
        }
        if (worldMap[p_dd->map_x][p_dd->map_y] > 0)
            hit = 1;
    }
}

void change_uclied_vertical(t_tri *p_tri)
{
    t_dda *p_dd;

    p_dd = &(p_tri->dda);
    //공식을 이용하시오...!!!
     if (p_tri->dda.side == 0) 
        p_dd.walldist = (p_dd->map_x - p_tri->pos_x + (1 - p_dd->step_x) / 2) / (p_dd->raydir_x);
    else
        p_dd.walldist = (p_dd->map_y - p_tri->pos_y + (1 - p_dd->step_y) / 2) / (p_dd->raydir_y);
}