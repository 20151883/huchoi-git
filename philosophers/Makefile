NAME = philo
CC = gcc
CXXFLAGS =
#CXXFLAGS = -W -Werror -Wextra -Wall
OBJS = main.o utils.o

%.o: %.c %.h
	$(CC) $(CXXFLAGS) -c $<

all : $(NAME)

$(NAME) : $(OBJS) main.h
	$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)
clean:
	rm -rf $(OBJS)
fclean:clean
	rm -rf $(NAME)
re : fclean $(NAME)
.PHONY: fclean all
