#include <stdio.h>

int main(void)
{
	printf("[%10.7d]",12345);
	printf("[0000012345]\n");
	printf("[%5.7d]",12345);
	printf("[12345]\n");
	printf("[%7.3d]",12345);
	printf("[  12345]\n");
	printf("[%4.3d]",12345);
	printf("[12345]\n");
	return (0);
}
