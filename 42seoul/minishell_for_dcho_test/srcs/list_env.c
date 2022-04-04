/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyelee <soyelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 16:39:50 by soyelee           #+#    #+#             */
/*   Updated: 2021/10/18 19:01:51 by soyelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_elist(t_elist *list)
{
	list->head = new_env(NULL, NULL, TRUE);
	list->head->exitstatus = 0;
	list->tail = new_env(NULL, NULL, TRUE);
	list->head->next = list->tail;
	list->tail->prev = list->head;
}

t_env	*new_env(char *key, char *value, int is_edge)
{
	t_env	*res;

	res = (t_env *)my_malloc(sizeof(t_env));
	res->key = key;
	res->value = value;
	res->is_edge = is_edge;
	res->prev = NULL;
	res->next = NULL;
	return (res);
}

void	add_env(t_env *prev, char *key, char *value)
{
	t_env	*new;

	new = new_env(key, value, FALSE);
	new->prev = prev;
	new->next = prev->next;
	prev->next = new;
	new->next->prev = new;
}

void	del_env(t_env *env)
{
	free(env->key);
	env->key = NULL;
	if (env->value != NULL)
	{
		free(env->value);
		env->value = NULL;
	}
	env->prev = NULL;
	env->next = NULL;
	free(env);
	env = NULL;
}

void	remove_env(t_env *env)
{
	env->next->prev = env->prev;
	env->prev->next = env->next;
	del_env(env);
}
