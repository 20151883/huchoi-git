/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyelee <soyelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:53:07 by soyelee           #+#    #+#             */
/*   Updated: 2021/10/20 03:32:30 by soyelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_error_1(char *strerr)
{
	ft_putstr_fd("Minishell: ", 2);
	perror(strerr);
}

void	print_error_2(char *cmd, char *strerr)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerr, 2);
	ft_putchar_fd('\n', 2);
}

void	print_error_3(char *cmd, char *arg, char *strerr)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerr, 2);
	ft_putchar_fd('\n', 2);
}

void	exit_error_malloc(void)
{
	ft_putstr_fd("Malloc failure\n", 2);
	exit(1);
}

void	exit_error(char *str)
{
	ft_putstr_fd("Minishell: ", 2);
	perror(str);
	exit(errno);
}
