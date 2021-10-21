/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyelee <soyelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:21:52 by dcho              #+#    #+#             */
/*   Updated: 2021/10/18 20:30:34 by soyelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_tlist	*join_spce(t_tlist *token)
{
	t_token	*cur;

	cur = token->head->next;
	while (cur->type != -1)
	{
		if (cur->type == SPCE && cur->next->type == SPCE)
		{
			cur = cur->next;
			remove_token(cur->prev);
			continue ;
		}
		cur = cur->next;
	}
	return (token);
}

static int	core(char **cmdline, t_tlist *list, int num, int len)
{
	char	*str;
	char	*token;

	if (len != 0)
	{
		str = my_malloc(len + 1);
		ft_strlcpy(str, (*cmdline) - len, len + 1);
		add_token(list->tail->prev, str, CHAR);
		len = 0;
	}
	if ((num == LRED || num == RRED) && *((*cmdline) + 1) == TOKEN[num])
	{
		token = my_malloc(3);
		token[0] = TOKEN[num];
		token[1] = TOKEN[num];
		token[2] = '\0';
		add_token(list->tail->prev, token, num + 3);
		(*cmdline)++;
	}
	else
		add_token(list->tail->prev, my_strdup_len(&(TOKEN[num]), 1), num);
	return (len);
}

t_tlist	*tokenizer(char *cmdline)
{
	int		len;
	t_tlist	*list;
	char	*str;
	int		type;

	len = 0;
	list = (t_tlist *)my_malloc(sizeof(t_tlist));
	init_tlist(list);
	while (*cmdline)
	{
		type = my_strchr(TOKEN, *cmdline);
		if (type != -1)
			len = core(&cmdline, list, type, len);
		else
			len++;
		cmdline++;
	}
	if (len != 0)
	{
		str = (char *)my_malloc(len + 1);
		ft_strlcpy(str, cmdline - len, len + 1);
		add_token(list->tail->prev, str, CHAR);
		len = 0;
	}
	return (join_spce(list));
}
