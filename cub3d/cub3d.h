/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:16:41 by huchoi            #+#    #+#             */
/*   Updated: 2021/04/02 17:30:19 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <math.h>
# include <stdlib.h>
# include "mlx/mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "get_next_line.h"
# include "Libft/libft.h"
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_W		13
# define KEY_LEFT	123
# define KEY_DOWN	125
# define KEY_RIGHT	124
# define KEY_ESC	53
# define KEY_UP		126
# define KEY_1		18

typedef	struct	s_tex
{
	void		*ptr;
	int			*data;
	int			width;
	int			height;
	int			size_l;
	int			bpp;
	int			endian;
	char		*path;
}				t_tex;

typedef	struct	s_dda
{
	int			step_x;
	int			step_y;
	int			map_x;
	int			map_y;
	int			side;
	double		raydir_x;
	double		raydir_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	double		walldist;
}				t_dda;

typedef	struct	s_tri
{
	void		*mlx_ptr;
	void		*win_ptr;
	double		pos[2];
	double		dir[2];
	double		plane[2];
	int			**test_map;
	t_dda		dda;
	t_tex		tex[4 + 1];
}				t_tri;

typedef struct	s_bmp{
	int				size;
	char			*img;
	int				fd;
	unsigned char	header[14];
	unsigned char	info[40];
	unsigned char	color[4];
}				t_bmp;

typedef	struct	s_image
{
	void		*img_ptr;
	char		*data_ptr;
	int			bpp;
	int			lenth;
	int			endian;
}				t_img;

typedef	struct	s_syn
{
	t_tri		tri;
	t_img		img;
	int			so_flag;
	int			no_flag;
	int			ea_flag;
	int			we_flag;
	int			s_flag;
	int			r_flag;
	int			c_flag;
	int			f_flag;
	int			dir_alpha_is_exist;
	int			c_color;
	int			f_color;
	double		**sprites;
	int			r[2];
	int			num_of_sprite;
	double		*zbuffer;
	int			drawstart;
	int			drawend;
	int			color;
	double		spritex;
	double		spritey;
	double		invdet;
	double		transformx;
	double		transformy;
	int			spritescreenx;
	int			spriteheight;
	int			drawstarty;
	int			drawendy;
	int			spritewidth;
	int			drawstartx;
	int			drawendx;
	int			stripe;
	int			texx;
	int			y;
	int			d;
	int			texy;
	double		*spritedistance;
	int			lineheight;
	double		step;
	double		wallx;
	double		texpos;
	int			bmp_flag;
	char		*cub_path;
}				t_syn;

void			check_lines(int nb, char *buf, int count);
void			init_flags(t_syn *p_syn);
void			par_the_line(t_syn *p_syn, char **split, char *buf);
char			**my_split(char const *s1, char *deli);
void			sort_sprites(t_syn *p_syn);
void			init_for_sprite(t_syn *p_syn, int i);
void			make_under(t_syn *p_syn);
void			make_over(t_syn *p_syn);
void			ft_bitmap(t_syn *s);
int				key_func(int keycode, t_syn *p_syn);
int				main_loop(t_syn *p_syn);
int				**renewer_map(t_syn *p_syn, int **map, char *add_line);
void			get_first(int fd, char **cur_buf);
int				valid_check(t_syn *p_syn, char **p_cur_buf, \
				char **p_before_buf, int flag);
int				get_last(t_syn *p_syn, char *cur_buf, \
				char *before_buf, int ret);
int				check_last(char *buf);
void			get_dir(t_syn *p_syn, int idx, char *add_line);
int				renewer_sprites(t_syn *p_syn, int size, int idx);
void			make_new_map(int **new_map, int **map, int *new_line, \
				int size);
void			manage_news_sprite(t_syn *p_syn, char *add_line, \
				int size, int idx);
void			ft_mergesort(t_syn *p_syn, double **arr, int start, int end);
void			ft_merge(t_syn *p_syn, double **arr, int start, int end);
int				is_valid_path(char *path);
int				case_by_lenth(char **split, t_syn *p_syn, int lenth);
int				is_valid_path(char *path);
int				is_valid_color(char **split);
void			check_flag(t_syn *p_syn);
int				check_news_sprite(char **split, t_syn *p_syn);
int				check_r(char **split, t_syn *p_syn);
int				check_f_c(char **split, t_syn *p_syn);
void			message_exit(void);
int				is_only_zero_blank_one(char *arr);
void			t_mergesort(t_syn *p_syn, double **arr, int start, int end);
void			ctrl_pos(int keycode, t_syn *p_syn);
void			pos_ws(t_syn*p_syn, double weight);
void			pos_ad(t_syn *p_syn, double weight);
void			ctrl_dir(int keycode, t_syn *p_syn);
void			rotate_dir(t_syn *p_syn, double theta);
void			load_texture_sprite(t_tri *p_tri, int idx);
void			par(t_syn *p_syn);
int				get_end(char *buf, int start, int *p_flag);
int				check_first(char *buf);
int				check_num_part(char *cur, char *before, int start, int end);
int				get_start(char *buf, char *before, int end);
int				is_valid_map(int fd, t_syn *p_syn);
void			make_block(t_syn *p_syn, int *p_idx, int i);
void			make_sprite(t_syn *p_syn);
void			init_tri(t_syn *p_syn);
void			dda_init(t_tri *p_tri);
void			dda_init_second(t_tri *p_tri);
void			before_make_texture(t_syn *p_syn);
void			renewer_tri(t_tri *test, int *new_pos, int *new_dir);
void			get_tri(t_tri *p_tria);
void			abs_must_equal_one(t_tri *p_tri);
void			change_uclied_vertical(t_tri *p_tri);
void			make_line(t_syn *p_syn, int x_pos, int start, \
				int end, int color);
void			my_mlx_pixel_put(t_img *p_img, int x, int y, int color);
void			dda_loop(t_tri *p_tri);
void			news(t_syn *p_syn, int *p_idx);
#endif
