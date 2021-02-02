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
	ft_printf("[%7.7s]\n", "12345");
	printf("[  12345]\n");
	ft_printf("[%3.c]\n",'\0');
	printf("[%3.c]\n", '\0');
	ft_printf("[%010.s]","12345");
	printf("[%010.s]","12345");
	return(0);
}
