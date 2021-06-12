CC = g++
CXXFLAGS = -Wall -O2
OBJS = megaphone.o
NAME = megaphone
%.o: %.cc %.h
	$(CC) $(CXXFLAGS) -c $<

$(NAME) : $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)
clean :
	rm -rf $(OBJS)
fclean : clean
	rm -rf $(NAME)
re : fclean $(NAME)
