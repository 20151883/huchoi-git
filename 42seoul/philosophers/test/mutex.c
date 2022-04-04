#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

pthread_t tid[2];
int counter = 0;
pthread_mutex_t lock;
int *test;

void* trythis(void* arg)
{
	pthread_mutex_lock(&lock);
	unsigned long i = 0;
	if (*(int *)arg == 0)
	{
		for (int i = 0; i < 0x9999; i++)
			*test += 1;
	}
	if (*(int *)arg == 1)
	{
		for (int i = 0; i < 0x9999; i++)
			*test -= 1;
	}
	pthread_mutex_unlock(&lock);
	return NULL;
}

int main(void)
{
	int i = 0;
	int error;
	test = malloc(sizeof(int));
	*test = 0;
	if (pthread_mutex_init(&lock, NULL) != 0) {
		printf("\n mutex init has failed\n");
		return 1;
	}
	int arr[2];
	arr[0] = 0;
	arr[1] = 1;
	while (i < 2) {

		error = pthread_create(&(tid[i]), NULL, &trythis, (void *)&arr[i]);
		//printf("the numbers are .. %lld %lld \n", tid[0], tid[1]);
		if (error != 0)
			printf("\nThread can't be created :[%s]",
				strerror(error));
		i++;
	}
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	pthread_mutex_destroy(&lock);
	printf("%d\n", *test);
	return 0;
}


