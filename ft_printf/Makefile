NAME = libftprintf.a

SRCS = new_ft_printf.c make_string.c integer.c not_integer.c utils.c 

OBJS = $(SRCS:.c=.o)

SUBOBJS = ./*.o
CC = gcc
RM = rm -f
.c.o :
	$(CC) -c $< -o $(<:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) SUB
	ar rcsv $@ $(SUBOBJS) $(OBJS)

SUB : 
	cd libft ; $(MAKE)
clean :
	$(RM) $(OBJS)
fclean :
	$(RM) $(OBJS) $(NAME)
re : fclean all
