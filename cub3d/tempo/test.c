#include <stdio.h>
#include "get_next_line.h"
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h>

int main(void)
{
    char *arr = "100,";
    printf("%d\n", atoi(arr));
    return (0);
}