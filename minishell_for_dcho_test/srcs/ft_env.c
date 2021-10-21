/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 00:44:35 by dcho              #+#    #+#             */
/*   Updated: 2021/10/07 20:52:49 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_elist *env)
{
	t_env	*cur;

	cur = env->head->next;
	while (!(cur->is_edge))
	{
		if (cur->value != NULL)
		{
			ft_putstr_fd(cur->key, 1);
			ft_putstr_fd("=", 1);
			ft_putstr_fd(cur->value, 1);
			ft_putstr_fd("\n", 1);
		}
		cur = cur->next;
	}
}
