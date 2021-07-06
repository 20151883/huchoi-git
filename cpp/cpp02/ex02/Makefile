NAME = a.out
#CXX = clang++
CXX = g++
CXXFLAGS = -Wall -Werror -Wextra
OBJS = main.o Fixed.o
%.o: %.cc %.h
	$(CXX) $(CXXFLAGS) -c $<

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
clean :
	rm -rf $(OBJS)
fclean : clean
	rm -rf $(NAME)
re : fclean $(NAME)
