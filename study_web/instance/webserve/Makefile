NAME = a.out

CXX = clang++
CXXFLAGS = 
OBJS = msg_checker.o client.o  webserv.o

%.o : %.cpp %.hpp
	$(CXX)  -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $^ -o $@

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all