#include <stdio.h>
#include <string.h>

int main(void)
{
	int num = 42;
	char arr[7];

	strcpy(arr, "string");
	printf("%08.5d\n",num);
//	printf("%05.10s\n", arr);
    printf("%-3.5s\n",arr);
    printf("%-6.3s\n",arr);
    printf("%-8.6s\n",arr);
    printf("%-8.8s\n",arr);
	return(0);
}

