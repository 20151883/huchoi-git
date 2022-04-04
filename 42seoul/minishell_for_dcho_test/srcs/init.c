/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 20:27:54 by dcho              #+#    #+#             */
/*   Updated: 2021/10/20 20:41:13 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_minishell(t_options *op, char *argv, char **envp)
{
	op->cmdline = NULL;
	op->token = NULL;
	op->cmd = NULL;
	op->pid = NULL;
	op->env = set_env(envp);
	op->exit_status = 0;
	op->minishell_path = my_malloc(PATH_MAX);
	getcwd(op->minishell_path, PATH_MAX);
	save_input_mode(&op->org_term);
	g_sig.program = argv;
}

void	init_pid(t_options *op)
{
	t_cmd	*c_cur;
	int		cnt;

	c_cur = op->cmd->head->next;
	cnt = 0;
	while (c_cur->is_pipe == 1)
	{
		cnt++;
		c_cur = c_cur->next;
	}
	op->pid = (int *)my_malloc(sizeof(int) * (cnt + 1));
	op->pid[cnt] = -1;
}

void	init_prompt(t_options *op)
{
	g_sig.is_prompt = TRUE;
	g_sig.is_parent = TRUE;
	g_sig.is_minishell = FALSE;
	g_sig.is_heredoc = FALSE;
	op->env->head->exitstatus = op->exit_status;
	signal_main();
	set_input_mode(&op->new_term);
}
