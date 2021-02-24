#include "cub3d.h"
void init_tri(t_tri *p_tri)
{
    p_tri->pos[0] = 20;
    p_tri->pos[1] = 20;
    p_tri->dir[0] = -1;
    p_tri->dir[1] = 0;
    //abs_must_epual_one(p_tri);
    p_tri->plane[0] = 0;
    p_tri->plane[1] = 0.66;
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
    p_tri->tex[0].ptr = mlx_xpm_file_to_image(p_tri->mlx_ptr, "./pics/eagle.xpm", &(p_tri->tex[0].width), &(p_tri->tex[0].height));
	p_tri->tex[0].data = (int *)mlx_get_data_addr(p_tri->tex[0].ptr, &p_tri->tex[0].bpp, &p_tri->tex[0].size_l, &p_tri->tex[0].endian);
    
    p_tri->tex[1].ptr = mlx_xpm_file_to_image(p_tri->mlx_ptr, "./pics/wall_1.xpm", &p_tri->tex[1].width, &p_tri->tex[1].height);
	p_tri->tex[1].data = (int *)mlx_get_data_addr(p_tri->tex[1].ptr, &p_tri->tex[1].bpp, &p_tri->tex[1].size_l, &p_tri->tex[1].endian);
    
    p_tri->tex[2].ptr = mlx_xpm_file_to_image(p_tri->mlx_ptr, "./pics/wall_2.xpm", &p_tri->tex[2].width, &p_tri->tex[2].height);
	p_tri->tex[2].data = (int *)mlx_get_data_addr(p_tri->tex[2].ptr, &p_tri->tex[2].bpp, &p_tri->tex[2].size_l, &p_tri->tex[2].endian);
    
    p_tri->tex[3].ptr = mlx_xpm_file_to_image(p_tri->mlx_ptr, "./pics/wall_3.xpm", &p_tri->tex[3].width, &p_tri->tex[3].height);
	p_tri->tex[3].data = (int *)mlx_get_data_addr(p_tri->tex[3].ptr, &p_tri->tex[3].bpp, &p_tri->tex[3].size_l, &p_tri->tex[3].endian);

    p_tri->tex[4].ptr = mlx_xpm_file_to_image(p_tri->mlx_ptr, "./pics/sprite_1.xpm", &p_tri->tex[4].width, &p_tri->tex[4].height);
	p_tri->tex[4].data = (int *)mlx_get_data_addr(p_tri->tex[4].ptr, &p_tri->tex[4].bpp, &p_tri->tex[4].size_l, &p_tri->tex[4].endian);

    p_tri->tex[5].ptr = mlx_xpm_file_to_image(p_tri->mlx_ptr, "./pics/sprite_2.xpm", &p_tri->tex[5].width, &p_tri->tex[5].height);
	p_tri->tex[5].data = (int *)mlx_get_data_addr(p_tri->tex[5].ptr, &p_tri->tex[5].bpp, &p_tri->tex[5].size_l, &p_tri->tex[5].endian);

    p_tri->tex[6].ptr = mlx_xpm_file_to_image(p_tri->mlx_ptr, "./pics/sprite_3.xpm", &p_tri->tex[6].width, &p_tri->tex[6].height);
	p_tri->tex[6].data = (int *)mlx_get_data_addr(p_tri->tex[6].ptr, &p_tri->tex[6].bpp, &p_tri->tex[6].size_l, &p_tri->tex[6].endian);

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

void make_under(t_syn *p_syn)
{
    int i = screenHeight / 2;
    int j;

    while (i <= screenHeight)
    {
        j = 0;
        while (j <= screenWidth)
            my_mlx_pixel_put(&(p_syn->img), j++, i, 0x663300);
        i++;
    }
}

void make_over(t_syn *p_syn)
{
    int i = 0;
    int j;

    while (i <= screenHeight / 2)
    {
        j = 0;
        while (j <= screenWidth)
            my_mlx_pixel_put(&(p_syn->img), j++, i, 0x3300CC);
        i++;
    }
}

int main_loop(t_syn *p_syn)
{
    Sprite sprite[numSprites] =
    {
        {20.5, 11.5, 4},
        {18.5,4.5, 4},
        {10.0,4.5, 4},
        {10.0,12.5,4},
        {3.5, 6.5, 4},
        {3.5, 20.5,4},
        {3.5, 14.5,4},
        {14.5,20.5,4},
        {18.5, 10.5, 5},
        {18.5, 11.5, 5},
        {18.5, 12.5, 5},
        {21.5, 1.5, 6},
        {15.5, 1.5, 6},
        {16.0, 1.8, 6},
        {16.2, 1.2, 6},
        {3.5,  2.5, 6},
        {9.5, 15.5, 6},
        {10.0, 15.1,6},
        {10.5, 15.8,6},
    };
    //double ZBuffer[screenWidth];
    int i = 0;
    double weight;
    int idx;
    make_clean(p_syn);
    make_over(p_syn);
    make_under(p_syn);
    
    while (i < screenWidth)
    {
        weight = 2 * i / (double)screenWidth - 1;
        p_syn->tri.dda.raydir_x = p_syn->tri.dir[0] + p_syn->tri.plane[0] * weight;
        p_syn->tri.dda.raydir_y = p_syn->tri.dir[1] + p_syn->tri.plane[1] * weight;
        make_block(p_syn, &idx, i);
        p_syn->ZBuffer[i] = p_syn->tri.dda.walldist;
        i++;
    }
        
    /*for(int i = 0; i < numSprites; i++)
    {
        p_syn->spriteOrder[i] = i;
        p_syn->spriteDistance[i] = ((p_syn->tri.pos[0] - sprite[i].x) * (p_syn->tri.pos[0] - sprite[i].x) + (p_syn->tri.pos[1] - sprite[i].y) * (p_syn->tri.pos[1] - sprite[i].y));
    }
    //sortSprites(spriteOrder, spriteDistance, numSprites);
    for(int i = 0; i < 10; i++)
    {
        p_syn->spriteX = sprite[p_syn->spriteOrder[i]].x - p_syn->tri.pos[0];
        p_syn->spriteY = sprite[p_syn->spriteOrder[i]].y - p_syn->tri.pos[1];
        p_syn->invDet = 1.0 / (p_syn->tri.plane[0] * p_syn->tri.dir[1] - p_syn->tri.dir[0] * p_syn->tri.plane[1]);
        p_syn->transformX = p_syn->invDet * (p_syn->tri.dir[1] * p_syn->spriteX - p_syn->tri.dir[0] * p_syn->spriteY);
        p_syn->transformY = p_syn->invDet * (-p_syn->tri.plane[1] * p_syn->spriteX + p_syn->tri.plane[0] * p_syn->spriteY);
        p_syn->spriteScreenX = (int)((screenWidth / 2) * (1 + p_syn->transformX / p_syn->transformY));

        p_syn->spriteHeight = abs((int)(H / (p_syn->transformY)));
      
        p_syn->drawStartY = -p_syn->spriteHeight / 2 + H / 2;
        if(p_syn->drawStartY < 0) p_syn->drawStartY = 0;
        p_syn->drawEndY = p_syn->spriteHeight / 2 + H / 2;
        if(p_syn->drawEndY >= H) p_syn->drawEndY = H - 1;

        p_syn->spriteWidth = abs((int)(H / (p_syn->transformY)));
        p_syn->drawStartX = -p_syn->spriteWidth / 2 + p_syn->spriteScreenX;
        if(p_syn->drawStartX < 0) p_syn->drawStartX = 0;
        p_syn->drawEndX = p_syn->spriteWidth / 2 + p_syn->spriteScreenX;
        if(p_syn->drawEndX >= screenWidth) p_syn->drawEndX = screenWidth - 1;

        for(p_syn->stripe = p_syn->drawStartX; p_syn->stripe < p_syn->drawEndX; (p_syn->stripe)++)
        {
            p_syn->texX = (int)(256 * (p_syn->stripe - (-p_syn->spriteWidth / 2 + p_syn->spriteScreenX)) * p_syn->tri.tex[sprite[p_syn->spriteOrder[i]].texture].width / p_syn->spriteWidth) / 256;
            if(p_syn->transformY > 0 && p_syn->stripe > 0 && p_syn->stripe < screenWidth && p_syn->transformY < p_syn->ZBuffer[p_syn->stripe])
            {
                for(p_syn->y = p_syn->drawStartY; p_syn->y < p_syn->drawEndY; (p_syn->y)++)
                {
                    p_syn->d = (p_syn->y) * 256 - H * 128 + p_syn->spriteHeight * 128;
                    p_syn->texY = ((p_syn->d * p_syn->tri.tex[sprite[p_syn->spriteOrder[i]].texture].height) / p_syn->spriteHeight) / 256;
                    p_syn->color = p_syn->tri.tex[sprite[p_syn->spriteOrder[i]].texture].data[p_syn->tri.tex[sprite[p_syn->spriteOrder[i]].texture].width * p_syn->texY + p_syn->texX];
                    if((p_syn->color & 0x00FFFFFF) != 0) my_mlx_pixel_put(&(p_syn->img), p_syn->stripe, p_syn->y, p_syn->color);
                }
            }
        }
    }*/
    make_sprite(p_syn, sprite);
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

    syn.tri.mlx_ptr = mlx_init();
    syn.tri.win_ptr = mlx_new_window(syn.tri.mlx_ptr, 640, 640, "hello");
    syn.img.img_ptr = mlx_new_image(syn.tri.mlx_ptr, 640, 640);
    syn.img.data_ptr = mlx_get_data_addr(syn.img.img_ptr, &(syn.img.bpp), &(syn.img.lenth), &(syn.img.endian));
    init_tri(&(syn.tri));
    mlx_hook(syn.tri.win_ptr, 2, 0, &key_func, &syn);
    mlx_loop_hook(syn.tri.mlx_ptr, &main_loop, &syn);
    mlx_loop(syn.tri.mlx_ptr);
    return (0);
}