LIBFT = ./libft/libft.a

NAME = cub3D

SRCS =  main.c ttri_dda.c ttri_to_dda.c map.c par.c key_ctrl.c \
	utils_for_par.c utils_for_par_2.c base_func.c utils_for_map.c utils_for_map_2.c \
	main_loop.c make_bmp.c make_image.c make_sprites.c make_sprites_utils.c make_texture.c \
	get_next_line.c get_next_line_utils.c tri_dda_init.c utils_for_par_3.c

OBJS = $(SRCS:.c=.o)
CFLAGS = -W -Wall -Werror -Wextra
CC = gcc 

FLAGS = -W -Wall -Wextra -Werror -L./mlx -lmlx -framework OpenGL -framework AppKit

$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a ./libft.a
	$(CC) $(FLAGS) $(OBJS) libft.a -o $(NAME)

all : $(NAME)

bonus : all

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(SURPL_O) 
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all
