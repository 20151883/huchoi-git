#include <stdio.h>
#include "ft_printf.h"
int main(void)
{
	ft_printf("[%10.5%]\n");
	ft_printf("[         %%]\n");
	ft_printf("[%010%]\n");
	ft_printf("[000000000%%]\n");
	ft_printf("[%010.5%]\n");
	ft_printf("[000000000%%]\n");
	ft_printf("[%.5%]\n");
	ft_printf("[%%]\n");
	ft_printf("[%-0.100%]\n");
	ft_printf("[%%]\n");
	ft_printf("[%-5%]\n");
	ft_printf("[%%    ]\n");
	return (0);
}
