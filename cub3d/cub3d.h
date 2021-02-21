#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "../mlx/mlx.h"

#define PIE (double)3.14
#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480
#define H 480

typedef struct s_syn{
    void *mlx_ptr;
    void *win_ptr;
    t_tri tri;//tri has dda struct...!
    t_img img;
}t_syn;

typedef struct s_tri{
    double pos[2];
    double dir[2];
    double plane[2];
    t_dda dda;
}t_tri;

typedef struct s_dda{//this struct will be included in t_tri struct...!!
    int step_x;
    int step_y;
    int map_x;
    int map_y;
    int side;
    double raydir_x;
    double raydir_y;
    double sidedist_x;
    double sidedist_y;
    double deltadist_x;
    double deltadist_y;
    double walldist; 
}t_dda;

typedef struct image{
    void *img_ptr;
    int *data_ptr;
    int bpp;
    int lenth;
    int endian;
}t_img;

extern int worldMap[mapWidth][mapHeight];