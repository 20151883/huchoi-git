#include <stdio.h>

int main(void)
{
	printf("[%-010.5%]\n");//in genalral case flag,  -,0 can not co-work(it means error!!!)alike c,s,p can not co-work with 0 flag(this is also error
	printf("[%%         ]");         
	return (0);
}
