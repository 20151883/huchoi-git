/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyelee <soyelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:53:52 by dcho              #+#    #+#             */
/*   Updated: 2021/09/04 16:19:0 by soyelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_options		op;

	if (argc != 1 || argv[1] != NULL)
		exit_error("Enter \"./minishell\"\n");
	init_minishell(&op, argv[0], envp);
	loop_main(&op);
	return (0);
}
