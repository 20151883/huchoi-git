/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 18:38:13 by soyelee           #+#    #+#             */
/*   Updated: 2021/10/21 00:19:10 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
/* modify */
// # include "readline.h"
//# include "/Users/dcho/.brew/Cellar/readline/8.1/include/readline/readline.h"
//# include "/Users/dcho/.brew/Cellar/readline/8.1/include/readline/history.h"
# include <readline/readline.h>
 # include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/errno.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <curses.h>
# include <term.h>

# define TOKEN		" \'\"$<>|"
# define TRUE		1
# define FALSE		0
# define SUCCESS	1
# define FAILURE	0

typedef struct s_sig
{
	int		is_prompt;
	int		is_parent;
	char	*program;
	int		is_minishell;
	int		is_heredoc;
}	t_sig;

t_sig	g_sig;

enum	e_token
{
	SPCE,
	SINQ,
	DOUQ,
	DOLR,
	LRED,
	RRED,
	PIPE,
	DLRD,
	DRRD,
	CHAR
};

typedef struct s_token
{
	char			*str;
	int				type;
	struct s_token	*prev;
	struct s_token	*next;
}				t_token;

typedef struct s_tlist
{
	t_token	*head;
	t_token	*tail;
}				t_tlist;

typedef struct s_redir
{
	int				count_dlrd;
	char			*filename;
	int				type;
	int				fd;
	int				old_fd;
	struct s_redir	*prev;
	struct s_redir	*next;
}				t_redir;

typedef struct s_rlist
{
	t_redir	*head;
	t_redir	*tail;
}				t_rlist;

typedef struct s_cmd
{
	int				count;
	char			**argv;
	int				argc;
	int				is_pipe;
	int				fd[2];
	int				pid;
	t_token			*token;
	t_rlist			*redir;
	struct s_cmd	*prev;
	struct s_cmd	*next;
}				t_cmd;

typedef struct s_clist
{
	t_cmd	*head;
	t_cmd	*tail;
}				t_clist;

typedef struct s_env
{
	char			*key;
	char			*value;
	int				is_edge;
	int				exitstatus;
	struct s_env	*prev;
	struct s_env	*next;
}				t_env;

typedef struct s_elist
{
	t_env	*head;
	t_env	*tail;
}				t_elist;

typedef struct s_options
{
	char			*cmdline;
	t_tlist			*token;
	t_clist			*cmd;
	t_elist			*env;
	int				*pid;
	int				exit_status;
	char			*minishell_path;
	struct termios	org_term;
	struct termios	new_term;
}				t_options;

/* init.c */
void	init_minishell(t_options *op, char *argv, char **envp);
void	init_prompt(t_options *op);
void	init_pid(t_options *op);

/* execution.c */
void	execution(t_cmd *cmdline, t_elist *env);

/* exec_single.c */
void	exec_single(t_options *op);

/* exec_multi.c */
void	exec_multiple(t_options *op);

/* error.c */
void	print_error_1(char *strerr);
void	print_error_2(char *cmd, char *strerr);
void	print_error_3(char *cmd, char *arg, char *strerr);
void	exit_error_malloc(void);
void	exit_error(char *str);

/* signal.c */
void	signal_main(void);
void	signal_ignore(void);
void	signal_default(void);

/* terminal.c */
void	save_input_mode(struct termios *org_term);
void	set_input_mode(struct termios *new_term);
void	reset_input_mode(struct termios *org_term);

/* loop.c */
int		loop_main(t_options *op);

/* parse_cmd.c */
t_clist	*cmdizer(t_tlist *token);

/* parse_redir.c */
t_rlist	*redir_detector(t_token *token);

/* parse_token.c */
t_tlist	*tokenizer(char *cmdline);

/* utils.c */
int		my_strchr(const char *str, int c);
char	*my_strdup_len(const char *str, int len);
char	*my_malloc(int size);
int		ft_strcmp(const char *s1, const char *s2);
void	free_null(void *address);

/* token_dollar.c */
int		env_name_len(char *str);
void	dolr_detector(t_token **cur, t_elist env, int flag);

/* token_quote.c */
int		sinq_detector(t_token **cur);
int		douq_detector(t_token **cur, t_elist *env);

/* error_token.c */
int		error_token(t_options *op);

/* list_token.c */
void	init_tlist(t_tlist *list);
t_token	*new_token(char *str, int type);
void	add_token(t_token *prev, char *str, int type);
void	del_token(t_token *token);
void	remove_token(t_token *token);
void	remove_cmd(t_cmd *cmd);

/* list_cmd.c */
void	init_clist(t_clist *list);
t_cmd	*init_cmd(t_token *token, int is_pipe);
void	add_cmd(t_cmd *prev, t_token *token, int is_pipe);
void	del_cmd(t_cmd *cmd);

/* list_env.c */
void	init_elist(t_elist *list);
t_env	*new_env(char *key, char *value, int is_edge);
void	add_env(t_env *prev, char *key, char *value);
void	del_env(t_env *env);
void	remove_env(t_env *env);

/* list_redir.c */
void	init_rlist(t_rlist *list);
t_redir	*new_redir(char *fn, int type, int fd);
void	add_redir(t_redir *prev, char *fn, int type, int fd);
void	del_redir(t_redir *redir);
void	remove_redir(t_redir *redir);

/* env.c */
int		count_env(t_elist *env);
t_elist	*set_env(char **envp);
char	**out_env(t_elist *env);
int		env_name_len(char *str);

/* env_sort.c */
t_elist	*sort_env(t_elist *env);

/* builtin.c */
int		builtin(t_options *op, t_cmd *cmd);

/* ft_export.c */
int		ft_export(int argc, char **argv, t_elist *env);

/* ft_echo.c */
void	ft_echo(t_cmd *cmd);

/* ft_cd.c */
int		ft_cd(int argc, char **argv, t_elist *env);

/* ft_env. */
void	ft_env(t_elist *env);

/* ft_exit.c */
int		ft_exit(int argc, char **argv);

/* ft_pwd.c */
void	ft_pwd(void);

/* ft_unset.c */
int		ft_unset(int argc, char **argv, t_elist *env);
char	*add_quote(char *str);
t_env	*search_env(t_elist *env, char *key);

/* redirection.c */
int		redirection(t_rlist *list);
void	unlink_heredoc(t_redir *cur);

/* heredoc.c */
int		heredoc(t_cmd *cmd, t_options *op);

/* free.c */
void	tlist_clean(t_tlist *tlist);
void	rlist_clean(t_rlist *rlist);
void	clist_clean(t_clist *clist);
void	elist_clean(t_elist *elist);
void	free_after_loop(t_options *op);

#endif
