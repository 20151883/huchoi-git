LIBFT = ./libft/libft.a

NAME = libftprintf.a

SRCS =  ft_printf.c make_string.c not_integer.c utils.c\
		 important.c finale.c  utils_ver2.c about_precision.c letter.c\
		 about_star.c integer_signed.c integer_unsigned.c\
		 not_integer_p.c value_is_zero.c
		
OBJS = $(SRCS:.c=.o)

CC = gcc 

FLAGS = -c -W -Wall -Werror

$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(SRCS)
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
