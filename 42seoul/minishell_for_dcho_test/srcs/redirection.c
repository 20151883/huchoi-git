/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:56:16 by dcho              #+#    #+#             */
/*   Updated: 2021/10/20 17:18:39 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	redirection_type(t_redir *red)
{
	if (red->type == RRED)
		red->fd = open(red->filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (red->type == DRRD)
		red->fd = open(red->filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		red->fd = open(red->filename, O_RDONLY);
	if (red->fd == -1)
	{
		print_error_1(red->filename);
		return (errno);
	}
	return (0);
}

static void	redir_dup(t_redir *red)
{
	int	redir[2];

	redir[0] = 0;
	redir[1] = 0;
	while (red->type != -1)
	{
		if (redir[0] == 0 && (red->type == DLRD || red->type == LRED))
		{
			red->old_fd = dup(0);
			dup2(red->fd, 0);
			redir[0] = 1;
		}
		else if (redir[1] == 0 && (red->type == DRRD || red->type == RRED))
		{
			red->old_fd = dup(1);
			dup2(red->fd, 1);
			redir[1] = 1;
		}
		if (redir[0] && redir[1])
			return ;
		red = red->prev;
	}
}

static void	redir_close(t_redir *cur)
{
	cur = cur->prev;
	while (cur->type != -1)
	{
		close(cur->fd);
		cur = cur->prev;
	}
}

int	redirection(t_rlist *list)
{
	t_redir	*cur;
	int		res_errno;

	cur = list->head->next;
	res_errno = 0;
	while (cur->type != -1)
	{
		res_errno = redirection_type(cur);
		if (res_errno)
		{
			redir_close(cur);
			return (res_errno);
		}
		cur = cur->next;
	}
	redir_dup(list->tail->prev);
	return (res_errno);
}

void	unlink_heredoc(t_redir *cur)
{
	while (cur->filename)
	{
		if (cur->type == DLRD)
			unlink(cur->filename);
		cur = cur->next;
	}
}
