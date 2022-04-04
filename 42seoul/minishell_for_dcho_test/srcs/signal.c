/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:26:51 by dcho              #+#    #+#             */
/*   Updated: 2021/10/21 00:28:07 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	signal_handler(int signo)
{
	pid_t	pid;

	pid = waitpid(-1, NULL, WNOHANG);
	if (signo == SIGINT)
	{
		if (g_sig.is_prompt)
		{
			write(1, "\n", 1);
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
			//close(0);
		}
		else if (g_sig.is_parent && !pid && !(g_sig.is_minishell))
			write(1, "\n", 1);
	}
	else if (signo == SIGQUIT)
	{
		if (g_sig.is_prompt)
		{
			rl_on_new_line();
			rl_redisplay();
		}
		else if (g_sig.is_parent && !pid && !(g_sig.is_minishell))
			write(1, "Quit: 3\n", 8);
	}
}

void	signal_main(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
}

void	signal_ignore(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}
