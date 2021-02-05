LIBFT = ./libft/libft.a

N_TEMP = temp.a

NAME = libftprintf.a

SRCS =  ft_printf_ver6.c make_string.c integer.c not_integer.c utils.c\
		 for_printf_utils.c for_printf_utils_ver2.c 
		

		
OBJS = $(SRCS:.c=.o)

CC = gcc 

FLAGS = -c -W -Wall -Werror

INCLUDES = -I./includes

$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(SURPL_O) 
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all
