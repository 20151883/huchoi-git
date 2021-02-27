#include "cub3d.h"
void init_tri(t_syn *p_syn)
{
    //par(p_syn);
    t_tri *p_tri = &p_syn->tri;
    /*p_tri->pos[0] = 1;
    p_tri->pos[1] = 1;
    p_tri->dir[0] = -1;
    p_tri->dir[1] = 0;
    //abs_must_epual_one(p_tri);
    p_tri->plane[0] = 0;
    p_tri->plane[1] = 0;
    if (p_tri->dir[1] != 0)
        p_tri->plane[0] = 0.66;
    else
        p_tri->plane[1] = 0.66;*/
    p_syn->ZBuffer = (double*)malloc(sizeof (double) * p_syn->R[0]);
    //printf("IN INIT TRI \n pos[0] = %f pos[1] = %f", p_syn->tri.pos[0], p_syn->tri.pos[1]);
    //memcpy(p_tri->worldMap, arr, sizeof(int) * mapWidth * mapHeight);
    ///printf("%d %d %d", p_tri->worldMap[0][0])
    /*int fd = open("./pics/eagle11.xpm", O_RDONLY);
    printf("fd %d\n", fd);*/

    //printf("test : %s", p_syn->tri.tex[0].path);

    p_tri->tex[0].ptr = mlx_xpm_file_to_image(p_tri->mlx_ptr, p_syn->tri.tex[0].path, &(p_tri->tex[0].width), &(p_tri->tex[0].height));
	p_tri->tex[0].data = (int *)mlx_get_data_addr(p_tri->tex[0].ptr, &p_tri->tex[0].bpp, &p_tri->tex[0].size_l, &p_tri->tex[0].endian);
    
    p_tri->tex[1].ptr = mlx_xpm_file_to_image(p_tri->mlx_ptr, p_syn->tri.tex[1].path, &p_tri->tex[1].width, &p_tri->tex[1].height);
	p_tri->tex[1].data = (int *)mlx_get_data_addr(p_tri->tex[1].ptr, &p_tri->tex[1].bpp, &p_tri->tex[1].size_l, &p_tri->tex[1].endian);
    
    p_tri->tex[2].ptr = mlx_xpm_file_to_image(p_tri->mlx_ptr, p_syn->tri.tex[2].path, &p_tri->tex[2].width, &p_tri->tex[2].height);
	p_tri->tex[2].data = (int *)mlx_get_data_addr(p_tri->tex[2].ptr, &p_tri->tex[2].bpp, &p_tri->tex[2].size_l, &p_tri->tex[2].endian);
    
    p_tri->tex[3].ptr = mlx_xpm_file_to_image(p_tri->mlx_ptr, p_syn->tri.tex[3].path, &p_tri->tex[3].width, &p_tri->tex[3].height);
	p_tri->tex[3].data = (int *)mlx_get_data_addr(p_tri->tex[3].ptr, &p_tri->tex[3].bpp, &p_tri->tex[3].size_l, &p_tri->tex[3].endian);

    p_tri->tex[4].ptr = mlx_xpm_file_to_image(p_tri->mlx_ptr, p_syn->tri.tex[4].path, &p_tri->tex[4].width, &p_tri->tex[4].height);
	p_tri->tex[4].data = (int *)mlx_get_data_addr(p_tri->tex[4].ptr, &p_tri->tex[4].bpp, &p_tri->tex[4].size_l, &p_tri->tex[4].endian);
}


void dda_init(t_tri *p_tri)
{
    //printf("IN DDA  INIT  pos[0] = %f pos[1] = %f", p_tri->pos[0], p_tri->pos[1]);
    t_dda *p_dd = &(p_tri->dda);

    p_dd->map_x = (int)p_tri->pos[0];
    p_dd->map_y = (int)p_tri->pos[1];
    p_dd->deltadist_x = (p_dd->raydir_y == 0) ? 0 : ((p_dd->raydir_x == 0) ? 1 : fabs(1 / p_dd->raydir_x));
    p_dd->deltadist_y = (p_dd->raydir_x == 0) ? 0 : ((p_dd->raydir_x == 0) ? 1 : fabs(1 / p_dd->raydir_y));
    if (p_dd->raydir_x > 0)
        p_dd->sidedist_x = (p_dd->map_x + 1 - p_tri->pos[0]) * p_dd->deltadist_x;
    else
        p_dd->sidedist_x = (p_tri->pos[0] - p_dd->map_x) * p_dd->deltadist_x;
    if (p_dd->raydir_y > 0)
        p_dd->sidedist_y = (p_dd->map_y + 1 - p_tri->pos[1]) * p_dd->deltadist_y;
    else
        p_dd->sidedist_y = (p_tri->pos[1] - p_dd->map_y) * p_dd->deltadist_y;
    //printf("dda init delta = %f\n", p_tri->dda.deltadist_x);
    //printf("dda init side = %f\n", p_tri->dda.sidedist_x);
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

void make_clean(t_syn *p_syn)
{
    int x = 0;

    while (x <= p_syn->R[1])
    {
        make_line(p_syn, x, 0, p_syn->R[1], 0x00);
        x++;
    }
}

void make_under(t_syn *p_syn)
{
    int i = p_syn->R[1] / 2;
    int j;

    while (i <= p_syn->R[1])
    {
        j = 0;
        while (j <= p_syn->R[0])
            my_mlx_pixel_put(&(p_syn->img), j++, i, p_syn->f_color);
        i++;
    }
}

void make_over(t_syn *p_syn)
{
    int i = 0;
    int j;

    while (i <= p_syn->R[1] / 2)
    {
        j = 0;
        while (j <= p_syn->R[0])
            my_mlx_pixel_put(&(p_syn->img), j++, i, p_syn->c_color);
        i++;
    }
}

int main_loop(t_syn *p_syn)
{
    int i = 0;
    double weight;
    int idx;
    make_clean(p_syn);
    make_over(p_syn);
    make_under(p_syn);
    
    //printf("test\n");
    //printf("p_syn->tri.pos[0] : %d\n", p_syn->tri.pos[0]);
    //printf("IN MAIN LOOP \n pos[0] = %f pos[1] = %f", p_syn->tri.pos[0], p_syn->tri.pos[1]);
    //printf("IN MAIN LOOP \n plane[0] = %f plane[1] = %f", p_syn->tri.plane[0], p_syn->tri.plane[1]);
    //printf("R = %d\n", p_syn->R[0]);
    while (i < p_syn->R[0])
    {
        weight = 2 * i / (double)p_syn->R[0] - 1;
        p_syn->tri.dda.raydir_x = p_syn->tri.dir[0] + p_syn->tri.plane[0] * weight;
        p_syn->tri.dda.raydir_y = p_syn->tri.dir[1] + p_syn->tri.plane[1] * weight;
        make_block(p_syn, &idx, i);
        p_syn->ZBuffer[i] = p_syn->tri.dda.walldist;
        i++;
    }
    make_sprite(p_syn);
    mlx_put_image_to_window(p_syn->tri.mlx_ptr, p_syn->tri.win_ptr, p_syn->img.img_ptr, 0, 0);
    return (0);
}

void make_line(t_syn *p_syn, int x_pos, int start, int end, int color)
{
    int y;

    y = start;
    while (y <= end)
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

void ft_close(t_syn *p_syn)
{
    mlx_destroy_window(p_syn->tri.mlx_ptr, p_syn->tri.win_ptr);
    exit(0);
}

int key_func(int keycode, t_syn *p_syn)
{
    double temp;
    int mapx = (int)p_syn->tri.pos[0];
    int mapy = (int)p_syn->tri.pos[1];
    double speed = 1;//속도를 너무 빨리해버리면 비스듬하게 기둥을 바라보는 방향으로 앞으로 이동할때 기둥을 통과하는 문제가 생긴다.
    //printf(" posx %f posy %f  dirx %f diry %f panex plnaey \n", p_syn->tri.pos[0], p_syn->tri.pos[1], p_syn->tri.dir[0], p_syn->tri.dir[1]);
    if (keycode == KEY_A)
    {
        p_syn->tri.pos[0] -= p_syn->tri.plane[0] *speed;
        p_syn->tri.pos[1] -= p_syn->tri.plane[1] *speed;
        if (p_syn->tri.test_map[(int)(p_syn->tri.pos[0])][(int)(p_syn->tri.pos[1])] > 0)
        {
            p_syn->tri.pos[0] += p_syn->tri.plane[0] *speed;
            p_syn->tri.pos[1] += p_syn->tri.plane[1] *speed;
        }
    }
    else if (keycode == KEY_W)
    {
        p_syn->tri.pos[0] += p_syn->tri.dir[0] *speed;
        p_syn->tri.pos[1] += p_syn->tri.dir[1] *speed;
        if (p_syn->tri.test_map[(int)(p_syn->tri.pos[0])][(int)(p_syn->tri.pos[1])] > 0)
        {
            p_syn->tri.pos[0] -= p_syn->tri.dir[0] *speed;
            p_syn->tri.pos[1] -= p_syn->tri.dir[1] *speed;
            /*int test_H = fabs(p_syn->tri.pos[1] - (int)p_syn->tri.pos[1]);
            if (fabs(test_H * (p_syn->tri.dir[0] / p_syn->tri.dir[1])) > fabs(p_syn->tri.pos[0] - (int)(p_syn->tri.pos[0])))
                p_syn->tri.pos[1] = (int)(p_syn->tri.pos[1]);
            else if(fabs(test_H * (p_syn->tri.dir[0] / p_syn->tri.dir[1])) < fabs(p_syn->tri.pos[0] - (int)(p_syn->tri.pos[0])))
                p_syn->tri.pos[0] = (int)(p_syn->tri.pos[0]);
            else if (fabs(test_H * (p_syn->tri.dir[0] / p_syn->tri.dir[1])) == fabs(p_syn->tri.pos[0] - (int)(p_syn->tri.pos[0])))
            {
                p_syn->tri.pos[1] = (int)(p_syn->tri.pos[1]);
                p_syn->tri.pos[0] = (int)(p_syn->tri.pos[0]);
            }*/
        }
    }
    else if(keycode == KEY_D)
    {
        p_syn->tri.pos[0] += p_syn->tri.plane[0] *speed;
        p_syn->tri.pos[1] += p_syn->tri.plane[1] *speed;
        if (p_syn->tri.test_map[(int)(p_syn->tri.pos[0])][(int)(p_syn->tri.pos[1])] > 0)
        {
            p_syn->tri.pos[0] -= p_syn->tri.plane[0] *speed;
            p_syn->tri.pos[1] -= p_syn->tri.plane[1] *speed;
        } 
    }
    else if (keycode == KEY_S)
    {
        p_syn->tri.pos[0] -= p_syn->tri.dir[0] *speed;
        p_syn->tri.pos[1] -= p_syn->tri.dir[1] *speed;
        if (p_syn->tri.test_map[(int)(p_syn->tri.pos[0])][(int)(p_syn->tri.pos[1])] > 0)
        {
            p_syn->tri.pos[0] += p_syn->tri.dir[0] *speed;
            p_syn->tri.pos[1] += p_syn->tri.dir[1] *speed;
        }
    }
    else if (keycode == KEY_LEFT)
    {
        temp = p_syn->tri.dir[0];
        p_syn->tri.dir[0] = p_syn->tri.dir[0] * cos(0.3) - p_syn->tri.dir[1] * sin(0.3);
        p_syn->tri.dir[1] = temp * sin(0.3) + p_syn->tri.dir[1] * cos(0.3);
        temp = p_syn->tri.plane[0];
        p_syn->tri.plane[0] = p_syn->tri.plane[0] * cos(0.3) - p_syn->tri.plane[1] * sin(0.3);
        p_syn->tri.plane[1] = temp * sin(0.3) + p_syn->tri.plane[1] * cos(0.3);
    }
    else if (keycode == KEY_RIGHT)
    {
        temp = p_syn->tri.dir[0];
        p_syn->tri.dir[0] = p_syn->tri.dir[0] * cos(-0.3) - p_syn->tri.dir[1] * sin(-0.3);
        p_syn->tri.dir[1] = temp * sin(-0.3) + p_syn->tri.dir[1] * cos(-0.3);
        temp = p_syn->tri.plane[0];
        p_syn->tri.plane[0] = p_syn->tri.plane[0] * cos(-0.3) - p_syn->tri.plane[1] * sin(-0.3);
        p_syn->tri.plane[1] = temp * sin(-0.3) + p_syn->tri.plane[1] * cos(-0.3);
    }
    else if (keycode == KEY_ESC)
        ft_close(p_syn);
    else
        exit(0);
    return (0);
}

int main(int argc, char *argv[])
{
    t_syn syn;
    par(&syn);
    printf("test\n");
    //printf("IN first \n pos[0] = %f pos[1] = %f", syn.tri.pos[0], syn.tri.pos[1]);
    syn.tri.mlx_ptr = mlx_init();
    syn.tri.win_ptr = mlx_new_window(syn.tri.mlx_ptr, syn.R[0], syn.R[1], "hello");
    syn.img.img_ptr = mlx_new_image(syn.tri.mlx_ptr, syn.R[0], syn.R[1]);
    syn.img.data_ptr = mlx_get_data_addr(syn.img.img_ptr, &(syn.img.bpp), &(syn.img.lenth), &(syn.img.endian));
    init_tri(&syn);
    //printf("IN MAIN LOOP \n plane[0] = %f plane[1] = %f", syn.tri.plane[0], syn.tri.plane[1]);
    mlx_hook(syn.tri.win_ptr, 2, 0, &key_func, &syn);
    mlx_loop_hook(syn.tri.mlx_ptr, &main_loop, &syn);
    //printf(" posx %f posy %f  dirx %f diry %f panex plnaey \n", syn.tri.pos[0], syn.tri.pos[1], syn.tri.dir[0], syn.tri.dir[1]);
    mlx_loop(syn.tri.mlx_ptr);
    return (0);
}