NAME = philo
CC = gcc
CFLAGS = -Werror -Wextra -Wall
OBJS = main.o utils.o utils_for_submain.o initialize.o end_point_check.o pthread_create_join.o

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

all : $(NAME)

$(NAME) : $(OBJS) main.h
	$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)
clean:
	rm -rf $(OBJS)
fclean:clean
	rm -rf $(NAME)
re : fclean $(NAME)
.PHONY: fclean all
