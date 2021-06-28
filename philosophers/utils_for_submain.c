/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_submain.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 22:36:43 by huchoi            #+#    #+#             */
/*   Updated: 2021/06/28 23:29:25 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			ft_right(t_philo *p_philo)
{
	int	right;
	int	left;
	int	num;

	num = p_philo->number + 1;
	right = (num == p_philo->p_syn->info->number_of_philosophers ? 0 : num);
	left = num - 1;
	if (p_philo->p_syn->info->number_of_philosophers == 1)
		right = 0;
	return (right);
}

int			ft_left(t_philo *p_philo)
{
	int	left;
	int	right;
	int	num;

	num = p_philo->number + 1;
	right = (num == p_philo->p_syn->info->number_of_philosophers ? 0 : num);
	left = num - 1;
	return (left);
}

uint64_t	relative_mstime(t_philo *p_philo)
{
	return (get_mstime() - p_philo->p_syn->start_time);
}

int			get_right_fork(t_philo *p_philo)
{
	int	num;

	num = p_philo->number + 1;
	pthread_mutex_lock(&p_philo->p_syn->mutex_fork[ft_right(p_philo)]);
	if (is_finish_point(p_philo->p_syn) == 1)
	{
		pthread_mutex_unlock(&p_philo->p_syn->mutex_fork[ft_right(p_philo)]);
		return (0);
	}
	if (p_philo->p_syn->each_time[num - 1] != 0)
		p_philo->p_syn->revision_time[num - 1] = relative_mstime(p_philo) -\
		p_philo->p_syn->info->time_to_eat - p_philo->p_syn->info->time_to_sleep;
	printf("%llu ms %d has taken a fork\n", relative_mstime(p_philo), num);
	if (0 == manage_one_philosopher(p_philo))
		return (0);
	return (1);
}

int			get_left_fork_eating(t_philo *p_philo)
{
	int	num;

	num = p_philo->number + 1;
	pthread_mutex_lock(&p_philo->p_syn->mutex_fork[ft_left(p_philo)]);
	if (p_philo->p_syn->each_time[num - 1] != 0)
		p_philo->p_syn->revision_time[num - 1] = relative_mstime(p_philo) \
	- p_philo->p_syn->info->time_to_eat - p_philo->p_syn->info->time_to_sleep;
	if (is_finish_point(p_philo->p_syn) == 1)
	{
		pthread_mutex_unlock(&p_philo->p_syn->mutex_fork[ft_right(p_philo)]);
		pthread_mutex_unlock(&p_philo->p_syn->mutex_fork[ft_left(p_philo)]);
		return (0);
	}
	printf("%llu ms %d has taken a fork\n", relative_mstime(p_philo), num);
	printf("%llu ms %d is eating\n", relative_mstime(p_philo), num);
	p_philo->p_syn->each_time[num - 1] = relative_mstime(p_philo);
	p_philo->p_syn->revision_time[num - 1] = relative_mstime(p_philo);
	//printf("p_philo->p_syn->each_time[num - 1] : %llu\n", p_philo->p_syn->each_time[num - 1]);
	if (is_finish_point(p_philo->p_syn) == 1)
	{
		pthread_mutex_unlock(&p_philo->p_syn->mutex_fork[ft_right(p_philo)]);
		pthread_mutex_unlock(&p_philo->p_syn->mutex_fork[ft_left(p_philo)]);
		return (0);
	}
	return (1);
}

int			wait_fork_and_eating(t_philo *p_philo)
{
	int	num;

	num = p_philo->number + 1;
	if (0 == get_right_fork(p_philo))
		return (0);
	if (0 == get_left_fork_eating(p_philo))
		return (0);
	usleep(p_philo->p_syn->info->time_to_eat * 1000);
	p_philo->p_syn->revision_time[num - 1] = \
	relative_mstime(p_philo) - p_philo->p_syn->info->time_to_eat;
	p_philo->p_syn->each_count[num - 1]++;
	if (is_finish_point(p_philo->p_syn) == 1)
	{
		pthread_mutex_unlock(&p_philo->p_syn->mutex_fork[ft_right(p_philo)]);
		pthread_mutex_unlock(&p_philo->p_syn->mutex_fork[ft_left(p_philo)]);
		return (0);
	}
	//printf("									%d eated %d\n", num, p_philo->p_syn->each_count[num - 1]);
	pthread_mutex_unlock(&p_philo->p_syn->mutex_fork[ft_left(p_philo)]);
	pthread_mutex_unlock(&p_philo->p_syn->mutex_fork[ft_right(p_philo)]);
	p_philo->p_syn->revision_time[num - 1] = \
	relative_mstime(p_philo) - p_philo->p_syn->info->time_to_eat;
	return (1);
}

void		even_last_sleep(t_philo *p_philo)
{
	int		num;

	num = p_philo->number + 1;
	if (num % 2 == 0)
		usleep(p_philo->p_syn->info->time_to_eat * 1000 / 2);
	else if (p_philo->p_syn->info->number_of_philosophers == num \
	&& num % 2 == 1 && num != 1)
		usleep((int)((3.0 / 2.0) * p_philo->p_syn->info->time_to_eat * 1000));
}
