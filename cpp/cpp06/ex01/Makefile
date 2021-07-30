NAME = a.out
CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra
OBJS = Serialization.o main.o

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $<
$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
clean :
	rm -rf $(OBJS)
fclean : clean
	rm -rf $(NAME)
re : fclean $(NAME)
