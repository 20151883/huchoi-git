/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_create_join.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 22:42:27 by huchoi            #+#    #+#             */
/*   Updated: 2021/06/27 22:42:28 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			ft_pthread_create(t_philo *p_philo, pthread_t *monitor, \
								pthread_t *tid)
{
	int	i;

	pthread_create(monitor, NULL, all_monitor, p_philo->p_syn);
	i = 0;
	while (i < p_philo->p_syn->info->number_of_philosophers)
	{
		pthread_create(&(tid[i]), NULL, sub_main, (void *)(&((p_philo)[i])));
		i++;
	}
	return (1);
}

int			ft_pthread_join(t_syn *p_syn, pthread_t *monitor, pthread_t *tid)
{
	int	j;

	j = 0;
	pthread_join(*monitor, NULL);
	while (j < p_syn->info->number_of_philosophers)
		pthread_join(tid[j++], NULL);
	return (1);
}

void		restore_resources(t_philo *p_philo)
{
	//뮤텍스 제거
	int z;

	z = 0;
	while (z < p_philo->p_syn->info->number_of_philosophers)
		pthread_mutex_destroy(&(p_philo->p_syn->mutex_fork[z++]));
	pthread_mutex_destroy(p_philo->p_syn->dead_mutex);
	pthread_mutex_destroy(p_philo->p_syn->eat_count_mutex);
	//동적할당된 메모리 해제
	free(p_philo->p_syn->each_count);
	free(p_philo->p_syn->info);
	free(p_philo->p_syn->each_time);
	free(p_philo->p_syn->mutex_fork);
	free(p_philo->p_syn->dead_mutex);
	free(p_philo->p_syn);
	free(p_philo);
}
