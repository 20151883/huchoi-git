#include <stdio.h>

int main(void)
{
	printf("[%-4.7d]",12345);
	printf("[0012345]\n");
	printf("[%010.7d]",12345);
	printf("[0000012345]\n");
	printf("[%-10.7d]",12345);
	printf("[0012345   ]\n");
//	printf("[%-010.7d]",12345);
//	printf("[]\n");
	printf("[%-7.3d]",12345);
	printf("[12345  ]\n");
	printf("[%010.3d]",12345);
	printf("[0000012345]\n");
	printf("[%010d]",12345);
	printf("[0000012345]");
	return (0);
}
