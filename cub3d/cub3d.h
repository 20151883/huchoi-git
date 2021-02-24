#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "./mlx.h"
#include <string.h>

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 640
#define H 640

# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_W				13
# define KEY_LEFT			123
# define KEY_DOWN			125
# define KEY_RIGHT			124
#define KEY_ESC             53
# define KEY_UP				126

typedef struct s_tex
{
	void		*ptr;
	int			*data;
	int			width;
	int			height;
	int			size_l;
	int			bpp;
	int			endian;
}t_tex;

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

typedef struct s_tri{//tri has dda structure..!
    void *mlx_ptr;
    void *win_ptr;
    double pos[2];
    double dir[2];
    double plane[2];
    int worldMap[mapWidth][mapHeight];
    t_dda dda;
    t_tex tex[4 + 3];
}t_tri;

typedef struct image{
    void *img_ptr;
    char *data_ptr;
    int bpp;
    int lenth;
    int endian;
}t_img;

typedef struct s_syn{
    t_tri tri;//tri has dda struct...!
    t_img img;
}t_syn;

void renewer_tri(t_tri *test, int *new_pos, int *new_dir);
void get_tri(t_tri *p_tria);
void abs_must_equal_one(t_tri *p_tri);
void change_uclied_vertical(t_tri *p_tri);
void make_line(t_syn *p_syn, int x_pos, int start, int end, int color);
void my_mlx_pixel_put(t_img *p_img, int x, int y, int color);
void dda_loop(t_tri *p_tri);


