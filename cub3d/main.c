#include "cub3d.h"

typedef struct Sprite
{
  double x;
  double y;
  int texture;
}Sprite;
#define numSprites 19
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
        {20.5, 11.5, 4}, //green light in front of playerstart
         //green lights in every room
        {18.5,4.5, 4},
        {10.0,4.5, 4},
        {10.0,12.5,4},
        {3.5, 6.5, 4},
        {3.5, 20.5,4},
        {3.5, 14.5,4},
        {14.5,20.5,4},

  //row of pillars in front of wall: fisheye test
        {18.5, 10.5, 5},
        {18.5, 11.5, 5},
        {18.5, 12.5, 5},

  //some barrels around the map
        {21.5, 1.5, 6},
        {15.5, 1.5, 6},
        {16.0, 1.8, 6},
        {16.2, 1.2, 6},
        {3.5,  2.5, 6},
        {9.5, 15.5, 6},
        {10.0, 15.1,6},
        {10.5, 15.8,6},
    };
    double ZBuffer[screenWidth];
    int spriteOrder[numSprites];
    double spriteDistance[numSprites];


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
    make_over(p_syn);
    make_under(p_syn);
    //my_mlx_pixel_put(p_syn->img.img_ptr, 1, 1, 0x3300CC);
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
        //int textNum = p_syn->tri.worldMap[p_syn->tri.dda.map_x][p_syn->tri.dda.map_y];
        if (p_syn->tri.dda.side == 0) 
            wallX = p_syn->tri.pos[1] + p_syn->tri.dda.walldist * p_syn->tri.dda.raydir_y;
        else            
            wallX = p_syn->tri.pos[0] + p_syn->tri.dda.walldist * p_syn->tri.dda.raydir_x;
        wallX -= floor((wallX));
        //x coordinate on the texture
        if ((p_syn->tri.dda.raydir_x >= 0) && p_syn->tri.dda.side == 0)//]
        {
            idx = 0;
            texX = (int)(wallX * (double)p_syn->tri.tex[0].width);
            if(p_syn->tri.dda.side == 0 && p_syn->tri.dda.raydir_x > 0) 
                texX = p_syn->tri.tex[0].width - texX - 1;
            if(p_syn->tri.dda.side == 1 && p_syn->tri.dda.raydir_y < 0) 
                texX = p_syn->tri.tex[0].width - texX - 1;
            step = 1.0 * p_syn->tri.tex[0].height / lineHeight;
        }
        else if (p_syn->tri.dda.raydir_x <= 0 && p_syn->tri.dda.side == 0)
         {   
            idx = 1;
            texX = (int)(wallX * (double)p_syn->tri.tex[1].width);
            if(p_syn->tri.dda.side == 0 && p_syn->tri.dda.raydir_x > 0) 
                texX = p_syn->tri.tex[1].width - texX - 1;
            if(p_syn->tri.dda.side == 1 && p_syn->tri.dda.raydir_y < 0) 
                texX = p_syn->tri.tex[1].width - texX - 1;
            step = 1.0 * p_syn->tri.tex[1].height / lineHeight;
        }   
        else if (p_syn->tri.dda.raydir_y >= 0 && p_syn->tri.dda.side == 1)
        {    
            idx= 2;
            texX = (int)(wallX * (double)p_syn->tri.tex[2].width);
            if(p_syn->tri.dda.side == 0 && p_syn->tri.dda.raydir_x > 0) 
                texX = p_syn->tri.tex[2].width - texX - 1;
            if(p_syn->tri.dda.side == 1 && p_syn->tri.dda.raydir_y < 0) 
                texX = p_syn->tri.tex[2].width - texX - 1;
            step = 1.0 * p_syn->tri.tex[2].height / lineHeight;
        }
        else if (p_syn->tri.dda.raydir_y <= 0 && p_syn->tri.dda.side == 1)
        {
            idx = 3;
            texX = (int)(wallX * (double)p_syn->tri.tex[3].width);
            if(p_syn->tri.dda.side == 0 && p_syn->tri.dda.raydir_x > 0) 
                texX = p_syn->tri.tex[3].width - texX - 1;
            if(p_syn->tri.dda.side == 1 && p_syn->tri.dda.raydir_y < 0) 
                texX = p_syn->tri.tex[3].width - texX - 1;
            step = 1.0 * p_syn->tri.tex[3].height / lineHeight;
        }
        texPos = (drawStart - H / 2 + lineHeight / 2) * step;
        for (int y = drawStart; y<drawEnd; y++)
        {
             // Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
            texY = (int)texPos & (p_syn->tri.tex[idx].height - 1);
            texPos += step;
            color = p_syn->tri.tex[idx].data[p_syn->tri.tex[idx].height * texY + texX];
            my_mlx_pixel_put(&(p_syn->img), i, y, color);
        }
        /*ZBuffer[i] = p_syn->tri.dda.walldist; //perpendicular distance is used
        for(int i = 0; i < numSprites; i++)
        {
            spriteOrder[i] = i;
            spriteDistance[i] = ((p_syn->tri.pos[0] - sprite[i].x) * (p_syn->tri.pos[0] - sprite[i].x) + (p_syn->tri.pos[1] - sprite[i].y) * (p_syn->tri.pos[1] - sprite[i].y)); //sqrt not taken, unneeded
        }
        //sortSprites(spriteOrder, spriteDistance, numSprites);//*******************&********************(************)
        for(int i = 0; i < 1; i++)
        {
      //translate sprite position to relative to camera
            double spriteX = sprite[spriteOrder[i]].x - p_syn->tri.pos[0];
            double spriteY = sprite[spriteOrder[i]].y - p_syn->tri.pos[1];

      //transform sprite with the inverse camera matrix
      // [ planeX   dirX ] -1                                       [ dirY      -dirX ]
      // [               ]       =  1/(planeX*dirY-dirX*planeY) *   [                 ]
      // [ planeY   dirY ]                                          [ -planeY  planeX ]

            double invDet = 1.0 / (p_syn->tri.plane[0] * p_syn->tri.dir[1] - p_syn->tri.dir[0] * p_syn->tri.plane[1]); //required for correct matrix multiplication

            double transformX = invDet * (p_syn->tri.dir[1] * spriteX - p_syn->tri.dir[0] * spriteY);
            double transformY = invDet * (-p_syn->tri.plane[1] * spriteX + p_syn->tri.plane[0] * spriteY); //this is actually the depth inside the screen, that what Z is in 3D

            int spriteScreenX = (int)((w / 2) * (1 + transformX / transformY));

      //calculate height of the sprite on screen
            int spriteHeight = abs((int)(H / (transformY))); //using 'transformY' instead of the real distance prevents fisheye
      //calculate lowest and highest pixel to fill in current stripe
            int drawStartY = -spriteHeight / 2 + H / 2;
            if(drawStartY < 0) drawStartY = 0;
            int drawEndY = spriteHeight / 2 + H / 2;
            if(drawEndY >= H) drawEndY = H - 1;

      //calculate width of the sprite
            int spriteWidth = abs((int)(H / (transformY)));
            int drawStartX = -spriteWidth / 2 + spriteScreenX;
            if(drawStartX < 0) drawStartX = 0;
            int drawEndX = spriteWidth / 2 + spriteScreenX;
            if(drawEndX >= w) drawEndX = w - 1;

      //loop through every vertical stripe of the sprite on screen
            for(int stripe = drawStartX; stripe < drawEndX; stripe++)
            {
                int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * p_syn->tri.tex[sprite[spriteOrder[i]].texture].width / spriteWidth) / 256;
        //the conditions in the if are:
        //1) it's in front of camera plane so you don't see things behind you
        //2) it's on the screen (left)
        //3) it's on the screen (right)
        //4) ZBuffer, with perpendicular distance
                if(transformY > 0 && stripe > 0 && stripe < w && transformY < ZBuffer[stripe])
                {
                    for(int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
                    {
                        int d = (y) * 256 - H * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
                        int texY = ((d * p_syn->tri.tex[sprite[spriteOrder[i]].texture].height) / spriteHeight) / 256;
                        int color = p_syn->tri.tex[sprite[spriteOrder[i]].texture].data[p_syn->tri.tex[sprite[spriteOrder[i]].texture].width * texY + texX]; //get current color from the texture
                        if((color & 0x00FFFFFF) != 0) my_mlx_pixel_put(&(p_syn->img), stripe, y, color); //buffer[y][stripe] = color; //paint pixel if it isn't black, black is the invisible color
                    }
                }
            }
        }*/
        ZBuffer[i] = p_syn->tri.dda.walldist; //perpendicular distance is used
        i++;
    }
        
    for(int i = 0; i < numSprites; i++)
    {
        spriteOrder[i] = i;
        spriteDistance[i] = ((p_syn->tri.pos[0] - sprite[i].x) * (p_syn->tri.pos[0] - sprite[i].x) + (p_syn->tri.pos[1] - sprite[i].y) * (p_syn->tri.pos[1] - sprite[i].y)); //sqrt not taken, unneeded
    }
        //sortSprites(spriteOrder, spriteDistance, numSprites);//*******************&********************(************)
    for(int i = 0; i < 10; i++)
    {
      //translate sprite position to relative to camera
        double spriteX = sprite[spriteOrder[i]].x - p_syn->tri.pos[0];
        double spriteY = sprite[spriteOrder[i]].y - p_syn->tri.pos[1];

      //transform sprite with the inverse camera matrix
      // [ planeX   dirX ] -1                                       [ dirY      -dirX ]
      // [               ]       =  1/(planeX*dirY-dirX*planeY) *   [                 ]
      // [ planeY   dirY ]                                          [ -planeY  planeX ]

        double invDet = 1.0 / (p_syn->tri.plane[0] * p_syn->tri.dir[1] - p_syn->tri.dir[0] * p_syn->tri.plane[1]); //required for correct matrix multiplication

        double transformX = invDet * (p_syn->tri.dir[1] * spriteX - p_syn->tri.dir[0] * spriteY);
        double transformY = invDet * (-p_syn->tri.plane[1] * spriteX + p_syn->tri.plane[0] * spriteY); //this is actually the depth inside the screen, that what Z is in 3D

        int spriteScreenX = (int)((w / 2) * (1 + transformX / transformY));

      //calculate height of the sprite on screen
        int spriteHeight = abs((int)(H / (transformY))); //using 'transformY' instead of the real distance prevents fisheye
      //calculate lowest and highest pixel to fill in current stripe
        int drawStartY = -spriteHeight / 2 + H / 2;
        if(drawStartY < 0) drawStartY = 0;
        int drawEndY = spriteHeight / 2 + H / 2;
        if(drawEndY >= H) drawEndY = H - 1;

      //calculate width of the sprite
        int spriteWidth = abs((int)(H / (transformY)));
        int drawStartX = -spriteWidth / 2 + spriteScreenX;
        if(drawStartX < 0) drawStartX = 0;
        int drawEndX = spriteWidth / 2 + spriteScreenX;
        if(drawEndX >= w) drawEndX = w - 1;

      //loop through every vertical stripe of the sprite on screen
        for(int stripe = drawStartX; stripe < drawEndX; stripe++)
        {
            int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * p_syn->tri.tex[sprite[spriteOrder[i]].texture].width / spriteWidth) / 256;
        //the conditions in the if are:
        //1) it's in front of camera plane so you don't see things behind you
        //2) it's on the screen (left)
        //3) it's on the screen (right)
        //4) ZBuffer, with perpendicular distance
            if(transformY > 0 && stripe > 0 && stripe < w && transformY < ZBuffer[stripe])
            {
                for(int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
                {
                    int d = (y) * 256 - H * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
                    int texY = ((d * p_syn->tri.tex[sprite[spriteOrder[i]].texture].height) / spriteHeight) / 256;
                    int color = p_syn->tri.tex[sprite[spriteOrder[i]].texture].data[p_syn->tri.tex[sprite[spriteOrder[i]].texture].width * texY + texX]; //get current color from the texture
                    if((color & 0x00FFFFFF) != 0) my_mlx_pixel_put(&(p_syn->img), stripe, y, color); //buffer[y][stripe] = color; //paint pixel if it isn't black, black is the invisible color
                }
            }
        }
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
    double speed = 1;//속도를 너무 빨리해버리면 비스듬하게 기둥을 바라보는 방향으로 앞으로 이동한다면 기둥을 통과하는 문제가 생긴다.
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