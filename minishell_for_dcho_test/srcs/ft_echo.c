/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyelee <soyelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 21:19:28 by dcho              #+#    #+#             */
/*   Updated: 2021/10/20 03:25:35 by soyelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_cmd *cmd)
{
	int		option;
	int		i;

	i = 1;
	option = FALSE;
	if (cmd->argc > 1)
	{
		if (!(ft_strcmp(cmd->argv[i], "-n")))
		{
			option = TRUE;
			i++;
		}
		while (cmd->argv[i])
		{
			ft_putstr_fd(cmd->argv[i++], 1);
			ft_putchar_fd(' ', 1);
		}
		ft_putchar_fd('\b', 1);
		if (option == FALSE)
			ft_putchar_fd('\n', 1);
	}
	else
		ft_putchar_fd('\n', 1);
}
