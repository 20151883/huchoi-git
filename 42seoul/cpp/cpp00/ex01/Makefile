NAME = execfile
CC = clang++
CXXFLAGS = -Wall -Werror -Wextra
OBJS = book.o main.o

%.o: %.cc %.h
	$(CC) $(CXXFLAGS) -c $<
all : $(NAME)
$(NAME) : $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)
clean :
	rm -rf $(OBJS)
fclean : clean
	rm -rf $(NAME)
re : fclean $(NAME)
