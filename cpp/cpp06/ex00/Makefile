CC = clang++
CXXFLAGS = -Wall -Werror -Wextra -W
OBJS = cast.o

%.o: %.cc %.h
	$(CC) $(CXXFLAGS) -c $<
convert : $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o convert
clean :
	rm -rf $(OBJS)
fclean : clean
	rm -rf convert
re : fclean convert
