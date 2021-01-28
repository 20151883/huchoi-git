#include <stdio.h>
#include "ft_printf.h"
int main(void)
{
	printf("%s\n", ten_small_hex("1234567"));
	printf("%x\n", 1234567);
	printf("%s\n",ten_big_hex("2147483647"));
	printf("%X\n",2147483647);
	printf("%s\n",ten_big_hex("-2147483647"));
	printf("%X\n",-2147483647);
	return (0);
}
