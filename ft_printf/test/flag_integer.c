#include <stdio.h>
#include "ft_printf.h"
int main(void)
{
	ft_printf("[%-4.7d]",12345);
	printf("[0012345]\n");
	ft_printf("[%010.7d]",12345);
	printf("[   0012345]\n");
	ft_printf("[%-10.7d]",12345);
	ft_printf("[0012345   ]\n");
//	printf("[%-010.7d]",12345);
//	printf("[]\n");
	ft_printf("[%-7.3d]",12345);
	printf("[12345  ]\n");
	ft_printf("[%010.3d]",12345);
	printf("[     12345]\n");
	ft_printf("[%010d]",12345);
	printf("[0000012345]");
	return (0);
}
