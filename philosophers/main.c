#include "main.h"

void *all_monitor(void *arg)
{
	struct timeval current;
	while (1)
	{
		gettimeofday(&current, NULL);
		for (int i = 0;i < info->number_of_philosophers; i++)
		{
			if (current.tv_sec - each_time[i].tv_sec >= info->time_to_die * 10000000)
			{
				printf("current : %ld\neach_time : %ld info->time_to_die : %d\n", current.tv_sec, each_time[i].tv_sec, info->time_to_die * 10000000);
				//시그널??
				printf("he is died for starving\n");
				return ((void *)NULL);
			}
		}
		usleep(1000);
	}
}

int main(int argc, char *argv[])
{
	//기본정보저장
	info = (Info *)malloc(sizeof(Info));//스택영역은 공유가 안되기에...
	ft_init(info, argv);
	each_time = malloc(sizeof(struct timeval) + info->number_of_philosophers);
	struct timeval test;
	gettimeofday(&test, NULL);
	for (int i = 0;i < info->number_of_philosophers; i++)
	{
		each_time[i].tv_sec = test.tv_sec;
	}
	pthread_t monitor;
	pthread_create(&(monitor), NULL, all_monitor, NULL);
	pthread_detach(monitor);
	//개별 쓰레드를 위한 준비작업
	mutex_fork = malloc(sizeof(pthread_mutex_t) * info->number_of_philosophers);
	pthread_t tid[info->number_of_philosophers];
	//mutex_init하기
	int i;
	lock = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(lock, NULL);
	for (i=0; i < info->number_of_philosophers; i++)
		pthread_mutex_init(&mutex_fork[i], NULL);
	//쓰레드의 생성
	i = 0;
	int arr[5];
	while (i < info->number_of_philosophers)
	{
		arr[i] = i;
		pthread_create(&(tid[i]), NULL, sub_main, (void *)&arr[i]);
		i++;
	}
	//모든 쓰레드가 종료되기 전에 프로세스가 종료되면 안되니까 기다리게 만드는 작업
	int j = 0;
	while (j < info->number_of_philosophers)
		pthread_join(tid[j++], NULL);
	//모든 쓰레드가 종료된 이후에 마무리 작업(쓰레드 자원 해제는 이미 된 상태임)
	int z;
	for (z = 0;z < info->number_of_philosophers; z++)
		pthread_mutex_destroy(&mutex_fork[z]);
	return 0;
}
