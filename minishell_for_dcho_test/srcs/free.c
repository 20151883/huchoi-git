/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:19:30 by dcho              #+#    #+#             */
/*   Updated: 2021/10/20 17:12:06 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tlist_clean(t_tlist *tlist)
{
	while (tlist->tail->prev != tlist->head)
		remove_token(tlist->tail->prev);
	del_token(tlist->head);
	del_token(tlist->tail);
}

void	rlist_clean(t_rlist *rlist)
{
	while (rlist->tail->prev != rlist->head)
		remove_redir(rlist->tail->prev);
	del_redir(rlist->head);
	del_redir(rlist->tail);
}

void	clist_clean(t_clist *clist)
{
	while (clist->tail->prev != clist->head)
		remove_cmd(clist->tail->prev);
	del_cmd(clist->head);
	del_cmd(clist->tail);
}

void	elist_clean(t_elist *elist)
{
	while (elist->tail->prev != elist->head)
		remove_env(elist->tail->prev);
	del_env(elist->head);
	del_env(elist->tail);
}

void	free_after_loop(t_options *op)
{
	if (op->cmdline != NULL)
	{
		free(op->cmdline);
		op->cmdline = NULL;
	}
	if (op->cmd != NULL)
	{
		clist_clean(op->cmd);
		free(op->cmd);
		op->cmd = NULL;
	}
	if (op->token != NULL)
	{
		tlist_clean(op->token);
		free(op->token);
		op->token = NULL;
	}
	if (op->pid != NULL)
	{
		free(op->pid);
		op->pid = NULL;
	}
}
