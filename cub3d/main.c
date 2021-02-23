#include "cub3d.h"

void init_tri(t_tri *p_tri)
{
    p_tri->pos[0] = 20;
    p_tri->pos[1] = 20;
    p_tri->dir[0] = 0;
    p_tri->dir[1] = 1;
    //abs_must_epual_one(p_tri);
    p_tri->plane[0] = 0.77;
    p_tri->plane[1] = 0;
    int arr[mapWidth][mapHeight] =
    {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,3,0,3,0,3,0,0,0,1},
    {1,0,0,0,0,0,2,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,2,0,0,0,1,0,0,0,0,3,0,0,0,3,0,0,0,1},
    {1,0,0,0,0,0,2,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,2,2,0,2,1,0,0,0,0,1,0,3,0,3,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };
    memcpy(p_tri->worldMap, arr, sizeof(int) * mapWidth * mapHeight);
    ///printf("%d %d %d", p_tri->worldMap[0][0])
    /*p_tri->tex[0].ptr = mlx_xpm_file_to_image(p_tri->mlx_ptr, "./pics/eagle.xpm", &(p_tri->tex[0].width), &(p_tri->tex[0].height));
	p_tri->tex[0].data = (int *)mlx_get_data_addr(p_tri->tex[0].ptr, &p_tri->tex[0].bpp, &p_tri->tex[0].size_l, &p_tri->tex[0].endian);
    
    p_tri->tex[1].ptr = mlx_xpm_file_to_image(p_tri->mlx_ptr, "./pics/wall_1.xpm", &p_tri->tex[1].width, &p_tri->tex[1].height);
	p_tri->tex[1].data = (int *)mlx_get_data_addr(p_tri->tex[1].ptr, &p_tri->tex[1].bpp, &p_tri->tex[1].size_l, &p_tri->tex[1].endian);
    
    p_tri->tex[2].ptr = mlx_xpm_file_to_image(p_tri->mlx_ptr, "./pics/wall_2.xpm", &p_tri->tex[2].width, &p_tri->tex[2].height);
	p_tri->tex[2].data = (int *)mlx_get_data_addr(p_tri->tex[2].ptr, &p_tri->tex[2].bpp, &p_tri->tex[2].size_l, &p_tri->tex[2].endian);
    
    p_tri->tex[3].ptr = mlx_xpm_file_to_image(p_tri->mlx_ptr, "./pics/wall_3.xpm", &p_tri->tex[3].width, &p_tri->tex[3].height);
	p_tri->tex[3].data = (int *)mlx_get_data_addr(p_tri->tex[3].ptr, &p_tri->tex[3].bpp, &p_tri->tex[3].size_l, &p_tri->tex[3].endian);*/
}

void dda_init(t_tri *p_tri)
{
    t_dda *p_dd = &(p_tri->dda);
    
    p_dd->map_x = (int)p_tri->pos[0];
    p_dd->map_y = (int)p_tri->pos[1];
    p_dd->deltadist_x = fabs(1.0 / p_tri->dda.raydir_x);
    p_dd->deltadist_y = fabs(1.0 / p_tri->dda.raydir_y);
    if (p_dd->raydir_x > 0)
        p_dd->sidedist_x = (p_dd->map_x + 1 - p_tri->pos[0]) * p_dd->deltadist_x;
    else
        p_dd->sidedist_x = (p_tri->pos[0] - p_dd->map_x) * p_dd->deltadist_x;
    if (p_dd->raydir_y > 0)
        p_dd->sidedist_y = (p_dd->map_y + 1 - p_tri->pos[1]) * p_dd->deltadist_y;
    else
        p_dd->sidedist_y = (p_tri->pos[1] - p_dd->map_y) * p_dd->deltadist_y;
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

    while (x <= screenHeight)
    {
        make_line(p_syn, x, 0, screenHeight, 0x00);
        x++;
    }
}
int main_loop(t_syn *p_syn)
{
    int i = 0;
    double weight;
    int lineHeight;
    int drawStart;
    int drawEnd;
    int color;
    int w = screenWidth;
    int texX;
    double step;
    int idx;
    double wallX; //where exactly the wall was hit
    double texPos;
    int texY;
    make_clean(p_syn);
    while (i < w)
    {
        weight = 2 * i / (double)w - 1;
        p_syn->tri.dda.raydir_x = p_syn->tri.dir[0] + p_syn->tri.plane[0] * weight;
        p_syn->tri.dda.raydir_y = p_syn->tri.dir[1] + p_syn->tri.plane[1] * weight;
        dda_init(&(p_syn->tri));
        dda_init_second(&(p_syn->tri));
        dda_loop(&(p_syn->tri));
        change_uclied_vertical(&(p_syn->tri));//strcut->walldist에 값이 저장된다.
        lineHeight = (double)H / (p_syn->tri.dda.walldist);
        drawStart = -lineHeight / 2 + screenHeight / 2;//int연산
        if(drawStart < 0)
            drawStart = 0;
        drawEnd = lineHeight / 2 + screenHeight / 2;//int 연산
        if(drawEnd >= H)
            drawEnd = H - 1;
        if (p_syn->tri.dda.side == 0) 
            wallX = p_syn->tri.pos[1] + p_syn->tri.dda.walldist * p_syn->tri.dda.raydir_y;
        else           
            wallX = p_syn->tri.pos[0] + p_syn->tri.dda.walldist * p_syn->tri.dda.raydir_x;
        wallX -= floor((wallX));
        //x coordinate on the texture
        /*if (p_syn->tri.dda.raydir_x >= (1 / sqrt(2)))//조건 문제가 있다..
        {
            idx = 0;
            texX = (int)wallX * (double)p_syn->tri.tex[0].width;
            if(p_syn->tri.dda.side == 0 && p_syn->tri.dda.raydir_x > 0) 
                texX = p_syn->tri.tex[0].width - texX - 1;
            if(p_syn->tri.dda.side == 1 && p_syn->tri.dda.raydir_y < 0) 
                texX = p_syn->tri.tex[0].width - texX - 1;
            step = 1.0 * p_syn->tri.tex[0].height / lineHeight;
        }
        else if (p_syn->tri.dda.raydir_x <= (-1) *(1 / sqrt(2)))
         {   
            idx = 1;
            texX = (int)wallX * (double)p_syn->tri.tex[1].width;
            if(p_syn->tri.dda.side == 0 && p_syn->tri.dda.raydir_x > 0) 
                texX = p_syn->tri.tex[1].width - texX - 1;
            if(p_syn->tri.dda.side == 1 && p_syn->tri.dda.raydir_y < 0) 
                texX = p_syn->tri.tex[1].width - texX - 1;
            step = 1.0 * p_syn->tri.tex[1].height / lineHeight;
        }   
        else if (p_syn->tri.dda.raydir_y >= (1 / sqrt(2)))
        {    
            idx= 2;
            texX = (int)wallX * (double)p_syn->tri.tex[2].width;
            if(p_syn->tri.dda.side == 0 && p_syn->tri.dda.raydir_x > 0) 
                texX = p_syn->tri.tex[2].width - texX - 1;
            if(p_syn->tri.dda.side == 1 && p_syn->tri.dda.raydir_y < 0) 
                texX = p_syn->tri.tex[2].width - texX - 1;
            step = 1.0 * p_syn->tri.tex[2].height / lineHeight;
        }
        else //(p_syn->tri.dda.raydir_y <= (-1) * (1 / sqrt(2)))
        {
            idx = 3;
            texX = (int)wallX * (double)p_syn->tri.tex[3].width;
            if(p_syn->tri.dda.side == 0 && p_syn->tri.dda.raydir_x > 0) 
                texX = p_syn->tri.tex[3].width - texX - 1;
            if(p_syn->tri.dda.side == 1 && p_syn->tri.dda.raydir_y < 0) 
                texX = p_syn->tri.tex[3].width - texX - 1;
            step = 1.0 * p_syn->tri.tex[3].height / lineHeight;
        }*/
        idx = 3;
        texX = (int)wallX * (double)p_syn->tri.tex[3].width;
        if(p_syn->tri.dda.side == 0 && p_syn->tri.dda.raydir_x > 0) 
            texX = p_syn->tri.tex[3].width - texX - 1;
        if(p_syn->tri.dda.side == 1 && p_syn->tri.dda.raydir_y < 0) 
            texX = p_syn->tri.tex[3].width - texX - 1;
        step = 1.0 * p_syn->tri.tex[3].height / lineHeight;
        // Starting texture coordinate
        texPos = (drawStart - H / 2 + lineHeight / 2) * step;
        for(int y = drawStart; y<drawEnd; y++)
        {
             // Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
            texY = (int)texPos & (p_syn->tri.tex[idx].height - 1);
            texPos += step;
            color = p_syn->tri.tex[idx].data[p_syn->tri.tex[idx].height * texY + texX];
             //make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
            if(p_syn->tri.dda.side == 1) 
                color = (color >> 1) & 8355711;
            /*p_syn->img.data_ptr[y * screenWidth + i] = color;*/
            my_mlx_pixel_put(&(p_syn->img), i, y, color);
        }
        /*if (p_syn->tri.dda.side == 1) 
            color = 0xFFFF00;
        else
            color = 0xFF0000;
        make_line(p_syn, i, drawStart, drawEnd, color);//w를 아주크게 해서 라인과 라인사이의 간격이 아주 촘촘하면 구분구적법의 느낌이 날것.//image에 그리는거..
        */
        i++;
    }
    mlx_put_image_to_window(p_syn->tri.mlx_ptr, p_syn->tri.win_ptr, p_syn->img.img_ptr, 0, 0);//딱 한번만 호출하는...
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
    double speed = 1;
    if (keycode == KEY_A)
    {
        p_syn->tri.pos[0] -= p_syn->tri.plane[0] *speed;
        p_syn->tri.pos[1] -= p_syn->tri.plane[1] *speed;
        if (p_syn->tri.worldMap[(int)(p_syn->tri.pos[0])][(int)(p_syn->tri.pos[1])] > 0)
        {
            p_syn->tri.pos[0] += p_syn->tri.plane[0] *speed;
            p_syn->tri.pos[1] += p_syn->tri.plane[1] *speed;
        }
    }
    else if (keycode == KEY_W)
    {
        p_syn->tri.pos[0] += p_syn->tri.dir[0] *speed;
        p_syn->tri.pos[1] += p_syn->tri.dir[1] *speed;
        if (p_syn->tri.worldMap[(int)(p_syn->tri.pos[0])][(int)(p_syn->tri.pos[1])] > 0)
        {
            p_syn->tri.pos[0] -= p_syn->tri.dir[0] *speed;
            p_syn->tri.pos[1] -= p_syn->tri.dir[1] *speed;
        }
    }
    else if(keycode == KEY_D)
    {
        p_syn->tri.pos[0] += p_syn->tri.plane[0] *speed;
        p_syn->tri.pos[1] += p_syn->tri.plane[1] *speed;
        if (p_syn->tri.worldMap[(int)(p_syn->tri.pos[0])][(int)(p_syn->tri.pos[1])] > 0)
        {
            p_syn->tri.pos[0] -= p_syn->tri.plane[0] *speed;
            p_syn->tri.pos[1] -= p_syn->tri.plane[1] *speed;
        } 
    }
    else if (keycode == KEY_S)
    {
        p_syn->tri.pos[0] -= p_syn->tri.dir[0] *speed;
        p_syn->tri.pos[1] -= p_syn->tri.dir[1] *speed;
        if (p_syn->tri.worldMap[(int)(p_syn->tri.pos[0])][(int)(p_syn->tri.pos[1])] > 0)
        {
            p_syn->tri.pos[0] += p_syn->tri.dir[0] *speed;
            p_syn->tri.pos[1] += p_syn->tri.dir[1] *speed;
        }
    }
    else if(keycode == KEY_LEFT)
    {
        temp = p_syn->tri.dir[0];
        p_syn->tri.dir[0] = p_syn->tri.dir[0] * cos(-0.3) - p_syn->tri.dir[1] * sin(-0.3);
        p_syn->tri.dir[1] = temp * sin(-0.3) + p_syn->tri.dir[1] * cos(-0.3);
        temp = p_syn->tri.plane[0];
        p_syn->tri.plane[0] = p_syn->tri.plane[0] * cos(-0.3) - p_syn->tri.plane[1] * sin(-0.3);
        p_syn->tri.plane[1] = temp * sin(-0.3) + p_syn->tri.plane[1] * cos(-0.3);
    }
    else if (keycode == KEY_RIGHT)
    {
        temp = p_syn->tri.dir[0];
        p_syn->tri.dir[0] = p_syn->tri.dir[0] * cos(0.3) - p_syn->tri.dir[1] * sin(0.3);
        p_syn->tri.dir[1] = temp * sin(0.3) + p_syn->tri.dir[1] * cos(0.3);
        temp = p_syn->tri.plane[0];
        p_syn->tri.plane[0] = p_syn->tri.plane[0] * cos(0.3) - p_syn->tri.plane[1] * sin(0.3);
        p_syn->tri.plane[1] = temp * sin(0.3) + p_syn->tri.plane[1] * cos(0.3);
    }
    else if (keycode == KEY_ESC)
        close(p_syn);
    else
        exit(0);
    return (0);
}

int main(int argc, char *argv[])
{
    t_syn syn;

    syn.tri.mlx_ptr = mlx_init();
    syn.tri.win_ptr = mlx_new_window(syn.tri.mlx_ptr, 640, 640, "hello");
    syn.img.img_ptr = mlx_new_image(syn.tri.mlx_ptr, 640, 640);
    syn.img.data_ptr = mlx_get_data_addr(syn.img.img_ptr, &(syn.img.bpp), &(syn.img.lenth), &(syn.img.endian));
    init_tri(&(syn.tri));
    t_tex test;
    test.ptr = mlx_xpm_file_to_image(syn.tri.mlx_ptr, "/Users/huchoi/huchoi-git/cub3d/pics/wall_1.xpm", &test.width, &test.height);
	test.data = (int *)mlx_get_data_addr(test.ptr, &test.bpp, &test.size_l, &test.endian);
    //mlx_hook(syn.tri.win_ptr, 2, 0, &key_func, &syn);
    //mlx_loop_hook(syn.tri.mlx_ptr, &main_loop, &syn);
    mlx_loop(syn.tri.mlx_ptr);
    return (0);
}