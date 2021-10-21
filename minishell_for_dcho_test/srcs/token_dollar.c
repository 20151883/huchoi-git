/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_dollar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:02:33 by soyelee           #+#    #+#             */
/*   Updated: 2021/10/20 17:14:32 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*key_to_str(t_elist env, char *key)
{
	t_env	*cur;

	cur = env.head->next;
	while (!(cur->is_edge))
	{
		if (!(ft_strcmp(key, cur->key)))
			return (my_strdup_len(cur->value, ft_strlen(cur->value)));
		cur = cur->next;
	}
	return (my_strdup_len("", 0));
}

static int	exit_status(t_token *cur, t_elist env)
{
	char	*exitstat;
	char	*leftover;
	char	*result;

	result = NULL;
	if (*(cur->str) == '?')
	{
		exitstat = ft_itoa(env.head->exitstatus);
		if (ft_strlen(cur->str) > 1)
		{
			leftover = my_strdup_len(cur->str + 1, ft_strlen(cur->str - 1));
			result = ft_strjoin(exitstat, leftover);
			if (result == NULL)
				exit_error_malloc();
			free_null(exitstat);
			free_null(leftover);
		}
		else
			result = exitstat;
		free(cur->str);
		cur->str = result;
		remove_token(cur->prev);
		return (TRUE);
	}
	return (FALSE);
}

static int	detector_core(t_token *cur, t_elist env)
{
	int		str_len;
	int		key_len;
	char	*key;

	if (exit_status(cur, env))
		return (0);
	str_len = ft_strlen(cur->str);
	key_len = env_name_len(cur->str);
	if (key_len)
		remove_token(cur->prev);
	else
	{
		cur->prev->type = CHAR;
		return (0);
	}
	if (str_len != key_len)
		add_token(cur, my_strdup_len(cur->str \
		+ key_len, str_len - key_len), CHAR);
	key = my_strdup_len(cur->str, key_len);
	free(cur->str);
	cur->str = key_to_str(env, key);
	free(key);
	key = NULL;
	return (1);
}

void	dolr_detector(t_token **cur, t_elist env, int flag)
{
	if (flag != DOUQ && ((*cur)->next->type == SINQ \
	|| (*cur)->next->type == DOUQ))
		remove_token((*cur));
	else if ((*cur)->next->type == CHAR)
	{
		(*cur) = (*cur)->next;
		if (!(detector_core(*cur, env)))
			return ;
	}
	else
		(*cur)->type = CHAR;
}
