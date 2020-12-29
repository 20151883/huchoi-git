#include <stdlib.h>
#include <stdio.h>
static char *ft_itoa(int n)
{
        char arr[12];
        int idx;
        int nb;
        char *ret;

        nb = n;
        if(nb < 0)
                nb = nb * (-1);
        idx = 0;
        while(nb / 10)
        {
                arr[idx++] = (nb % 10) + '0';
                nb = nb / 10;
        }
        arr[idx] = (nb % 10) + '0';
        if(nb < 0)
                arr[++idx] = '-';
        ret = (char *)malloc(sizeof(char) * (idx+1));
        nb = 0;
        while(idx >= 0)
                ret[nb++] = arr[idx--];
        ret[nb] = '\0';
        return (ret);
}

int main(void)
{
	int nb = 12345678;
	char *arr;
	arr = ft_itoa(nb);
	printf("%c\n%c\n%c\n", arr[0], arr[1], arr[2]);
	printf("%s\n",arr);
	return (0);
}
