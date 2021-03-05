all:
	gcc -L./mlx -lmlx -framework OpenGL -framework AppKit main.c TRI_dda.c tri_to_DDA.c utils.c map.c par.c libft.a get_next_line.c key_ctrl.c \
	utils_for_par.c base_func.c utils_for_map.c utils_for_map_2.c

LIBFT = ./libft/libft.a

NAME = cub3D

SRCS =  main.c TRI_dda.c tri_to_DDA.c utils.c map.c par.c get_next_line.c key_ctrl.c \
	utils_for_par.c utils_for_par_2.c base_func.c utils_for_map.c utils_for_map_2.c \
	main_loop.c make_bmp.c make_image.c make_sprites.c make_sprites_utils.c make_texture.c 

OBJS = $(SRCS:.c=.o)

CC = gcc 

FLAGS = -W -Wall -Werror -L./mlx -lmlx -framework OpenGL -framework AppKit

$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a ./libft
	$(CC) $(FLAGS) $(OBJS) libft.a -o $(NAME)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(SURPL_O) 
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all
