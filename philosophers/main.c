#include "main.h"

void *all_monitor(void *arg)
{
	int flag = 0;
	usleep((p_syn->info->time_to_die / 2) * 1000);
	while (1)
	{
		for (int i = 0;i < p_syn->info->number_of_philosophers; i++)
		{
			if ((get_mstime() - p_syn->start_time) >=  p_syn->each_time[i] + p_syn->info->time_to_die)
			{
				//pthread_mutex_unlock(&p_syn->mutex_fork[left]);
				//pthread_mutex_unlock(&p_syn->mutex_fork[left]);
				printf("current : %llu && last time : %llu\n", get_mstime() - p_syn->start_time, p_syn->each_time[i]);
				printf("gap is : %llu && limit gap is %llu\n", get_mstime() - p_syn->start_time - p_syn->each_time[i], p_syn->info->time_to_die);
				printf("%d is died for starving\n", i + 1);
				int *ret = malloc(sizeof(int));
				*ret = 1;
				p_syn->pthread_flag = 1;
				return ((void *)ret);
			}
			if (p_syn->each_count[i] >= p_syn->info->number_of_times_each_philosopher_must_eat)
			{
				flag++;
			}
		}
		if (flag == p_syn->info->number_of_philosophers)
		{
			int *ret = malloc(sizeof(int));
			*ret = 2;
			p_syn->pthread_flag = 1;
			printf("%llu must eat count reached\n", p_syn->each_time[p_syn->info->number_of_philosophers - 1]);
			return ((void *)ret);
		}
		else
			flag = 0;
		usleep(1000);
	}
}

int main(int argc, char *argv[])
{
	//기본정보저장
	//syn *p_syn  = malloc(sizeof(syn));//잠시보류
	p_syn  = malloc(sizeof(syn));
	p_syn->info = (Info *)malloc(sizeof(Info));//스택영역은 공유가 안되기에...
	ft_init(p_syn->info, argv);
	p_syn->pthread_flag = 0;
	p_syn->start_time = get_mstime();
	p_syn->each_time = malloc(sizeof(uint64_t) * p_syn->info->number_of_philosophers);
	p_syn->each_count = malloc(sizeof(int) * p_syn->info->number_of_philosophers);
	for (int q = 0;q < p_syn->info->number_of_philosophers; q++)
		(p_syn->each_count)[q] = 0;
	for (int i = 0;i < p_syn->info->number_of_philosophers; i++)
		(p_syn->each_time)[i]= get_mstime();
	//개별 쓰레드를 위한 준비작업
	p_syn->mutex_fork = malloc(sizeof(pthread_mutex_t) * p_syn->info->number_of_philosophers);
	pthread_t tid[p_syn->info->number_of_philosophers];
	pthread_t monitor;
	//mutex_init하기
	int i;
	p_syn->lock = malloc(sizeof(pthread_mutex_t));
	p_syn->count_lock =  malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(p_syn->lock, NULL);
	pthread_mutex_init(p_syn->count_lock, NULL);
	for (i=0; i < p_syn->info->number_of_philosophers; i++)
		pthread_mutex_init(&(p_syn->mutex_fork[i]), NULL);
	//쓰레드의 생성
	pthread_create(&(monitor), NULL, all_monitor, NULL);
	i = 0;
	int arr[5];
	while (i < p_syn->info->number_of_philosophers)
	{
		arr[i] = i;
		pthread_create(&(tid[i]), NULL, sub_main, (void *)&arr[i]);
		i++;
	}
	//모든 쓰레드가 종료되기 전에 프로세스가 종료되면 안되니까 기다리게 만드는 작업
	int result;
	pthread_join(monitor, (void *)&result);
	int j = 0;
	while (j < p_syn->info->number_of_philosophers)
		pthread_join(tid[j++], NULL);
	//모든 쓰레드가 종료된 이후에 마무리 작업(쓰레드 자원 해제는 이미 된 상태임)
	int z;
	for (z = 0;z < p_syn->info->number_of_philosophers; z++)
		pthread_mutex_destroy(&(p_syn->mutex_fork[z]));
	pthread_mutex_destroy(p_syn->lock);
	//모든 메모리 할당 해제 해주는 작업
	return 0;
}
