/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyelee <soyelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:44:36 by dcho              #+#    #+#             */
/*   Updated: 2021/10/20 03:47:41 by soyelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*search_env(t_elist *env, char *key)
{
	t_env	*cur;

	cur = env->head->next;
	while (cur->is_edge == FALSE)
	{
		if (!(ft_strcmp(key, cur->key)))
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

char	*add_quote(char *str)
{
	char	*res;
	int		strlen;

	strlen = ft_strlen(str);
	res = my_malloc(strlen + 3);
	res[0] = '`';
	ft_strlcpy(res + 1, str, ft_strlen(str) + 1);
	res[strlen + 1] = '\'';
	res[strlen + 2] = '\0';
	return (res);
}

int	ft_unset(int argc, char **argv, t_elist *env)
{
	t_env	*found;
	int		len;
	int		i;
	char	*print;

	i = 1;
	if (argc > 1)
	{
		while (--argc)
		{
			len = env_name_len(argv[i]);
			if (len == 0)
			{
				print = add_quote(argv[i]);
				print_error_3("unset", print, "not a valid identifier");
				free(print);
				return (FAILURE);
			}
			found = search_env(env, argv[i]);
			if (found)
				remove_env(found);
		}
	}
	return (SUCCESS);
}
