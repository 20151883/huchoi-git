#include "minishell.h"

int	builtin(t_options *op, t_cmd *cmd)
{
	if (!(ft_strcmp(cmd->argv[0], "export")))
		return (ft_export(cmd->argc, cmd->argv, op->env));
	else if (!(ft_strcmp(cmd->argv[0], "echo")))
		ft_echo(cmd);
	else if (!(ft_strcmp(cmd->argv[0], "env")))
		ft_env(op->env);
	else if (!(ft_strcmp(cmd->argv[0], "cd")))
		return (ft_cd(cmd->argc, cmd->argv, op->env));
	else if (!(ft_strcmp(cmd->argv[0], "pwd")))
		ft_pwd();
	else if (!(ft_strcmp(cmd->argv[0], "unset")))
		return (ft_unset(cmd->argc, cmd->argv, op->env));
	else if (!(ft_strcmp(cmd->argv[0], "exit")))
		return (ft_exit(cmd->argc, cmd->argv));
	else
		return (-1);
	return (0);
}
