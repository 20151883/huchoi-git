NAME = convert
CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra
OBJS = cast.o

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@
clean :
	rm -rf $(OBJS)
fclean : clean
	rm -rf $(NAME)
re : fclean $(NAME)
