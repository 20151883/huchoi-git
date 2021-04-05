#include <string.h>
#include <stdio.h>

int main(void)
{
    //char *str = "deli0is0zero0"; 이렇게 리터럴 형으로 적으면 버스에러남
    char str[100] = "deli0is0zero0";
    char *p_tok = strtok(str, "0");
    while (p_tok != NULL)
    {
        printf("%s\n", p_tok);
        p_tok = strtok(NULL, "0");
    }
    return (0);
}