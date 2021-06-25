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
	struct timeval start_time;
}Info;

pthread_mutex_t *mutex_fork;
pthread_mutex_t *lock;
struct timeval *each_time;

Info *info;

void ft_init(Info *p_info, char **argv)
{//is digit 활용 잘 해야할듯..
	gettimeofday(&p_info->start_time, NULL);
	p_info->number_of_philosophers = atoi(argv[1]);
	p_info->time_to_die = (suseconds_t)atoi(argv[2]);
	p_info->time_to_eat = (suseconds_t)atoi(argv[3]);
	p_info->time_to_sleep = (suseconds_t)atoi(argv[4]);
	if (argv[5] != NULL)
		p_info->number_of_times_each_philosopher_must_eat = atoi(argv[5]);
	else
		p_info->number_of_times_each_philosopher_must_eat = -1;
}
void *sub_pthread(void *arg)
{
	struct timeval *time = (struct timeval *)arg;
	struct timeval current;
	while (1)
	{
		gettimeofday(&current, NULL);
		if (current.tv_sec - time->tv_sec >= info->time_to_die)
		{
			//시그널??
			return ((void *)NULL);
		}
		usleep(1000);
	}
}
void *sub_main(void *arg)
{
	int temp = *((int *)arg);
	struct timeval mytime;
	gettimeofday(&mytime, NULL);
	int i = 0;

	int num = temp + 1;
	int max =  0 - info->number_of_times_each_philosopher_must_eat;

	int left, right;//n번째 철학자의 오른쪽의 포크는 fork[n], 왼쪽의 포크는 fork[n-1]
	right = num == info->number_of_philosophers ? 0 : num;
	left = num - 1;
	if (temp % 2 == 1)
		usleep((temp % 2) * info->time_to_eat);
	/*if (num == info->number_of_philosophers && num % 2 == 0)
		usleep((temp % 2) * info->time_to_eat);*/

	long hungry_time;
	long eated_time = 0;//식사를 한 직후의 시점
	while (max++)
	{
		//usleep((temp % 2) * info->time_to_eat);//이건 아마도 처음에 한번만 해주면 될듯?
		gettimeofday(&mytime, NULL);
		//hungry_time = mytime.tv_sec -

		pthread_mutex_lock(&mutex_fork[right]);//뮤텍스락을 건다면 모두 여기서 다 같이 걸어주어야함.
		pthread_mutex_lock(&mutex_fork[left]);
		gettimeofday(&mytime, NULL);
		printf("%d ms %d is taken fork\n", mytime.tv_usec - info->start_time.tv_usec, num);
		//p_ingo->time_to_die 의 값은 모니터 쪽에서 참조할 예정임.
		//printf("%d\n", temp + 1);

		//gettimeofday(&mytime, NULL);
		printf("%d ms %d is taken fork\n", mytime.tv_usec - info->start_time.tv_usec, num);
		printf("%d ms %d is eating\n", mytime.tv_usec - info->start_time.tv_usec, num);
		usleep(info->time_to_eat);
		gettimeofday(&mytime, NULL);
		each_time[temp].tv_sec = mytime.tv_sec;
		printf("%d ms %d is sleep\n", mytime.tv_usec - info->start_time.tv_usec, num);
		pthread_mutex_unlock(&mutex_fork[left]);
		pthread_mutex_unlock(&mutex_fork[right]);

		usleep(info->time_to_sleep);
		gettimeofday(&mytime, NULL);
		printf("%d ms %d is thinking\n", mytime.tv_usec - info->start_time.tv_usec, num);
		//usleep(300)//이 값을 계산해야하는지...? 여기서 usleep()안해도 될듯
	}
	printf("%d is reached end\n", num);
	return NULL;
}
