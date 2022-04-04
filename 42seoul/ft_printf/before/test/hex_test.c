#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int num = 0xabcd;
	ft_printf("%x\n", num);
	printf("%x\n", num);
	ft_printf("%x\n",0x1234a);
	printf("%x\n",0x1234a);
	return (0);
}
