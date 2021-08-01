NAME = test
CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror
OBJS = main.o

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re : fclean $(NAME)
