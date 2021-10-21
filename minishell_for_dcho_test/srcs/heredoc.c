/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 12:42:47 by soyelee           #+#    #+#             */
/*   Updated: 2021/10/21 00:18:11 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*new_filename_2(t_options *op, char	*num)
{
	char	*path;
	char	*name;

	path = ft_strjoin(op->minishell_path, "/.heredoc_");
	if (path == NULL)
		exit_error_malloc();
	name = ft_strjoin(path, num);
	if (name == NULL)
		exit_error_malloc();
	free(path);
	free(num);
	path = NULL;
	num = NULL;
	return (name);
}

static char	*new_filename(int count_cmd, int count_dlrd, t_options *op)
{
	char	*num_cmd;
	char	*num_dlrd;
	char	*temp;

	num_cmd = ft_itoa(count_cmd);
	num_dlrd = ft_itoa(count_dlrd);
	if (num_cmd == NULL || num_dlrd == NULL)
		exit_error_malloc();
	temp = ft_strjoin(num_cmd, "_");
	if (temp == NULL)
		exit_error_malloc();
	free(num_cmd);
	num_cmd = temp;
	temp = ft_strjoin(temp, num_dlrd);
	if (temp == NULL)
		exit_error_malloc();
	free_null(num_cmd);
	free_null(num_dlrd);
	return (new_filename_2(op, temp));
}

static int	buf_readline(t_redir *red, char *delimiter)
{
	char	*buf;

	buf = readline("> ");
	if (buf == NULL)
	{
		ft_putchar_fd('\0', red->fd);
		return (-1);
	}
	if (!(ft_strcmp(buf, delimiter)))
	{
		free(buf);
		return (-1);
	}
	ft_putstr_fd(buf, red->fd);
	ft_putchar_fd('\n', red->fd);
	free(buf);
	return (1);
}

static int	read_heredoc(t_redir *red, char *filename)
{
	int		res;
	char	*delimiter;

	delimiter = red->filename;
	red->filename = filename;
	g_sig.is_heredoc = TRUE;
	red->fd = open(red->filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (red->fd == -1)
	{
		perror("heredoc open error");
		return (FAILURE);
	}
	while (1)
	{
		res = buf_readline(red, delimiter);
		if (res == FAILURE)
			return (FAILURE);
		else if (res == -1)
			break ;
	}
	close(red->fd);
	free(delimiter);
	return (SUCCESS);
}

int	heredoc(t_cmd *cmd, t_options *op)
{
	t_redir	*cur;
	char	*newname;

	while (cmd->is_pipe != -1)
	{
		cur = cmd->redir->head->next;
		while (cur->filename)
		{
			if (cur->type == DLRD)
			{
				newname = new_filename(cmd->count, cur->count_dlrd, op);
				if (read_heredoc(cur, newname) == FAILURE)
					return (FAILURE);
			}
			cur = cur->next;
		}
		cmd = cmd->next;
	}
	return (TRUE);
}
