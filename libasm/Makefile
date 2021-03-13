NAME = test.a
SRCS = ft_strcmp.s
OBJS = $(SRCS:.s=.o)
%.o : %.s
	nasm -f macho64 $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	nasm -f macho64 $(SRCS)
	ar -rcs $@ $(OBJS)
	gcc main.c $@
