/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_multi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 21:10:12 by dcho              #+#    #+#             */
/*   Updated: 2021/10/20 20:54:06 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exec_multi_parent(t_cmd *cur)
{
	if (cur->prev->is_pipe == 1)
		close(cur->prev->fd[0]);
	if (cur->next->is_pipe == 1)
		close(cur->fd[1]);
}

static void	exec_multi_child(t_options *op, t_cmd *cur)
{
	int		is_builtin;

	if (cur->prev->is_pipe == 1)
	{
		close(cur->prev->fd[1]);
		dup2(cur->prev->fd[0], 0);
	}
	if (cur->next->is_pipe == 1)
	{
		close(cur->fd[0]);
		dup2(cur->fd[1], 1);
	}
	if (redirection(cur->redir) != 0)
		exit(1);
	is_builtin = builtin(op, cur);
	if (is_builtin != -1)
		exit(is_builtin);
	else
		execution(cur, op->env);
}

static void	after_waitpid(t_options *op)
{
	t_cmd	*cur;

	cur = op->cmd->head->next;
	while (cur->pid != -1)
	{
		waitpid(cur->pid, &op->exit_status, 0);
		unlink_heredoc(cur->redir->head->next);
		cur = cur->next;
	}
	op->exit_status = WEXITSTATUS(op->exit_status);
}

void	exec_multiple(t_options *op)
{
	t_cmd	*c_cur;
	int		i;

	i = 0;
	c_cur = op->cmd->head->next;
	while (c_cur->is_pipe != -1)
	{
		if (c_cur->next->is_pipe != -1)
			pipe(c_cur->fd);
		c_cur->pid = fork();
		op->pid[i++] = c_cur->pid;
		g_sig.is_parent = op->pid[i - 1];
		g_sig.is_prompt = FALSE;
		signal_main();
		if (c_cur->pid == 0)
			exec_multi_child(op, c_cur);
		else
			exec_multi_parent(c_cur);
		c_cur = c_cur->next;
	}
	after_waitpid(op);
}
