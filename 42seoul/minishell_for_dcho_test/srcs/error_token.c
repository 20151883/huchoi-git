/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyelee <soyelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:55:23 by soyelee           #+#    #+#             */
/*   Updated: 2021/10/18 14:39:02 by soyelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	error_token_type(int type)
{
	if (type == LRED)
		ft_putstr_fd("<'\n", 2);
	else if (type == RRED)
		ft_putstr_fd(">'\n", 2);
	else if (type == DLRD)
		ft_putstr_fd("<<'\n", 2);
	else if (type == DRRD)
		ft_putstr_fd(">>'\n", 2);
	else if (type == PIPE)
		ft_putstr_fd("|'\n", 2);
	else if (type == -1)
		ft_putstr_fd("newline'\n", 2);
}

static int	error_token_print(t_token *cur)
{
	int	type;
	int	res;

	res = 0;
	type = cur->type;
	cur = cur->prev;
	if (cur->type == SPCE)
		cur = cur->prev;
	if ((cur->type == LRED || cur->type == RRED
			|| cur->type == DLRD || cur->type == DRRD)
		|| (type == PIPE && (cur->type == PIPE || cur->type == -1)))
	{
		ft_putstr_fd("Minishell: syntax error near unexpected token `", 2);
		error_token_type(type);
		res = 1;
	}
	return (res);
}

int	error_token(t_options *op)
{
	t_token	*cur;
	int		res;

	res = 0;
	cur = op->token->head->next;
	while (1)
	{
		if (cur->type == -1
			|| cur->type == LRED || cur->type == RRED
			|| cur->type == DLRD || cur->type == DRRD
			|| cur->type == PIPE)
		{
			res = error_token_print(cur);
			if (res == 1)
				break ;
		}
		if (cur->type == -1)
			break ;
		cur = cur->next;
	}
	return (res);
}
