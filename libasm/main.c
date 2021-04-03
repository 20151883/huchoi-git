#include "libasm.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	/*char *str = "0";
	printf("ft_strlen(str) = %d\n", ft_strlen(str));*/
	
	char *str = "copy is done?";
	char dd[30];
	ft_strcpy(dd, str);
	printf("dd = %s\n", dd);

	/*char *num_arr = "123456789";
	printf(" ft_strcmp(num_arr) = %d\n", ft_strcmp(num_arr, "123456789"));*/
	
	/*int fd = open("test.txt", O_WRONLY);
	int ret = write(fd, "is done?", 20);
	printf("      %d\n", ret);*/

	/*int fd = open ("test.txt", O_RDONLY);
	char *buf = malloc(100);
	int ret = ft_read(fd, buf, 30);
	printf("          %s\n", buf);
	printf("          %d\n", ret);*/

	char *src= "duplicate is done?";
	printf("result of ft_strdup : %s\n", ft_strdup(src));
	return (0);	
}

