#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	unsigned int num = 2147483648;
	ft_printf("[%10.7d]",12345);
	ft_printf("[   0012345]\n");
	ft_printf("[%5.7d]",12345);
	ft_printf("[0012345]\n");
	ft_printf("[%7.3d]",12345);
	ft_printf("[  12345]\n");
	ft_printf("[%4.3d]",12345);
	ft_printf("[12345]\n");
	ft_printf("[%4.3u]\n", 12345);
	printf("[%4.3u]\n",12345);
	ft_printf("[%10.8x]\n", 12345);
	printf("[%10.8x]\n",12345);
	ft_printf("[%-10.8X]\n", 0xffffffff);
	printf("[%-10.8X]\n",0xffffffff);
	ft_printf("[%20.14u]\n", 0xffffffff);
	printf("[%20.14u]\n",0xffffffff);
	ft_printf("[%12.15u]\n", 0xffffffff);
	printf("[%12.15u]\n",0xffffffff);
	ft_printf("[%u]",2147483648);
	printf("[%u]", num);
	ft_printf("[%-0d]",100);
	printf("[%-0d]",100);
	int a = ft_printf(" %d ",0);
	int b = printf(" %d ",0);
	printf(" %d %d ",a,b);
	return (0);
}
