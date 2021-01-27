#include <stdio.h>

int main(void)
{
	printf("[%-.3s]","12345");
	printf("[123]\n");
	printf("[%-4.3s]","12345");
	printf("[123]\n");
	printf("[%-3.6s]","12345");
	printf("[12345 ]\n");
	printf("[%-7.6s]","12345");
	printf("[12345  ]\n");
	return (0);
}
