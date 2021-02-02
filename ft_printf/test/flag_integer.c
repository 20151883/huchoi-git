#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int num1,num2;
	char *arr = "abcd";
	unsigned int num3 = 2147483647;
	ft_printf("[%-4.7d]",12345);
	printf("[0012345]\n");
	ft_printf("[%010.7d]",12345);
	printf("[   0012345]\n");
	ft_printf("[%-10.7d]",12345);
	ft_printf("[0012345   ]\n");
//	printf("[%-010.7d]",12345);
//	printf("[]\n");
	ft_printf("[%-7.3d]\n",12345);
	printf("[12345  ]\n");
	ft_printf("[%010.3d]\n",12345);
	printf("[     12345]\n");
	ft_printf("[%010d]\n",12345);
	printf("[0000012345]\n");
	num1=ft_printf("[%0d]\n", -12345);
	num2=printf("[%0d]\n", -12345);
	printf("%d %d",num1, num2);
	ft_printf("[%x %x]", 0xaaff, 2147483647);
	ft_printf("[%x %x %d %X %p]\n",0xaaff, 2147483647, 100, 2147483647, arr);
	printf("[%x %x %u %X %p]\n",0xaaff, 2147483647, num3, 2147483647, arr);
	return (0);
}
