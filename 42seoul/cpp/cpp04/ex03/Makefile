NAME = a.out
CXX = clang++
CXXFLAGS = -Werror -Wextra -Wall
OBJS = AMateria.o Character.o Cure.o Ice.o MateriaSource.o main.o

%.o : %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean :
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)
re : fclean all