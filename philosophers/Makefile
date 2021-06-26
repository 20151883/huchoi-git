NAME = philosophers
CC = gcc
CXXFLAGS =
#CXXFLAGS = -W -Werror -Wextra -Wall
OBJS = main.o

%.o: %.c %.h
	$(CC) $(CXXFLAGS) -c $<

$(NAME) : $(OBJS) main.h
	$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)

.PHONY: clean
clean:
	rm -f $(OBJS) main

