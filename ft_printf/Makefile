NAME = ft_printf.a

SRCS = new_ft_printf.c make_srting.c integer.c not_integer.c utils.c 
OBJS = $(SRCS:.c=.o)
RM = rm -f
.c.o :
	$(CC) $(CLFAG) -c $< -o $(<:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $@ $(OBJS)

clean :
	$(RM) $(OBJS)
fclean :
	$(RM) $(OBJS) $(NAME)