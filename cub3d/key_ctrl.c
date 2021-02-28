#include "cub3d.h"

void ctrl_pos(int keycode, t_syn *p_syn)
{
    double speed;

    speed = 0.3;
    if (keycode == KEY_W)
    {
        pos_WS(p_syn, speed);
    }
    else if (keycode == KEY_D)
    {
        pos_AD(p_syn, speed);
    }
    else if (keycode == KEY_S)
    {
        pos_WS(p_syn, -speed);
    }
    else if (keycode == KEY_A)
    {
        pos_AD(p_syn, -speed);
    }
    else
        return;
}

void pos_WS(t_syn*p_syn, double weight)
{
    p_syn->tri.pos[0] += p_syn->tri.dir[0] * weight;
    p_syn->tri.pos[1] += p_syn->tri.dir[1] * weight;
    if (p_syn->tri.test_map[(int)(p_syn->tri.pos[0])][(int)(p_syn->tri.pos[1])] == 1)
    {
        p_syn->tri.pos[0] -= p_syn->tri.dir[0] * weight;
        p_syn->tri.pos[1] -= p_syn->tri.dir[1] * weight;
    }
}

void pos_AD(t_syn *p_syn, double weight)
{
    p_syn->tri.pos[0] += p_syn->tri.plane[0] * weight;
    p_syn->tri.pos[1] += p_syn->tri.plane[1] * weight;
    if (p_syn->tri.test_map[(int)(p_syn->tri.pos[0])][(int)(p_syn->tri.pos[1])] == 1)
    {
        p_syn->tri.pos[0] -= p_syn->tri.plane[0] * weight;
        p_syn->tri.pos[1] -= p_syn->tri.plane[1] * weight;
    }
}

void ctrl_dir(int keycode, t_syn *p_syn)
{
    double theta;

    theta = 0.3;
    if (keycode == KEY_LEFT)
    {
        rotate_dir(p_syn, +theta);
    }
    else if (keycode == KEY_RIGHT)
    {
        rotate_dir(p_syn, -theta);
    }
    else
        return;
}

void rotate_dir(t_syn *p_syn, double theta)
{
    double  temp;
    double  c = cos(theta);
    double  s = sin(theta);

    temp = p_syn->tri.dir[0];
    p_syn->tri.dir[0] = c * p_syn->tri.dir[0] - s * p_syn->tri.dir[1];
    p_syn->tri.dir[1] = s * temp + c * p_syn->tri.dir[1];
    temp = p_syn->tri.plane[0];
    p_syn->tri.plane[0] = c * p_syn->tri.plane[0] - s * p_syn->tri.plane[1];
    p_syn->tri.plane[1] = s * temp + c * p_syn->tri.plane[1]; 
}