/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:45:10 by dcho              #+#    #+#             */
/*   Updated: 2021/10/20 17:35:33 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	export_error(char *argv)
{
	char	*print;

	print = add_quote(argv);
	print_error_3("export", print, "not a valid identifier");
	free(print);
	return (1);
}

static void	export_modify(t_env *env, char *key, char *value)
{
	if (value == NULL)
		return ;
	free(env->value);
	env->value = NULL;
	env->value = value;
	free(key);
}

static int	export_mainloop(char **argv, t_elist *env, int ret)
{
	char	*key;
	char	*value;
	t_env	*found;
	int		len;

	while (*argv)
	{
		len = env_name_len(*argv);
		if (len == 0)
			ret = export_error(*argv);
		key = my_strdup_len(*argv, len);
		found = search_env(env, key);
		if ((*argv)[len] == '=')
			value = my_strdup_len(*argv + len + 1, ft_strlen(*argv) - len - 1);
		else
			value = NULL;
		if (found == NULL)
			add_env(env->tail->prev, key, value);
		else
			export_modify(found, key, value);
		argv++;
	}
	return (ret);
}

int	ft_export(int argc, char **argv, t_elist *env)
{
	int		ret;
	t_elist	*tmp;

	ret = 0;
	if (argc == 1)
	{
		tmp = sort_env(env);
		elist_clean(tmp);
		free(tmp);
		tmp = NULL;
	}
	else if (argc > 1)
	{
		argv++;
		ret = export_mainloop(argv, env, ret);
	}
	return (ret);
}
