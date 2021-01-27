#include <stdio.h>

int main(void)
{
	int *p;
	int num = 5;
	p = &num;

	printf("[%4.3s]", "12345");
	printf("[ 123]\n");
	printf("[%2.3s]", "12345");
	printf("[123]\n");
	printf("[%3.7s]", "12345");
	printf("[12345]\n");
	printf("[%7.7s]", "12345");
	printf("[  12345]");
	return(0);
}
