#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <sys/time.h>

typedef struct Info{
	int			number_of_philosophers;
	uint64_t time_to_die;
	uint64_t time_to_eat;
	uint64_t time_to_sleep;
	int			number_of_times_each_philosopher_must_eat;
	struct timeval start_time;
}Info;

typedef struct Syn{
	Info *info;
	pthread_mutex_t *mutex_fork;
	pthread_mutex_t *lock;
	uint64_t *each_time;
	uint64_t start_time;
	int pthread_flag;
	int *each_count;
	pthread_mutex_t *count_lock;
}syn;

syn *p_syn;



/*pthread_mutex_t *mutex_fork;
pthread_mutex_t *lock;
uint64_t *each_time;
uint64_t start_time;
int pthread_flag;
int *each_count;
pthread_mutex_t *count_lock;
Info *info;*/

uint64_t get_mstime();

void ft_init(Info *p_info, char **argv)
{//is digit 활용 잘 해야할듯..
	p_info->number_of_philosophers = atoi(argv[1]);
	p_info->time_to_die = (suseconds_t)atoi(argv[2]);
	p_info->time_to_eat = (suseconds_t)atoi(argv[3]);
	p_info->time_to_sleep = (suseconds_t)atoi(argv[4]);
	if (argv[5] != NULL)
		p_info->number_of_times_each_philosopher_must_eat = atoi(argv[5]);
	else
		p_info->number_of_times_each_philosopher_must_eat = -1;
}

void *sub_main(void *arg)
{
	int temp = *((int *)arg);
	int i = 0;
	int num = temp + 1;
	int max =  0 - p_syn->info->number_of_times_each_philosopher_must_eat;
	int left, right;//n번째 철학자의 오른쪽의 포크는 fork[n], 왼쪽의 포크는 fork[n-1]
	right = (num == p_syn->info->number_of_philosophers ? 0 : num);
	left = num - 1;
	if (temp % 2 == 1)
		usleep((temp % 2) * p_syn->info->time_to_eat * 1000 / 2);
	else if (p_syn->info->number_of_philosophers == num && num % 2 == 1)
		usleep((int)((3.0 / 2.0) * p_syn->info->time_to_eat * 1000));
	if (temp % 2 && p_syn->info->number_of_philosophers % 2 == 0 && num == p_syn->info->number_of_philosophers)
	{
		int temp = right;
		right = left;
		left = temp;
	}
	while (p_syn->pthread_flag == 0 && p_syn->each_count[temp] <= p_syn->info->number_of_times_each_philosopher_must_eat)
	{
		pthread_mutex_lock(&p_syn->mutex_fork[right]);
		printf("%llu ms %d is taken right fork num is %d\n", get_mstime() - p_syn->start_time, num, right);
		pthread_mutex_lock(&p_syn->mutex_fork[left]);
		printf("%llu ms %d is taken left fork num is %d\n", get_mstime() - p_syn->start_time, num, left);
		printf("%llu ms %d is eating\n", get_mstime() - p_syn->start_time, num);
		usleep(p_syn->info->time_to_eat * 1000);
		p_syn->each_time[temp] = get_mstime() - p_syn->start_time;

		printf("%llu ms %d is sleep\n", get_mstime() - p_syn->start_time, num);
		pthread_mutex_unlock(&p_syn->mutex_fork[left]);
		pthread_mutex_unlock(&p_syn->mutex_fork[right]);

		p_syn->each_count[temp] = p_syn->each_count[temp] + 1;
		//printf("										%d's person's count is %d\n", num, each_count[temp]);

		usleep(p_syn->info->time_to_sleep * 1000);
		printf("%llu ms %d is thinking\n", get_mstime() - p_syn->start_time, num);
	}
	//printf("%d is reached end\n", num);
	return NULL;
}

uint64_t get_mstime()
{
	struct timeval current;
	gettimeofday(&current, NULL);

	return (current.tv_sec * (uint64_t)1000) + (current.tv_usec / 1000);
}
