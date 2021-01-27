#include "libft.h"
%만났을때
int what_case(char c)
{
    char *arr;

    arr = malloc(10);
    ft_strcpy(arr, "cspdiuxX%");
    if (c == '-' || c == '0')
        return (1);
    if('1' < c && c < '9')
        return (2)
    if(c == '.')
        return (3);
    if (ft_strchr(arr, c) != 0)
        return (5);
    return (-1);
}