/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyelee <soyelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:11:44 by dcho              #+#    #+#             */
/*   Updated: 2021/10/20 04:09:19 by soyelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_elist	*envcpy(t_elist *env)
{
	t_elist	*res;
	t_env	*cur;
	char	*new_key;
	char	*new_value;

	res = (t_elist *)my_malloc(sizeof(t_elist));
	init_elist(res);
	cur = env->head->next;
	while (!(cur->is_edge))
	{
		new_key = ft_strdup(cur->key);
		new_value = ft_strdup(cur->value);
		if (new_key == NULL || new_value == NULL)
			exit_error_malloc();
		add_env(res->tail->prev, new_key, new_value);
		cur = cur->next;
	}
	return (res);
}

static void	swap(t_env *e1, t_env *e2)
{
	t_env	*tmp;

	tmp = new_env(e2->key, e2->value, FALSE);
	e2->key = e1->key;
	e2->value = e1->value;
	e1->key = tmp->key;
	e1->value = tmp->value;
	free(tmp);
	tmp = NULL;
}

static void	print_env(t_elist *env)
{
	t_env	*cur;

	cur = env->head->next;
	while (!(cur->is_edge))
	{
		ft_putstr_fd("export ", 1);
		ft_putstr_fd(cur->key, 1);
		if (cur->value != NULL)
		{
			ft_putstr_fd("=", 1);
			ft_putstr_fd("\"", 1);
			ft_putstr_fd(cur->value, 1);
			ft_putstr_fd("\"", 1);
		}
		ft_putstr_fd("\n", 1);
		cur = cur->next;
	}
}

t_elist	*sort_env(t_elist *env)
{
	t_elist	*tmp_list;
	t_env	*cur;
	int		i;
	int		j;
	int		len;

	tmp_list = envcpy(env);
	len = count_env(env);
	i = 0;
	while (i++ < len)
	{
		cur = tmp_list->head->next;
		j = 0;
		while (j++ < len - 1)
		{
			if (ft_strcmp(cur->key, cur->next->key) > 0)
				swap(cur, cur->next);
			cur = cur->next;
		}
	}
	print_env(tmp_list);
	return (tmp_list);
}
