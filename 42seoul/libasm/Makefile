NAME = libasm.a
OBJS = ft_strlen.o ft_strcmp.o ft_strcpy.o ft_write.o ft_read.o  ft_strdup.o
FLAGS = -Wall -Wextra -Werror
%.o : %.s
	nasm -f macho64 $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $@ $(OBJS)
clean : 
	rm -rf $(OBJS) test
fclean : clean
	rm -rf $(NAME)
re: fclean all

test: all
	gcc $(FLAGS) -L. -lasm -o test main.c 
