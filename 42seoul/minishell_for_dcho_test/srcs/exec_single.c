/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_single.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyelee <soyelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 21:10:14 by dcho              #+#    #+#             */
/*   Updated: 2021/10/20 03:30:15 by soyelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	redir_close(t_redir *cur)
{
	int		redir[2];

	redir[0] = 0;
	redir[1] = 0;
	while (cur->type != -1)
	{
		close(cur->fd);
		if ((cur->type == LRED || cur->type == DLRD) && !(redir[0]))
		{
			redir[0] = 1;
			dup2(cur->old_fd, 0);
			close(cur->old_fd);
		}
		if ((cur->type == RRED || cur->type == DRRD) && !(redir[1]))
		{
			redir[1] = 1;
			dup2(cur->old_fd, 1);
			close(cur->old_fd);
		}
		cur = cur->prev;
	}
}

static void	exec_single_core(t_options *op, t_cmd *cur)
{
	cur->pid = fork();
	op->pid[0] = cur->pid;
	g_sig.is_parent = op->pid[0];
	g_sig.is_prompt = FALSE;
	signal_main();
	if (cur->pid == 0)
		execution(cur, op->env);
	else
	{
		if (!(ft_strcmp(cur->argv[0], g_sig.program)))
			g_sig.is_minishell = TRUE;
		waitpid(*op->pid, &op->exit_status, 0);
		op->exit_status = WEXITSTATUS(op->exit_status);
	}
}

static int	cmdline_only_space(char *cmdline)
{
	int	i;

	i = 0;
	while (cmdline[i] && cmdline[i] == ' ')
		i++;
	if (cmdline[i] == '\0')
		return (TRUE);
	return (FALSE);
}

void	exec_single(t_options *op)
{
	t_cmd	*c_cur;
	int		result;

	c_cur = op->cmd->head->next;
	if (cmdline_only_space(op->cmdline))
		return ;
	if (redirection(c_cur->redir) == 0)
	{
		result = builtin(op, op->cmd->head->next);
		if (result == -1)
			exec_single_core(op, c_cur);
		else
			op->exit_status = result;
		redir_close(c_cur->redir->tail->prev);
	}
	else
		op->exit_status = 1;
	unlink_heredoc(c_cur->redir->head->next);
}
