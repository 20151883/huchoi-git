#include <stdio.h>
#include <string.h>

int main(void)
{
	int num = 42;
	char arr[7];

	strcpy_s(arr,7, "string");
	printf("%-08.5d\n",num);
	printf("%0-5.10s\n", arr);
    printf("%-3.5s\n",arr);
    printf("%-6.3s\n",arr);
    printf("%-8.6s\n",arr);
    printf("%s-8.8s\n",arr);
	return(0);
}
