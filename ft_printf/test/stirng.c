#include <stdio.h>

int main(void)
{
	int *p;
	int num = 5;
	p = &num;

	printf("[%4.3s]", "12345");
	printf("[]\n");
	printf("[%2.3s]", "12345");
	printf("[]\n");
	printf("[%3.7s]", "12345");
	printf("[]\n");
	printf("[%7.7s]", "12345");
	printf("[]");
	return(0);
}
