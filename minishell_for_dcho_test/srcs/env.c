/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 20:03:18 by soyelee           #+#    #+#             */
/*   Updated: 2021/10/20 16:25:46 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_env(t_elist *env)
{
	int		count;
	t_env	*cur;

	count = 0;
	cur = env->head->next;
	while (!(cur->is_edge))
	{
		count++;
		cur = cur->next;
	}
	return (count);
}

int	env_name_len(char *str)
{
	int	count;

	count = 1;
	if (ft_isalpha(str[0]) == 0 && str[0] != '_')
		return (0);
	while (str[count] != '\0' && (ft_isalnum(str[count]) != 0 \
	|| str[count] == '_'))
		count++;
	return (count);
}

t_elist	*set_env(char **envp)
{
	t_elist	*list;
	char	*equals;
	char	*key;
	char	*value;

	list = (t_elist *)my_malloc(sizeof(t_elist));
	init_elist(list);
	while (*envp)
	{
		equals = ft_strchr(*envp, '=');
		key = my_strdup_len(*envp, (int)(equals - *envp));
		value = my_strdup_len(equals + 1, ft_strlen(equals + 1));
		add_env(list->tail->prev, key, value);
		envp++;
	}
	return (list);
}

char	**out_env(t_elist *env)
{
	int		i;
	int		len;
	char	**envp;
	char	*temp;
	t_env	*cur;

	len = count_env(env);
	envp = (char **)my_malloc(sizeof(char *) * (len + 1));
	envp[len] = NULL;
	cur = env->head->next;
	i = 0;
	while (!(cur->is_edge))
	{
		if (cur->value != NULL)
		{
			temp = ft_strjoin(cur->key, "=");
			envp[i++] = ft_strjoin(temp, cur->value);
			free(temp);
			temp = NULL;
		}
		cur = cur->next;
	}
	return (envp);
}
