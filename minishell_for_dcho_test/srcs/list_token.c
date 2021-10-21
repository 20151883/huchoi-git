/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyelee <soyelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 16:43:41 by soyelee           #+#    #+#             */
/*   Updated: 2021/10/18 19:02:21 by soyelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_tlist(t_tlist *list)
{
	list->head = new_token(NULL, -1);
	list->tail = new_token(NULL, -1);
	list->head->next = list->tail;
	list->tail->prev = list->head;
}

t_token	*new_token(char *str, int type)
{
	t_token	*res;

	res = (t_token *)my_malloc(sizeof(t_token));
	res->str = str;
	res->type = type;
	res->prev = NULL;
	res->next = NULL;
	return (res);
}

void	add_token(t_token *prev, char *str, int type)
{
	t_token	*new;

	new = new_token(str, type);
	new->prev = prev;
	new->next = prev->next;
	prev->next = new;
	new->next->prev = new;
}

void	del_token(t_token *token)
{
	free(token->str);
	token->str = NULL;
	token->type = -1;
	token->prev = NULL;
	token->next = NULL;
	free(token);
	token = NULL;
}

void	remove_token(t_token *token)
{
	token->prev->next = token->next;
	token->next->prev = token->prev;
	del_token(token);
}
