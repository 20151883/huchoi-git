NAME = ft_printf.a

SRCS = ft_printf_ver4.c make_string.c integer.c not_integer.c utils.c for_printf_utils.c for_printf_utils_ver2.c

OBJS = $(SRCS:.c=.o)

CC = gcc
RM = rm -f
.c.o :
	$(CC) -c $< -o $(<:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcsv $@ $(OBJS)

clean :
	$(RM) $(OBJS)
fclean :
	$(RM) $(OBJS) $(NAME)

re : fclean all
