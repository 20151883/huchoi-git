/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 21:03:44 by huchoi            #+#    #+#             */
/*   Updated: 2021/06/30 13:33:40 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		*sub_main(void *arg)
{
	int		num;
	t_philo	*p_philo;

	p_philo = (t_philo *)arg;
	num = p_philo->number + 1;
	even_last_sleep(p_philo);
	while (p_philo->p_syn->pthread_flag == 0 && (p_philo->p_syn->each_count\
	[num - 1] <= p_philo->p_syn->info->\
	number_of_times_each_philosopher_must_eat \
	|| p_philo->p_syn->info->number_of_times_each_philosopher_must_eat == -1))
	{
		if (is_finish_point(p_philo->p_syn) == 1)
			return (NULL);
		if (0 == wait_fork_and_eating(p_philo))
			return (NULL);
		if (is_finish_point(p_philo->p_syn) == 1)
			return (NULL);
		if (sleep_thinking(p_philo) == 0)
			return (NULL);
	}
	return (NULL);
}

int			sleep_thinking(t_philo *p_philo)
{
	int		num;

	num = p_philo->number + 1;
	printf("%llu ms %d is sleeping\n", relative_mstime(p_philo), num);
	//usleep(p_philo->p_syn->info->time_to_sleep * 1000);
	my_usleep(p_philo, p_philo->p_syn->info->time_to_sleep * 1000);
	p_philo->sleeping_flag = 1;//////
	p_philo->p_syn->revision_time[num - 1] = relative_mstime(p_philo) - p_philo->p_syn->info->time_to_eat - p_philo->p_syn->info->time_to_sleep;
	if (is_finish_point(p_philo->p_syn) == 1)
		return (0);
	printf("%llu ms %d is thinking\n", relative_mstime(p_philo), num);
	return (1);
}

int			check_dead(t_philo *p_philo, int *p_flag, int idx)
{
	t_syn *p_syn = p_philo->p_syn;

	if ((get_mstime() - p_syn->start_time) > \
	(p_syn->revision_time[idx]) + p_syn->info->time_to_die)
	{
		pthread_mutex_lock(p_syn->dead_mutex);
		//printf("gap is : %llu && limit gap is %llu\n", get_mstime() - p_syn->start_time - p_syn->each_time[idx], p_syn->info->time_to_die);
		printf("%llu %d died\n", get_mstime() - p_syn->start_time, idx + 1);
		p_syn->pthread_flag = 1;
		pthread_mutex_unlock(p_syn->dead_mutex);
		return (1);
	}
	if (p_syn->each_count[idx] >= \
	p_syn->info->number_of_times_each_philosopher_must_eat \
	&& p_syn->info->number_of_times_each_philosopher_must_eat != -1)
		(*p_flag)++;
	return (0);
}

int			all_check_dead(t_philo *p_philo, int *p_flag)
{
	int	i;

	i = -1;
	while (++i < p_philo->p_syn->info->number_of_philosophers)
	{
		if (check_dead(p_philo, p_flag, i) == 1)
			return (1);
	}
	return (0);
}

uint64_t	lastest_time(uint64_t *arr, int num)
{
	uint64_t	ret;
	int			idx;

	idx = -1;
	ret = arr[0];
	while (++idx < num)
	{
		if (arr[idx] > ret)
			ret = arr[idx];
	}
	return (ret);
}

void		*all_monitor(void *p_philo)
{
	int		flag;
	t_syn	*p_syn;

	flag = 0;
	p_syn = (t_syn *)(((t_philo *)(p_philo))->p_syn);
	usleep((p_syn->info->time_to_die / 2) * 1000);
	while (1)
	{
		pthread_mutex_lock(p_syn->eat_count_mutex);
		if (all_check_dead(p_philo, &flag) == 1)
			return (NULL);
		if (flag == p_syn->info->number_of_philosophers)
		{
			p_syn->pthread_flag = 1;
			printf("%llu must eat count reached\n", relative_mstime(p_philo));
			pthread_mutex_unlock(p_syn->eat_count_mutex);
			return (NULL);
		}
		else
			flag = 0;
		pthread_mutex_unlock(p_syn->eat_count_mutex);
		usleep(1000);
	}
}

int			main(int argc, char *argv[])
{
	int			i;
	t_philo		*p_philo;
	t_syn		*p_syn;
	pthread_t	*tid;
	pthread_t	monitor;

	if (argc != 5 && argc != 6)
		return (0);
	p_syn = malloc(sizeof(t_syn));
	p_syn->info = (t_info *)malloc(sizeof(t_info));
	if (-1 == ft_info_init(p_syn, argv))
		return (0);
	tid = malloc(sizeof(pthread_t) * p_syn->info->number_of_philosophers);
	p_philo = malloc(sizeof(t_philo) * p_syn->info->number_of_philosophers);
	i = -1;
	while (++i < p_syn->info->number_of_philosophers)
	{
		p_philo[i].number = i;
		p_philo[i].eating_flag = 0;
		p_philo[i].sleeping_flag = 0;
		p_philo[i].p_syn = p_syn;
	}
	ft_syn_init(p_philo);
	ft_pthread_create(p_philo, &monitor, tid);
	ft_pthread_join(p_syn, &monitor, tid);
	restore_resources(p_philo, tid);
	return (0);
}
