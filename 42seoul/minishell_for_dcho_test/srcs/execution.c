/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:49:44 by soyelee           #+#    #+#             */
/*   Updated: 2021/10/20 16:27:19 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exit_error_exec(char *str)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": command not found\n", 2);
	exit(127);
}

char	**get_path(t_elist *env)
{
	char	**res;
	t_env	*path;

	path = search_env(env, "PATH");
	if (path == NULL)
		return (NULL);
	res = ft_split(path->value, ':');
	return (res);
}

char	*get_command(char *cmd, char *path)
{
	char	*temp;
	char	*result;

	temp = ft_strjoin(path, "/");
	result = ft_strjoin(temp, cmd);
	free(temp);
	temp = NULL;
	return (result);
}

void	execution(t_cmd *cmd, t_elist *env)
{
	char	**paths;
	char	*command;

	paths = get_path(env);
	execve(cmd->argv[0], cmd->argv, out_env(env));
	if (paths == NULL)
	{
		print_error_2(cmd->argv[0], "No such file or directory");
	}
	while (*paths)
	{
		command = get_command(cmd->argv[0], *paths);
		execve(command, cmd->argv, out_env(env));
		free(command);
		command = NULL;
		paths++;
	}
	exit_error_exec(cmd->argv[0]);
}
