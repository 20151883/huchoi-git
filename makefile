NAME = libft.h
FILES =ft_memmove.c\  
	ft_memset.c \ 
	ft_isalnum.c \ 
	ft_toupper.c  \
	ft_strnstr.c  \
	ft_strncmp.c  \
	ft_isascii.c  \
	ft_bzero.c   \
	ft_isprint.c  \
	ft_atoi.c     \
	ft_strchr.c   \
	ft_tolower.c\
	ft_memchr.c  \            
	ft_isalpha.c  \
	ft_memccpy.c  \
	ft_memcmp.c    \        
	ft_isdigit.c  \
	ft_strlen.c  \
	ft_memcpy.c   \
	ft_strlcpy.c  \
	ft_strlcat.c  \
	ft_strrchr.c\
	ft_strjoin.c \ 
	ft_substr.c  \
	ft_split.c    \
	ft_putchar_fd.c\  
	test.txt  \
	ft_putnbr_f\d.c\  
	ft_putstr.c \ 
	ft_strmapi.c \ 
	ft_strtrim.c  \ 
	ft_putendl_fd.c\  
	ft_itoa.c\
BOUNUS = ft_lstlas\t.c  \
	ft_lstmap.c\  
	ft_lstclear.c  \
	ft_lstsize.c  \
	ft_lstadd_back.c \   
	ft_lstadd_front.\c  
	ft_lstdelone.c  \
	ft_lstnew.c  \
	ft_lstiter.c  \

CC = gcc
CFLAGS = -Wall -Werror -Wextra

OBJS = ${FILES:.c=.o}
BONUS_OBJ = ${BONUS:.c=.o}


RM = rm -rf

.c.o:
	CC CFLAGS -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS} 

clean :
	${RM} *.0

fclean : clean
	${RM}*.c

re : fclean all

.PHONY : all clean fclean re
