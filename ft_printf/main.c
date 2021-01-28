#include "ft_printf.h"

int main(void)
{
	ft_printf("[%-10c]\n",'z');
	printf("[%-10.c]\n",'z');
	ft_printf("[%s]\n","is it work?");
	printf("[%s]\n","is it sork?");
	ft_printf("[%10.5s]\n","is it work?");
	printf("[%10.5s]\n","is it sork?");
	ft_printf("[%-10.5s]\n","is it work?");
	printf("[%-10.5s]\n","is it sork?");
	ft_printf("[%-10.20s]\n","is it work?");
	printf("[%-10.20s]\n","is it sork?");
	ft_printf("[%2.5s]\n","is it work?");
	printf("[%2.5s]\n","is it sork?");
	ft_printf("[%30.20s]\n","is it work?");
	printf("[%30.20s]\n","is it sork?");
	printf("\n\n\n\n");
	ft_printf("[%d]\n",12345);
	printf("[%d]\n",12345);
	ft_printf("[%-10.8d]\n",12345);
	printf("[%-10.8d]\n",12345);
	ft_printf("[%10.3d]\n",12345);
	printf("[%10.3d]\n",12345);
	ft_printf("[%-3.5d]\n",12345);
	printf("[%-3.5d]\n",12345);
	return (0);
}
