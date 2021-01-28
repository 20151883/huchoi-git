#include <stdio.h>
#include "ft_printf.h"
int main(void)
{
	int *p;
	int num = 5;
	p = &num;

	ft_printf("[%4.3s]", "12345");
	printf("[ 123]\n");
	ft_printf("[%2.3s]", "12345");
	printf("[123]\n");
	ft_printf("[%3.7s]", "12345");
	printf("[12345]\n");
	ft_printf("[%7.7s]", "12345");
	printf("[  12345]");
	return(0);
}
