NAME = a.out
CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra -Wshadow -Wno-shadow
OBJS = ClapTrap.o main.o ScavTrap.o FragTrap.o DiamondTrap.o

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
