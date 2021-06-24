#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>
#include <string.h>
#include <sys/time.h>

typedef struct Info{
	int			number_of_philosophers;
	suseconds_t time_to_die;
	suseconds_t time_to_eat;
	suseconds_t time_to_sleep;
	int			number_of_times_each_philosopher_must_eat;
}Info;

pthread_mutex_t *mutex_fork;
pthread_mutex_t *lock;
Info *info;

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
	int i = 0;
	int temp = *((int *)arg);
	int max =  0 - info->number_of_times_each_philosopher_must_eat;
	struct timeval mytime;
	while (max++)
	{
		gettimeofday(&mytime, NULL);
		usleep((temp % 2) * info->time_to_eat);
		printf("%d ms %d is taken fork\n", mytime.tv_usec, temp + 1);
		printf("%d ms %d is taken fork\n", mytime.tv_usec, temp + 1);
		pthread_mutex_lock(&mutex_fork[temp]);
		gettimeofday(&mytime, NULL);
		printf("%d ms %d is eating\n", mytime.tv_usec, temp + 1);
		usleep(info->time_to_eat);
		//p_ingo->time_to_die 의 값은 모니터 쪽에서 참조할 예정임.
		printf("%d\n", temp + 1);
		pthread_mutex_unlock(&mutex_fork[temp]);
		//
		gettimeofday(&mytime, NULL);
		printf("%d ms %d is thinking\n", mytime.tv_usec, temp);
		usleep(info->time_to_sleep);
	}
	return NULL;
}
