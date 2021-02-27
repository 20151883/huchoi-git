#include "cub3d.h"

void make_block(t_syn *p_syn, int *p_idx, int i)
{
    dda_init(&(p_syn->tri));
    dda_init_second(&(p_syn->tri));
    dda_loop(&(p_syn->tri));
    change_uclied_vertical(&(p_syn->tri));//strcut->walldist에 값이 저장된다.
    p_syn->lineHeight = (double)H / (p_syn->tri.dda.walldist);
    p_syn->drawStart = -p_syn->lineHeight / 2 + screenHeight / 2;//int연산
    if(p_syn->drawStart < 0)
         p_syn->drawStart = 0;
    p_syn->drawEnd = p_syn->lineHeight / 2 + screenHeight / 2;//int 연산
    if(p_syn->drawEnd >= H)
        p_syn->drawEnd = H - 1;
    if (p_syn->tri.dda.side == 0) 
        p_syn->wallX = p_syn->tri.pos[1] + p_syn->tri.dda.walldist * p_syn->tri.dda.raydir_y;
    else
        p_syn->wallX = p_syn->tri.pos[0] + p_syn->tri.dda.walldist * p_syn->tri.dda.raydir_x;
    p_syn->wallX -= floor((p_syn->wallX));
    news(p_syn, p_idx);
    p_syn->texPos = (p_syn->drawStart - H / 2 + p_syn->lineHeight / 2) * p_syn->step;
    for (int y = p_syn->drawStart; y<p_syn->drawEnd; y++)
    {
        p_syn->texY = (int)p_syn->texPos & (p_syn->tri.tex[*p_idx].height - 1);
        p_syn->texPos += p_syn->step;
        p_syn->color = p_syn->tri.tex[*p_idx].data[p_syn->tri.tex[*p_idx].height * p_syn->texY + p_syn->texX];
        my_mlx_pixel_put(&(p_syn->img), i, y, p_syn->color);
    }
}

void news(t_syn *p_syn, int *p_idx)
{
    if ((p_syn->tri.dda.raydir_x >= 0) && p_syn->tri.dda.side == 0)//
    {
        *p_idx = 0;
        before_make_texture(p_syn, p_idx);
    }
    else if (p_syn->tri.dda.raydir_x <= 0 && p_syn->tri.dda.side == 0)
    {   
        *p_idx = 1;
        before_make_texture(p_syn, p_idx);
    }   
    else if (p_syn->tri.dda.raydir_y >= 0 && p_syn->tri.dda.side == 1)
    {    
        *p_idx= 2;
        before_make_texture(p_syn, p_idx);
    }
    else if (p_syn->tri.dda.raydir_y <= 0 && p_syn->tri.dda.side == 1)
    {
        *p_idx = 3;
        before_make_texture(p_syn, p_idx);
    }
    else
        return;
}

void before_make_texture(t_syn *p_syn, int *p_idx)
{
    p_syn->texX = (int)(p_syn->wallX * (double)p_syn->tri.tex[3].width);
    if(p_syn->tri.dda.side == 0 && p_syn->tri.dda.raydir_x > 0) 
        p_syn->texX = p_syn->tri.tex[3].width - p_syn->texX - 1;
    if(p_syn->tri.dda.side == 1 && p_syn->tri.dda.raydir_y < 0) 
        p_syn->texX = p_syn->tri.tex[3].width - p_syn->texX - 1;
    p_syn->step = 1.0 * p_syn->tri.tex[3].height / p_syn->lineHeight;
}

void make_sprite(t_syn *p_syn, Sprite *sprite)
{
    for(int i = 0; i < numSprites; i++)
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
    }
}