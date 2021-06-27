/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 22:42:14 by huchoi            #+#    #+#             */
/*   Updated: 2021/06/27 22:42:46 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			ft_info_init(t_syn *p_syn, char **argv)
{
	int		i;
	t_info	*p_info;

	i = 0;
	p_info = p_syn->info;
	while (argv[++i])
	{
		if (ft_isdigit(argv[i]) == 0 || my_atouit(argv[i]) == -1)
		{//음수, 양수범위 넘어가는 수, 숫자가 아닌것 모두 걸러짐.
			printf("error argument\n");
			free(p_syn->info);
			free(p_syn);
			return (-1);
		}
	}
	p_syn->info->number_of_philosophers = my_atouit(argv[1]);
	p_syn->info->time_to_die = (uint64_t)my_atouit(argv[2]);
	p_syn->info->time_to_eat = (uint64_t)my_atouit(argv[3]);
	p_syn->info->time_to_sleep = (uint64_t)my_atouit(argv[4]);
	if (argv[5] != NULL)
		p_syn->info->number_of_times_each_philosopher_must_eat = \
		my_atouit(argv[5]);
	else
		p_syn->info->number_of_times_each_philosopher_must_eat = -1;
	return (1);
}

void		ft_syn_init(t_syn *p_syn)
{
	int	i;

	p_syn->pthread_flag = 0;
	p_syn->start_time = get_mstime();
	p_syn->each_time = malloc(sizeof(uint64_t) * \
					p_syn->info->number_of_philosophers);
	p_syn->each_count = malloc(sizeof(int) * \
					p_syn->info->number_of_philosophers);
	i = 0;
	while (i < p_syn->info->number_of_philosophers)
		(p_syn->each_count)[i++] = 0;
	while (--i >= 0)
		(p_syn->each_time)[i] = get_mstime();
	p_syn->mutex_fork = malloc(sizeof(pthread_mutex_t) * \
							p_syn->info->number_of_philosophers);
	p_syn->dead_mutex = malloc(sizeof(pthread_t));
	p_syn->eat_count_mutex = malloc(sizeof(pthread_t));
	while (++i < p_syn->info->number_of_philosophers)
		pthread_mutex_init(&(p_syn->mutex_fork[i]), NULL);
	pthread_mutex_init(p_syn->dead_mutex, NULL);
}
