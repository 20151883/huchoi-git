#include "ft_printf.h"

int main(void)
{
	ft_printf("[%-.3s]","12345");
	printf("[123]\n");
	ft_printf("[%-4.3s]","12345");
	printf("[123 ]\n");
	ft_printf("[%-3.6s]","12345");
	printf("[12345]\n");
	ft_printf("[%-7.6s]","12345");
	printf("[12345  ]\n");
	return (0);
}
