#include <stdio.h>

int main(void)
{
	printf("[%-4.7d]",12345);
	printf("[0012345]\n");
	printf("[%-4.7d]",12345);
	printf("[0012345]\n");
	printf("[%010.7d]",12345);//i think this is not error...
	printf("[   0012345]\n");//space is default buf flag 0 can change!!! no... precision is defeated... so flag 0 has no power...!
	//brfore argument is not correct... if prcision is exist the flag 0 can not have power (this is correct!!!!!!!)
	printf("[%-10.7d]",12345);
	printf("[0012345   ]\n");
//	printf("[%-010.7d]",12345);
//	printf("[]\n");
	printf("[%-7.3d]",12345);
	printf("[12345  ]\n");
	printf("[%010.3d]",12345);
	printf("[     12345]\n");
	printf("[%010d]",12345);//precision is not here, so flag 0 has power
	printf("[0000012345]");
	return (0);
}
