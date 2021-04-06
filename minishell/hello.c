#include <unistd.h>
#include <stdio.h>

int main(void)
{
    printf("hello");
    write(1, "world", 5);
    return (0);
}