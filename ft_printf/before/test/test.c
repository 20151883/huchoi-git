#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	/*ft_printf("[%.x][%.X][%.u]\n",0xfffffff4,0xfffffff4,0xfffff);
	printf("[%-2x]\n\n\n\n", '\0');
	ft_printf("[%02X]",0);
	char *test = "ancd";
	ft_printf("[%8p]\n",test);
	printf("[%8p]\n",test);
	ft_printf("[%%%d]",4200);
	printf("[%%%d]",4200);*/
	//ft_printf("[%c]",NULL);
	//printf("[%c]",NULL);
	char *ptr = "abcd";
	//ft_printf("[%18p]\n",ptr);
	//printf("[%18p]\n",ptr);
	printf("[%10p]\n",NULL);
	printf("[%-20.p]\n", NULL);
	printf("[%-20.p]\n", "abcd");
	ft_printf("[%*p]\n",-10, NULL);
	ft_printf("[%*.p]\n",10,  NULL);
	ft_printf("[%*p]\n",20,  "abcd");


	//ft_printf("%3.0X",15);
	return (0);
}
