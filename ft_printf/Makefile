NAME = libftprintf.a

SRCS = new_ft_printf.c make_string.c integer.c not_integer.c utils.c 

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
