#include "main.h"

void init_shell(void)
{
    char user_naem = getenv("USER");
    pritnf("user name is : %s", user_name);
}

void put_prompt(void)
{
    printf("this is test prompt");
}