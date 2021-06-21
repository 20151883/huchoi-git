CC = clang++
CXXFLAGS = -Wall -Werror -Wextra
OBJS = Base.o main.o

%.o: %.cc %.h
	$(CC) $(CXXFLAGS) -c $<
test : $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o test
clean :
	rm -rf $(OBJS)
fclean : clean
	rm -rf test
re : fclean test
