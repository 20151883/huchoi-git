NAME = a.out
CXX = clang++
CXXFLAGS = -Werror -Wextra -Wall
OBJS = WrongAnimal.o  WrongCat.o  WrongDog.o  animal.o  cat.o  dog.o  main.o

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