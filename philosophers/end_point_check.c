/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_point_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 22:42:20 by huchoi            #+#    #+#             */
/*   Updated: 2021/06/27 22:42:28 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			is_anybody_dead(t_syn *p_syn)
{
	pthread_mutex_lock(p_syn->dead_mutex);
	if (p_syn->pthread_flag == 1)
	{
		pthread_mutex_unlock(p_syn->dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(p_syn->dead_mutex);
	return (0);
}

int			is_all_enough_eat(t_syn *p_syn)
{
	pthread_mutex_lock(p_syn->eat_count_mutex);
	if (p_syn->pthread_flag == 1)
	{
		pthread_mutex_unlock(p_syn->eat_count_mutex);
		return (1);
	}
	pthread_mutex_unlock(p_syn->eat_count_mutex);
	return (0);
}

int			is_finish_point(t_syn *p_syn)
{
	if (is_all_enough_eat(p_syn) && is_anybody_dead(p_syn))
		return (1);
	else
		return (0);
}
