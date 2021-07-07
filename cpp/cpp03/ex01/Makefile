NAME = a.out
CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra
OBJS = ClapTrap.o main.o ScavTrap.o

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $<
all : $(NAME)
$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
clean :
	rm -rf $(OBJS)
fclean : clean
	rm -rf $(NAME)
re : fclean $(NAME)
