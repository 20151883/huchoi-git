#include "main.h"

void *sub_main(void *arg)
{

	t_philo * p_philo = (t_philo *)arg;//일단 보류
	int temp = p_philo->number;//일단 보류
	int i = 0;
	int num = temp + 1;
	int left, right;


	right = (num == p_philo->p_syn->info->number_of_philosophers ? 0 : num);
	left = num - 1;
	if (temp % 2 == 1)
		usleep((temp % 2) * p_philo->p_syn->info->time_to_eat * 1000 / 2);
	else if (p_philo->p_syn->info->number_of_philosophers == num && num % 2 == 1)
		usleep((int)((3.0 / 2.0) * p_philo->p_syn->info->time_to_eat * 1000));
	if (temp % 2 && p_philo->p_syn->info->number_of_philosophers % 2 == 0 && num == p_philo->p_syn->info->number_of_philosophers)
	{
		int temp = right;
		right = left;
		left = temp;
	}
	while (p_philo->p_syn->pthread_flag == 0 && ((p_philo->p_syn->each_count[temp] <= p_philo->p_syn->info->number_of_times_each_philosopher_must_eat) || (p_philo->p_syn->info->number_of_times_each_philosopher_must_eat == -1)))
	{
		if (is_finish_point(p_philo->p_syn) == 1)
			return (NULL);
		//printf("p_philo->p_syn->pthread_flag is %d\n", p_philo->p_syn->pthread_flag);
		pthread_mutex_lock(&p_philo->p_syn->mutex_fork[right]);
		if (is_finish_point(p_philo->p_syn) == 1)
		{
			pthread_mutex_unlock(&p_philo->p_syn->mutex_fork[right]);
			return (NULL);
		}
		printf("%llu ms %d has taken a fork\n", get_mstime() - p_philo->p_syn->start_time, num);
		pthread_mutex_lock(&p_philo->p_syn->mutex_fork[left]);
		if (is_finish_point(p_philo->p_syn) == 1)
		{
			pthread_mutex_unlock(&p_philo->p_syn->mutex_fork[right]);
			pthread_mutex_unlock(&p_philo->p_syn->mutex_fork[left]);
			return (NULL);
		}
		printf("%llu ms %d has taken a fork\n", get_mstime() - p_philo->p_syn->start_time, num);
		printf("%llu ms %d is (start)eating\n", get_mstime() - p_philo->p_syn->start_time, num);
		usleep(p_philo->p_syn->info->time_to_eat * 1000);
		p_philo->p_syn->each_time[temp] = get_mstime() - p_philo->p_syn->start_time;
		pthread_mutex_unlock(&p_philo->p_syn->mutex_fork[left]);
		pthread_mutex_unlock(&p_philo->p_syn->mutex_fork[right]);
		p_philo->p_syn->each_count[temp] = p_philo->p_syn->each_count[temp] + 1;
		if (is_finish_point(p_philo->p_syn) == 1)
			return (NULL);
		//printf("										%d's person's count is %d\n", num, p_philo->p_syn->each_count[temp]);
		printf("%llu ms %d is (start)sleeping\n", get_mstime() - p_philo->p_syn->start_time, num);
		usleep(p_philo->p_syn->info->time_to_sleep * 1000);
		if (is_finish_point(p_philo->p_syn) == 1)
			return (NULL);
		printf("%llu ms %d is (start)thinking\n", get_mstime() - p_philo->p_syn->start_time, num);
	}
	return NULL;
}

int		check_dead(t_syn *p_syn, int *p_flag, int idx)
{
	if ((get_mstime() - p_syn->start_time) >  p_syn->each_time[idx] + p_syn->info->time_to_die)
	{
		pthread_mutex_lock(p_syn->dead_mutex);
		//printf("current : %llu && last time : %llu\n", get_mstime() - p_syn->start_time, p_syn->each_time[i]);
		//printf("gap is : %llu && limit gap is %llu\n", get_mstime() - p_syn->start_time - p_syn->each_time[i], p_syn->info->time_to_die);
		printf("%llu %d died\n",get_mstime() - p_syn->start_time, idx + 1);
		//int *ret = malloc(sizeof(int));
		//*ret = 1;
		p_syn->pthread_flag = 1;
		pthread_mutex_unlock(p_syn->dead_mutex);
		return (1);
	}
	if (p_syn->each_count[idx] >= p_syn->info->number_of_times_each_philosopher_must_eat && p_syn->info->number_of_times_each_philosopher_must_eat != -1)
		(*p_flag)++;
	return (0);
}

void *all_monitor(void *temp)
{
	int flag = 0;
	t_syn *p_syn = (t_syn *)temp;
	usleep((p_syn->info->time_to_die / 2) * 1000);
	while (1)
	{

		for (int i = 0;i < p_syn->info->number_of_philosophers; i++)
		{
			if (check_dead(p_syn, &flag, i) == 1)
				return NULL;
			/*if ((get_mstime() - p_syn->start_time) >  p_syn->each_time[i] + p_syn->info->time_to_die)
			{
				pthread_mutex_lock(p_syn->dead_mutex);
				//printf("current : %llu && last time : %llu\n", get_mstime() - p_syn->start_time, p_syn->each_time[i]);
				//printf("gap is : %llu && limit gap is %llu\n", get_mstime() - p_syn->start_time - p_syn->each_time[i], p_syn->info->time_to_die);
				printf("%llu %d died\n",get_mstime() - p_syn->start_time, i + 1);
				int *ret = malloc(sizeof(int));
				*ret = 1;
				p_syn->pthread_flag = 1;
				pthread_mutex_unlock(p_syn->dead_mutex);
				return ((void *)ret);
			}

			if (p_syn->each_count[i] >= p_syn->info->number_of_times_each_philosopher_must_eat && p_syn->info->number_of_times_each_philosopher_must_eat != -1)
			{
				flag++;
			}*/
		}
		pthread_mutex_lock(p_syn->eat_count_mutex);
		if (flag == p_syn->info->number_of_philosophers)
		{
			/*int *ret = malloc(sizeof(int));
			*ret = 2;*/
			p_syn->pthread_flag = 1;
			printf("%llu must eat count reached\n", p_syn->each_time[p_syn->info->number_of_philosophers - 1]);
			//return ((void *)ret);
			pthread_mutex_unlock(p_syn->eat_count_mutex);
			return (NULL);
		}
		else
			flag = 0;
		pthread_mutex_unlock(p_syn->eat_count_mutex);
		usleep(1000);
	}
}

int main(int argc, char *argv[])
{
	int i;

	if (argc != 5 && argc != 6)
		return 0;
	t_syn *p_syn  = malloc(sizeof(t_syn));//잠시보류

	//p_syn  = malloc(sizeof(syn));
	p_syn->info = (t_info *)malloc(sizeof(t_info));
	pthread_t tid[p_syn->info->number_of_philosophers];
	pthread_t monitor;
	if (-1 == ft_info_init(p_syn, argv))
		return 0;
	t_philo *p_philo = malloc(sizeof(t_philo) * p_syn->info->number_of_philosophers);//잠시보류
	for (int a = 0;a < p_syn->info->number_of_philosophers; a++)//잠시보류
	{
		p_philo[a].number = a;//잠시보류
		p_philo[a].p_syn = p_syn;//잠시보류
	}
	ft_syn_init(p_syn);
	ft_pthread_create(p_philo, &monitor, tid);
	ft_pthread_join(p_syn, &monitor, tid);
	//restore_resources(p_philo);
	return 0;
}
