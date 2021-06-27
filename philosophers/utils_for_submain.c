/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_submain.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 22:36:43 by huchoi            #+#    #+#             */
/*   Updated: 2021/06/27 22:37:11 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			ft_right(t_philo *p_philo)
{
	int	right;
	int	left;
	int	num;
	int	temp;
	int tmp;

	num = p_philo->number + 1;
	temp = num - 1;
	right = (num == p_philo->p_syn->info->number_of_philosophers ? 0 : num);
	left = num - 1;
	if (temp % 2 && p_philo->p_syn->info->number_of_philosophers % 2 == 0 \
	&& num == p_philo->p_syn->info->number_of_philosophers)
	{
		tmp = right;
		right = left;
		left = tmp;
	}
	return (right);
}

int			ft_left(t_philo *p_philo)
{
	int	left;
	int	right;
	int	num;
	int	temp;
	int	tmp;

	temp = num - 1;
	num = p_philo->number + 1;
	right = (num == p_philo->p_syn->info->number_of_philosophers ? 0 : num);
	left = num - 1;
	if (temp % 2 && p_philo->p_syn->info->number_of_philosophers % 2 == 0 \
	&& num == p_philo->p_syn->info->number_of_philosophers)
	{
		tmp = right;
		right = left;
		left = tmp;
	}
	return (left);
}

uint64_t	relative_mstime(t_philo *p_philo)
{
	return (get_mstime() - p_philo->p_syn->start_time);
}

int			wait_fork_and_eating(t_philo *p_philo)
{
	int	num;

	num = p_philo->number + 1;
	pthread_mutex_lock(&p_philo->p_syn->mutex_fork[ft_right(p_philo)]);
	if (is_finish_point(p_philo->p_syn) == 1)
	{
		pthread_mutex_unlock(&p_philo->p_syn->mutex_fork[ft_right(p_philo)]);
		return (0);
	}
	printf("%llu ms %d has taken a fork\n", relative_mstime(p_philo), num);
	pthread_mutex_lock(&p_philo->p_syn->mutex_fork[ft_left(p_philo)]);
	if (is_finish_point(p_philo->p_syn) == 1)
	{
		pthread_mutex_unlock(&p_philo->p_syn->mutex_fork[ft_right(p_philo)]);
		pthread_mutex_unlock(&p_philo->p_syn->mutex_fork[ft_left(p_philo)]);
		return (0);
	}
	printf("%llu ms %d has taken a fork\n", relative_mstime(p_philo), num);
	printf("%llu ms %d is eating\n", relative_mstime(p_philo), num);
	p_philo->p_syn->each_time[num - 1] = relative_mstime(p_philo);
	usleep(p_philo->p_syn->info->time_to_eat * 1000);
	pthread_mutex_unlock(&p_philo->p_syn->mutex_fork[ft_left(p_philo)]);
	pthread_mutex_unlock(&p_philo->p_syn->mutex_fork[ft_right(p_philo)]);
	p_philo->p_syn->each_count[num - 1]++;
	return (1);
}

void		even_last_sleep(t_philo *p_philo)
{
	int		num;

	num = p_philo->number + 1;
	if (num % 2 == 0)
		usleep(p_philo->p_syn->info->time_to_eat * 1000 / 2);
	else if (p_philo->p_syn->info->number_of_philosophers == num \
	&& num % 2 == 1)
		usleep((int)((3.0 / 2.0) * p_philo->p_syn->info->time_to_eat * 1000));
}
