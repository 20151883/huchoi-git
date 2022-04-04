/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:20:01 by dcho              #+#    #+#             */
/*   Updated: 2021/10/20 23:58:05 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	signal_d_checker(t_options *op)
{
	if (op->cmdline == NULL)
	{
		signal_ignore();
		ft_putstr_fd("\x1b[1A", STDOUT_FILENO);
		ft_putstr_fd("\033[11C", STDOUT_FILENO);
		ft_putstr_fd("exit\n", STDOUT_FILENO);
		reset_input_mode(&op->org_term);
		exit(0);
	}
}

static int	quote_parse(t_options *op)
{
	t_token	*cur;

	cur = op->token->head->next;
	while (cur->type != -1)
	{
		if (cur->type == SINQ)
		{
			if (sinq_detector(&cur) == FAILURE)
			{
				ft_putstr_fd("unclosed single quotes \n", 2);
				return (FAILURE);
			}
		}
		else if (cur->type == DOUQ)
		{
			if (douq_detector(&cur, op->env) == FAILURE)
			{
				ft_putstr_fd("unclosed double quotes \n", 2);
				return (FAILURE);
			}
		}
		else
			cur = cur->next;
	}
	return (SUCCESS);
}

static int	parse(t_options *op)
{
	t_token	*cur;

	op->token = tokenizer(op->cmdline);
	if (quote_parse(op) == FAILURE)
		return (FAILURE);
	if (error_token(op))
		return (FAILURE);
	cur = op->token->head->next;
	while (cur->type != -1)
	{
		if (cur->type == DOLR)
			dolr_detector(&cur, *(op->env), DOLR);
		cur = cur->next;
	}
	op->cmd = cmdizer(op->token);
	if (op->cmd == NULL)
	{
		ft_putstr_fd("commandline cannot end with pipe\n", 1);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	loop_main(t_options *op)
{
	while (1)
	{
		free_after_loop(op);
		init_prompt(op);
		op->cmdline = readline("\033[32mMinishell>\033[0m ");
		signal_d_checker(op);
		if (ft_strcmp("", op->cmdline) == 0)
			continue ;
		add_history(op->cmdline);
		op->exit_status = parse(op) + 1;
		if (op->exit_status == 1)
			continue ;
		if (heredoc(op->cmd->head->next, op) == FAILURE)
			continue ;
		reset_input_mode(&op->org_term);
		signal_ignore();
		init_pid(op);
		if (op->cmd->head->next->is_pipe == FALSE)
			exec_single(op);
		else
			exec_multiple(op);
	}
}
