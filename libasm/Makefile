NAME = test.a
OBJS = ft_strlen.o ft_strcmp.o ft_strcpy.o ft_write.o ft_read.o  ft_strdup.o
%.o : %.s
	nasm -f macho64 $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $@ $(OBJS)
	gcc main.c $@
clean : 
	rm -rf $(OBJS)
fclean : clean
	rm -rf $(NAME)
re: fclean all
