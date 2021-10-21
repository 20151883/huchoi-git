/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyelee <soyelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:45:15 by dcho              #+#    #+#             */
/*   Updated: 2021/10/20 03:29:18 by soyelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(int argc, char **argv, t_elist *env)
{
	t_env	*home;

	if (argc == 1)
	{
		home = search_env(env, "HOME");
		if (home)
			chdir(home->value);
		else
		{
			print_error_2("cd", "HOME not set");
			return (1);
		}
	}
	else if (argc > 1)
	{
		if (chdir(argv[1]))
		{
			print_error_3("cd", argv[1], "No such file or directory");
			return (1);
		}
	}
	return (0);
}
