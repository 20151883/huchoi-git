#include "main.h"

int ft_isdigit(const char *arr)
{
	while (*arr)
	{
		if ('0' > *arr || *arr > '9')
			return 0;
		arr++;
	}
	return (1);
}

int		ft_strlen(char *str)
{
	int	ret;

	ret = 0;
	while (str[ret])
		ret++;
	return (ret);
}

int		ft_strcmp(char *s1, char *s2)
{
	int idx;

	idx = 0;
	while (s1[idx] == s2[idx] && s1[idx])
		idx++;
	return (s1[idx] - s2[idx]);
}

int		my_atouit(char *positive_arr)
{
	int	ret;
	int	idx;

	ret = 0;
	idx = 0;
	if (ft_strlen(positive_arr) >= 10 && ft_strcmp(positive_arr, "2147483647") > 0)
		return -1;
	while (positive_arr[idx])
	{
		ret *= 10;
		ret += positive_arr[idx] - '0';
		idx++;
	}
	return (ret);
}

//int ft_info_init(Info *p_info, char **argv)
int ft_info_init(t_syn *p_syn, char **argv)
{
	int i;
	t_info *p_info = p_syn->info;
	i = 0;
	while (argv[++i])
	{
		if (ft_isdigit(argv[i]) == 0 || my_atouit(argv[i]) == -1)//음수, 양수범위 넘어가는 수, 숫자가 아닌것 모두 걸러짐.
		{
			printf("error argument\n");
			free(p_syn->info);
			free(p_syn);
			return -1;
		}
	}
	p_syn->info->number_of_philosophers = my_atouit(argv[1]);
	p_syn->info->time_to_die = (uint64_t)my_atouit(argv[2]);
	p_syn->info->time_to_eat = (uint64_t)my_atouit(argv[3]);
	p_syn->info->time_to_sleep = (uint64_t)my_atouit(argv[4]);
	if (argv[5] != NULL)
		p_syn->info->number_of_times_each_philosopher_must_eat = my_atouit(argv[5]);
	else
		p_syn->info->number_of_times_each_philosopher_must_eat = -1;
	return 1;
}

int		is_anybody_dead(t_syn *p_syn)
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

int		is_all_enough_eat(t_syn *p_syn)
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


int		is_finish_point(t_syn *p_syn)
{
	if (is_all_enough_eat(p_syn) && is_anybody_dead(p_syn))
		return (1);
	else
		return (0);
}

void ft_syn_init(t_syn *p_syn)
{
	p_syn->pthread_flag = 0;
	p_syn->start_time = get_mstime();
	p_syn->each_time = malloc(sizeof(uint64_t) * p_syn->info->number_of_philosophers);
	p_syn->each_count = malloc(sizeof(int) * p_syn->info->number_of_philosophers);
	for (int q = 0;q < p_syn->info->number_of_philosophers; q++)
		(p_syn->each_count)[q] = 0;
	for (int i = 0;i < p_syn->info->number_of_philosophers; i++)
		(p_syn->each_time)[i]= get_mstime();
	p_syn->mutex_fork = malloc(sizeof(pthread_mutex_t) * p_syn->info->number_of_philosophers);
	p_syn->dead_mutex = malloc(sizeof(pthread_t));
	p_syn->eat_count_mutex = malloc(sizeof(pthread_t));
	int i;
	for (i=0; i < p_syn->info->number_of_philosophers; i++)
		pthread_mutex_init(&(p_syn->mutex_fork[i]), NULL);
	pthread_mutex_init(p_syn->dead_mutex, NULL);
}

int ft_pthread_create(t_philo *p_philo, pthread_t *monitor, pthread_t *tid)
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

int ft_pthread_join(t_syn *p_syn, pthread_t *monitor, pthread_t *tid)
{
	//printf("reach??\n");
	int	j;

	j = 0;

	pthread_join(*monitor, NULL);

	while (j < p_syn->info->number_of_philosophers)
		pthread_join(tid[j++], NULL);

	return 1;
}

void	restore_resources(t_philo *p_philo)
{
	//뮤텍스 제거
	int z;
	for (z = 0;z < p_philo->p_syn->info->number_of_philosophers; z++)
		pthread_mutex_destroy(&(p_philo->p_syn->mutex_fork[z]));
	pthread_mutex_destroy(p_philo->p_syn->dead_mutex);
	//동적할당된 메모리 해제
	free(p_philo->p_syn->each_count);
	free(p_philo->p_syn->info);
	free(p_philo->p_syn->each_time);
	free(p_philo->p_syn->mutex_fork);
	free(p_philo->p_syn->dead_mutex);
	free(p_philo->p_syn);
	free(p_philo);
}

uint64_t get_mstime()
{
	struct timeval current;
	gettimeofday(&current, NULL);

	return (current.tv_sec * (uint64_t)1000) + (current.tv_usec / 1000);
}
