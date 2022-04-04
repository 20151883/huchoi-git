/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyelee <soyelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:02:40 by soyelee           #+#    #+#             */
/*   Updated: 2021/10/18 18:07:45 by soyelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	sinq_detector(t_token **cur)
{
	if ((*cur)->type == (*cur)->next->type)
	{
		add_token((*cur), my_strdup_len("", 0), CHAR);
		*cur = (*cur)->next;
		remove_token((*cur)->prev);
		remove_token((*cur)->next);
		return (SUCCESS);
	}
	(*cur) = (*cur)->next;
	remove_token((*cur)->prev);
	while ((*cur)->type != SINQ && (*cur)->type != -1)
	{
		(*cur)->type = CHAR;
		(*cur) = (*cur)->next;
	}
	if ((*cur)->type == -1)
		return (FAILURE);
	(*cur) = (*cur)->next;
	remove_token((*cur)->prev);
	return (SUCCESS);
}

int	douq_detector(t_token **cur, t_elist *env)
{
	if ((*cur)->type == (*cur)->next->type)
	{
		add_token((*cur), my_strdup_len("", 0), CHAR);
		*cur = (*cur)->next;
		remove_token((*cur)->prev);
		remove_token((*cur)->next);
		return (SUCCESS);
	}
	(*cur) = (*cur)->next;
	remove_token((*cur)->prev);
	while ((*cur)->type != DOUQ && (*cur)->type != -1)
	{
		if ((*cur)->type != DOLR)
			(*cur)->type = CHAR;
		else
			dolr_detector(cur, *env, DOUQ);
		(*cur) = (*cur)->next;
	}
	if ((*cur)->type == -1)
		return (FAILURE);
	(*cur) = (*cur)->next;
	remove_token((*cur)->prev);
	return (SUCCESS);
}
