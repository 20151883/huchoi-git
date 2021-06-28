/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 19:08:39 by huchoi            #+#    #+#             */
/*   Updated: 2021/06/28 22:43:38 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

typedef	struct		s_info
{
	int				number_of_times_each_philosopher_must_eat;
	int				number_of_philosophers;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	uint64_t		start_time;
}					t_info;

typedef	struct		s_syn
{
	int				*each_count;
	int				pthread_flag;
	t_info			*info;
	uint64_t		*each_time;
	uint64_t		*revision_time;
	uint64_t		*before_time;
	uint64_t		start_time;
	pthread_mutex_t	*mutex_fork;
	pthread_mutex_t	*dead_mutex;
	pthread_mutex_t	*eat_count_mutex;
}					t_syn;

typedef	struct		s_philo
{
	t_syn			*p_syn;
	int				number;

}					t_philo;

uint64_t			get_mstime();
int					ft_strlen(char *str);
int					ft_strcmp(char *s1, char *s2);
int					my_atouit(char *positive_arr);
int					ft_info_init(t_syn *p_syn, char **argv);
void				ft_syn_init(t_philo *p_philo);
void				restore_resources(t_philo *p_philo, pthread_t	*tid);
int					ft_pthread_create(t_philo *temp, \
					pthread_t *monitor, pthread_t *tid);
int					ft_pthread_join(t_syn *temp, pthread_t *monitor, \
					pthread_t *tid);
void				*sub_main(void *arg);
void				*all_monitor(void *arg);
int					is_anybody_dead(t_syn *temp);
int					is_all_enough_eat(t_syn *temp);
int					is_finish_point(t_syn *temp);
int					ft_right(t_philo *p_philo);
int					ft_left(t_philo *p_philo);
uint64_t			relative_mstime(t_philo *p_philo);
void				even_last_sleep(t_philo *p_philo);
int					wait_fork_and_eating(t_philo *p_philo);
int					ft_isdigit(const char *arr);
int					manage_one_philosopher(t_philo *p_philo);
int			sleep_thinking(t_philo *p_philo);
#endif
