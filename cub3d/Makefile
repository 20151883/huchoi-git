##all:
##	gcc -L./mlx -lmlx -framework OpenGL -framework AppKit main.c TRI_dda.c tri_to_DDA.c utils.c map.c par.c libft.a get_next_line.c key_ctrl.c \
	utils_for_par.c base_func.c utils_for_map.c utils_for_map_2.c
##./a.out

CC = gcc
CFLAGS = -L./mlx -lmlx -framework OpenGL -framework AppKit

SRCS = main.c TRI_dda.c tri_to_DDA.c utils.c map.c par.c utils_for_map.c utils_for_map_2.c \
	   utils_for_par.c base_func.c \
	   get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

NAME = CUB3D

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./Libft
	cp ./libft.a ./lift.a
	$(CC) $(CLFAG) -o $@ $(OBJS)
