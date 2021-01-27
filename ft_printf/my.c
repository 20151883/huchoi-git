#include <stdio.h>
#include "libft.h"

int	main(void)
{
	//char *temp = calloc(sizeof(char),1);
	//char *temp = malloc(2);
	char temp[2];
	char arr[5];
	*arr = 0;
	*temp = 'a';
	char *why = ft_strjoin(arr, temp);
	printf("%ld",sizeof(temp));
	printf("%s", why);
	printf("??");
	return (0);
}
