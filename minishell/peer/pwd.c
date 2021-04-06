#include <unistd.h>
#include <stdio.h>

char *my_read()
{
    char *ret;
    char buf[5];
    int readsize;
    while (1)
    {
        readsize = read(1, buf, 4);
        if (buf[readsize - 1] == EOF)
    }
}

int main(void)
{
    write(1, "MINISHELL>>", 11);
    while (1)
    {
        
        write(1, "MINISHELL>>", 11);
    }
    return (0);
}