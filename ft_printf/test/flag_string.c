#include <stdio.h>

int main(void)
{
	printf("[%-.3s]","12345");
	printf("[123]");
	printf("[%-4.3s]","12345");
	printf("[123 ]");
	printf("[%-3.6s]","12345");
	printf("[12345]");
	printf("[%-7.6s]","12345");
	printf("[12345  ]");
	return (0);
}
