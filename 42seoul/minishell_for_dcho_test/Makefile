# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcho <dcho@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/02 18:44:32 by dcho              #+#    #+#              #
#    Updated: 2021/10/21 00:19:29 by dcho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

SRCS		= main.c\
			  execution.c\
			  error.c\
			  exec_single.c\
			  exec_multi.c\
			  signal.c\
			  terminal.c\
			  loop.c\
			  list_token.c\
			  list_cmd.c\
			  list_env.c\
			  list_redir.c\
			  parse_cmd.c\
			  parse_token.c\
			  utils.c\
			  token_quote.c\
			  token_dollar.c\
			  error_token.c\
			  env.c\
			  env_sort.c\
			  ft_export.c\
			  ft_unset.c\
			  ft_echo.c\
			  ft_cd.c\
			  ft_exit.c\
			  ft_pwd.c\
			  ft_env.c\
			  builtin.c\
			  redirection.c\
			  heredoc.c\
			  init.c\
			  parse_redir.c\
			  free.c

SRCS_DIR	= ./srcs

SRC			= $(addprefix $(SRCS_DIR),$(SRCS))

OBJS		= $(SRCS:.c=.o)

%.o			: $(SRCS_DIR)/%.c
			@$(CC) $(CFLAGS) -o $@ -c $<

CC			= gcc

# CFLAGS		= -Wall -Wextra -Werror -g3 -fsanitize=address -I ./includes -I ./libft -I/Users/$(USER)/.brew/opt/readline/include
# CFLAGS		= -Wall -Wextra -Werror -I ./includes -I ./libft -I/Users/$(USER)/.brew/opt/readline/include

# Cluster IMAC
# CFLAGS		= -Wall -Wextra -Werror -I ./includes -I ./libft -I /Users/$(USER)/.brew/Cellar/readline/8.1/include/readline
#  CFLAGS		= -Wall -Wextra -Werror -I ./includes -I ./libft -I/Users/$(USER)/.brew/opt/readline/include -I /Users/$(USER)/.brew/Cellar/readline/8.1/include/readline

# MACBOOK 로컬
 CFLAGS		= -Wall -Wextra -Werror -I ./includes -I ./libft #-I/opt/homebrew/opt/readline/include

LIBFT		= ./libft/

# Cluster IMAC
#LDFLAGS		= -L . -L $(LIBFT) -L /Users/$(USER)/.brew/Cellar/readline/8.1/lib
# LDFLAGS		= -L . -L $(LIBFT) -L /Users/$(USER)/.brew/opt/readline/lib -L /Users/$(USER)/.brew/Cellar/readline/8.1/lib

# MACBOOK 로컬
 LDFLAGS		= -L . -L $(LIBFT) #-L /opt/homebrew/opt/readline/lib

RM			= rm -rf

all			: $(NAME)

$(NAME)		: $(OBJS)
			@make -C $(LIBFT) all
			$(CC) $(CFLAGS) $^ \
			$(LDFLAGS) -lft -lreadline\
			-o $@

clean		:
			$(MAKE) -C $(LIBFT) clean
			$(RM) $(OBJS)

fclean		: clean
			$(MAKE) -C $(LIBFT) fclean
			$(RM) $(NAME)

re			: fclean all

.PHONY		: all clean fclean re

