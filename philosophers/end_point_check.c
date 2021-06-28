/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_point_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 22:42:20 by huchoi            #+#    #+#             */
/*   Updated: 2021/06/28 15:53:18 by huchoi           ###   ########.fr       */
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
	if (is_all_enough_eat(p_syn))
	{
		if (is_anybody_dead(p_syn))
			return (1);
		else
			return (0);
	}
	else if (p_syn->info->number_of_times_each_philosopher_must_eat == 0)
		return (1);
	else
		return (0);
}

int			manage_one_philosopher(t_philo *p_philo)
{
	if (p_philo->p_syn->info->number_of_philosophers == 1)
		usleep(p_philo->p_syn->info->time_to_die * 1011);
	if (is_finish_point(p_philo->p_syn) == 1)
	{
		pthread_mutex_unlock(&p_philo->p_syn->mutex_fork[ft_right(p_philo)]);
		return (0);
	}
	else
		return (1);
}
