#include <string.h>
#include <stdio.h>
int main(void)
{
    int i = 10;
    char arr[100] = "test0is0test";
    char *ptr = arr;
    char *p = strsep(&ptr, "0");
    while (p != NULL && i--)
    {
        printf("%s\n", p);
        printf("%p\n", p);
        printf("%s\n", ptr);
        char *p = strsep(&ptr, "0");
    }
    return (0);
}