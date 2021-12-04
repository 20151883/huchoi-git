NAME = a.out
CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
OBJS = map.o

%.o : %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

clean : 
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME) 

re : fclean all