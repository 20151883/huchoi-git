#include <stdio.h>

int main(void)
{
	printf("[%-.3s]","12345");
	printf("[]\n");
	printf("[%-4.3s]","12345");
	printf("[]\n");
	printf("[%-3.6s]","12345");
	printf("[]\n");
	printf("[%-7.6s]","12345");
	printf("[]\n");
	return (0);
}
