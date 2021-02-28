#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "./mlx.h"
#include <string.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h>
#include <unistd.h>
//#define screenWidth p_syn->R[0]
//#define screenHeight p_syn->R[1]
#define H p_syn->R[1]

# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_W				13
# define KEY_LEFT			123
# define KEY_DOWN			125
# define KEY_RIGHT			124
#define KEY_ESC             53
# define KEY_UP				126
#define KEY_1               18

typedef struct Sprite
{
  double x;
  double y;
  //int texture;//this must be the 4...!!
}Sprite;

typedef struct s_tex
{
	void		*ptr;
	int			*data;
	int			width;
	int			height;
	int			size_l;
	int			bpp;
	int			endian;
    char        *path;
}t_tex;

typedef struct s_dda{//this struct will be included in t_tri struct...!!
    int         step_x;
    int         step_y;
    int         map_x;
    int         map_y;
    int         side;
    double      raydir_x;
    double      raydir_y;
    double      sidedist_x;
    double      sidedist_y;
    double      deltadist_x;
    double      deltadist_y;
    double      walldist; 
}t_dda;

typedef struct s_tri{//tri has dda structure..!
    void    *mlx_ptr;
    void    *win_ptr;
    double  pos[2];
    double  dir[2];
    double  plane[2];
    //int worldMap[mapWidth][mapHeight];
    int     **test_map;
    t_dda   dda;
    t_tex   tex[4 + 1];//tex[4+1] is correct!!
}t_tri;

typedef struct image{
    void    *img_ptr;
    char    *data_ptr;
    int     bpp;
    int     lenth;
    int     endian;
}t_img;

typedef struct s_syn{
    t_tri   tri;//tri has dda struct...!
    t_img   img;
    int     dir_alpha_is_exist;
    int     c_color;
    int     f_color;
    double  **sprites;
    int     R[2];
    int     num_of_sprite;
    double  *ZBuffer;
    int     drawStart;
    int     drawEnd;
    int     color;
    double  spriteX;
    double  spriteY;
    double  invDet;
    double  transformX;
    double  transformY;
    int     spriteScreenX;
    int     spriteHeight;
    int     drawStartY;
    int     drawEndY;
    int     spriteWidth;
    int     drawStartX;
    int     drawEndX;
    int     stripe;
    int     texX;
    int     y;
    int     d;
    int     texY;
    double  *spriteDistance;
    int     lineHeight;
    //int texX;
    double step;
    double wallX; //where exactly the wall was hit
    double texPos;
    //Sprite *sprite;
    //int texY;
}t_syn;

void ft_mergesort(t_syn *p_syn, double **arr, int start, int end);

void ctrl_pos(int keycode, t_syn *p_syn);
void pos_WS(t_syn*p_syn, double weight);
void pos_AD(t_syn *p_syn, double weight);
void ctrl_dir(int keycode, t_syn *p_syn);
void rotate_dir(t_syn *p_syn, double theta);

void load_texture_sprite(t_tri *p_tri, int idx);
int par(t_syn *p_syn);
int get_end(char *buf, int start, int *p_flag);
int check_first(char *buf, int *p_flag);
int check_num_part(char *cur,char *before, int start, int end);
int get_start(char *buf,char *before, int end);
int is_valid_map(int fd, t_syn *p_syn);

void make_block(t_syn *p_syn, int *p_idx, int i);
void make_sprite(t_syn *p_syn);
void init_tri(t_syn *p_syn);
void dda_init(t_tri *p_tri);
void dda_init_second(t_tri *p_tri);
void before_make_texture(t_syn *p_syn, int *p_idx);
void renewer_tri(t_tri *test, int *new_pos, int *new_dir);
void get_tri(t_tri *p_tria);
void abs_must_equal_one(t_tri *p_tri);
void change_uclied_vertical(t_tri *p_tri);
void make_line(t_syn *p_syn, int x_pos, int start, int end, int color);
void my_mlx_pixel_put(t_img *p_img, int x, int y, int color);
void dda_loop(t_tri *p_tri);
void news(t_syn *p_syn, int *p_idx);

