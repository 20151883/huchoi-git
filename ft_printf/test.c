#include <stdio.h>
#include "libft.h"
int main(void)
{
	char *arr = "cspdiuxX%";
	if(ft_strchr(arr, '-')!= NULL)
		printf("done");
	else
		printf("not");
	return (0);
}
