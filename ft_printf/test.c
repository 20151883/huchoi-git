#include <stdio.h>
#include "libft.h"
int main(void)
{
	char *arr = "cspdiuxX%";
	char ch = '-';
	if(ft_strchr("cspdiuxX%", ch) != 0)
		printf("done");
	else if (ft_strchr("cspdiuxX%", ch) == 0)
		printf("not");
	return (0);
}
