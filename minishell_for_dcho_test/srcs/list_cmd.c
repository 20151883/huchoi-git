/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyelee <soyelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:56:20 by dcho              #+#    #+#             */
/*   Updated: 2021/10/20 02:09:36 by soyelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_clist(t_clist *list)
{
	list->head = init_cmd(NULL, -1);
	list->tail = init_cmd(NULL, -1);
	list->head->next = list->tail;
	list->tail->prev = list->head;
}

t_cmd	*init_cmd(t_token *token, int is_pipe)
{
	t_cmd	*res;

	res = (t_cmd *)my_malloc(sizeof(t_cmd));
	res->argv = NULL;
	res->token = token;
	res->is_pipe = is_pipe;
	res->prev = NULL;
	res->next = NULL;
	res->pid = -1;
	res->redir = NULL;
	return (res);
}

void	add_cmd(t_cmd *prev, t_token *token, int is_pipe)
{
	t_cmd	*new;

	new = init_cmd(token, is_pipe);
	new->next = prev->next;
	new->prev = prev;
	prev->next->prev = new;
	prev->next = new;
}

void	del_cmd(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd->argv != NULL)
	{
		while (cmd->argv[i] != NULL)
		{
			free(cmd->argv[i]);
			cmd->argv[i++] = NULL;
		}
		free(cmd->argv);
		cmd->argv = NULL;
	}
	cmd->token = NULL;
	if (cmd->redir != NULL)
	{
		rlist_clean(cmd->redir);
		free(cmd->redir);
		cmd->redir = NULL;
	}
	cmd->prev = NULL;
	cmd->next = NULL;
	free(cmd);
	cmd = NULL;
}

void	remove_cmd(t_cmd *cmd)
{
	cmd->next->prev = cmd->prev;
	cmd->prev->next = cmd->next;
	del_cmd(cmd);
}
