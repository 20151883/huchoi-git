/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyelee <soyelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:07:02 by dcho              #+#    #+#             */
/*   Updated: 2021/10/18 16:30:22 by soyelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_number(char *str)
{
	while (*str)
	{
		if (ft_isdigit((int)(*str)) == 0)
			return (FALSE);
		str++;
	}
	return (TRUE);
}

int	ft_exit(int argc, char **argv)
{
	ft_putstr_fd("exit\n", 1);
	if (argc > 2)
	{
		print_error_2("exit", "too many arguments");
		return (1);
	}
	if (argc == 2 && !(is_number(argv[1])))
	{
		print_error_3("exit", argv[1], "numeric argument required");
		exit(255);
	}
	exit(0);
}
