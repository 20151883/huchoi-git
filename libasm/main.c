#include "libasm.h"
#include <stdio.h>
#include <fcntl.h>
int main(void)
{
	char *str = "my malloc";
	char dd[10];
	//printf("        %s\n", test);
	/*int fd = open("test.txt", O_WRONLY);
	int ret = write(fd, "is done?", 20);
	printf("      %d\n", ret);
	*/
	/*int fd = open ("test.txt", O_RDONLY);
	char *buf = malloc(100);
	int ret = ft_read(fd, buf, 30);
	printf("          %s\n", buf);
	printf("          %d\n", ret);*/
	char *s = "copy is done??";
	char *test =ft_strdup(s);
	printf("            %s\n", test);
	return (0);	
}

