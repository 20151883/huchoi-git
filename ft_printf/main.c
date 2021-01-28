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
	return (0);
}
