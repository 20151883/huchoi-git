/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 20:11:06 by dcho              #+#    #+#             */
/*   Updated: 2021/10/20 17:38:38 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_rlist(t_rlist *list)
{
	list->head = new_redir(NULL, -1, -1);
	list->tail = new_redir(NULL, -1, -1);
	list->head->next = list->tail;
	list->tail->prev = list->head;
}

t_redir	*new_redir(char *fn, int type, int fd)
{
	t_redir	*res;

	res = (t_redir *)my_malloc(sizeof(t_redir));
	res->filename = fn;
	res->type = type;
	res->fd = fd;
	res->old_fd = 0;
	res->count_dlrd = 0;
	res->prev = NULL;
	res->next = NULL;
	return (res);
}

void	add_redir(t_redir *prev, char *fn, int type, int fd)
{
	t_redir	*new;

	new = new_redir(fn, type, fd);
	new->prev = prev;
	new->next = prev->next;
	prev->next = new;
	new->next->prev = new;
}

void	del_redir(t_redir *redir)
{
	if (redir->filename != NULL)
	{
		if (redir->type == DLRD)
			unlink(redir->filename);
		free(redir->filename);
		redir->filename = NULL;
	}
	redir->type = -1;
	redir->prev = NULL;
	redir->next = NULL;
	free (redir);
	redir = NULL;
}

void	remove_redir(t_redir *redir)
{
	redir->prev->next = redir->next;
	redir->next->prev = redir->prev;
	del_redir(redir);
}
