NAME = replace
CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra
OBJS = main.o

%.o: %.cc %.h
	$(CXX) $(CXXFLAGS) -c $<
all : $(NAME)
$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
clean :
	rm -rf $(OBJS)
fclean : clean
	rm -rf $(NAME)
re : fclean $(NAME)
