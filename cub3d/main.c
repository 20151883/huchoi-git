#include "cub3d.h"

int worldMap[mapWidth][mapHeight] =
    {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
    {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
    {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };

void init_tri(t_tri *p_tri)
{
    p_tri->pos[0] = 2;
    p_tri->pos[1] = 3;
    p_tri->dir[0] = 1;
    p_tri->dir[1] = 0;
    abs_must_epual_one(p_tri);
    p_tri->theta = PIE / 180.0;
    p_tri->plane[0] = 0;
    p_tri->plane[1] = 0.66;
}

void dda_init(t_tri *p_tri)
{
    t_dda *p_dd = &(p_tri->dda);
    
    p_dd->map_x = (int)p_tri->pos[0];
    p_dd->map_y = (int)p_tri->pos[1];
    p_dd->deltadist_x = fabs(1.0 / p_tri->dda.raydir_x);
    p_dd->deltadist_y = fabs(1.0 / p_tri->dda.raydir_y);
    if (p_dd->raydir_x > 0)
        p_dd->sidedist_x = (p_dd->map_x + 1 - p_tri->pos_x) * p_dd->deltadist_x;
    else
        p_dd->sidedist_x = (p_tri->pos_x - p_dd->map_x) * p_dd->deltadist_x;
    if (p_dd->raydir_y > 0)
        p_dd->sidedist_y = (p_dd->map_y + 1 - p_tri->pos_y) * p_dd->deltadist_y;
    else
        p_dd->sidedist_y = (p_tri->pos_y - p_dd->map_y) * p_dd->deltadist_y;
}

void dda_init_second(t_tri *p_tri)
{
    t_dda *p_dd = &(p_tri->dda);

    if (p_tri->dda.raydir_x > 0)
        p_dd->step_x = 1;
    else
        p_dd->step_x = -1;
    if (p_tri->dda.raydir_y > 0)
        p_dd->step_y = 1;
    else
        p_dd->step_y = -1;
}

void main_loop(t_syn *p_syn)
{
    int i = 0;
    double weight;
    int lineHeight;
    int drawStart;
    int drawEnd;
    int color;
    int w = screenWidth;

    while (i < w)
    {
        weight = 2 * i / double(w) - 1;
        syn->dda.raydir_x = syn->tri.dir[0] + syn->tri.plane[0] * weight;
        syn->dda.raydir_y = syn->tri.dir[1] + syn->tri.plane[1] * weight;
        dda_init(&(p_syn->tri));
        dda_init_second(&(p_syn->tri));
        dda_loop(&(p_syn->tri));
        change_uclied_vertical(&(p_syn->tri));//strcut->walldist에 값이 저장된다.
        lineHeight = (double)H / (syn->tri.dda.walldist);

        drawStart = -lineHeight / 2 + screenHeight / 2;//int연산
        if(drawStart < 0)
            drawStart = 0;
        drawEnd = lineHeight / 2 + screenHeight / 2;//int 연산
        if(drawEnd >= h)
            drawEnd = h - 1;
        switch(worldMap[mapX][mapY])
        {
            case 1:  color = 0xFF0000;  break; //red
            case 2:  color = 0xFF00;  break; //green
            case 3:  color = 0xFF;   break; //blue
            case 4:  color = 0xFFFFFF;  break; //white
            default: color = 0xFFFF00; break; //yellow
        }
        //give x and y sides different brightness
        if (side == 1) 
            color = color / 2;
        make_line(p_syn, w/2.0 + (w*weight)/2.0, drawStart, drawEnd, color);//w를 아주크게 해서 라인과 라인사이의 간격이 아주 촘촘하면 구분구적법의 느낌이 날것.//image에 그리는거..
        i++;
    }
    mlx_put_image_to_window(p_syn->mlx_ptr, p_syn->wid_ptr, p_syn->img_ptr.img, 0, 0);//딱 한번만 호출하는...
}

void make_line(t_syn *p_syn, double x_pos, double start, double end, int color)
{
    int y;

    y = start;
    whie (y <= end)
    {
        my_mlx_pixel_put(&(p_syn->img), x_pos, y, color);
        y++;
    }
}

void    my_mlx_pixel_put(t_img *p_img, int x, int y, int color)
{
    char *dst;

    dst = p_img->data_ptr + (y * p_img->lenth + x * (p_img->bpp / 8));
    // 괄호 == offset
    *(unsigned int *)dst = color;
}

int main(int argc, char *argv[])
{
    t_syn syn;

    sym.mlx_ptr = mlx_init();
    syn.win_ptr = mlx_new_window(mlx_ptr, 1080, 1080, "hello");
    syn.img.img_ptr = mlx_new_image(img.img_ptr, 1080, 1080);
    syn.img.data_ptr = mlx_get_data_addr(syn.img.img, &(syn.img.bpp), &(syn.img.length), &(syn.img.endian));
    init_tri(&(syn.tri));

    //mlx_hook(syn.mlx_ptr, key, mask, &key_function, &syn);//change pos, dir, plane....
    //mlx_hook(syn.mlx_ptr, key, mask, &close_function, &syn);

    mlx_loop_hook(syn.mlx_ptr, main_loop, &syn);
    mlx_loop(syn.mlx_ptr);
    return (0);
}