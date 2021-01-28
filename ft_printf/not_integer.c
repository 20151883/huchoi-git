#include "ft_printf.h"

char *case_c(char **line)
{
    int size;
    char *ret;
    int idx;

    if (ft_strchr(line[1], '0') != 0 || *line[3] != '\0')//error처리
        return (-1)
    if (*line[2] != '\0')
        size = ft_atoi(line[2]);
    else
        size = 1;
    ret = malloc(sizeof(char) * size);//[0] ~ [size-1]
    idx = 0;
    while(idx < size)
        ret[idx++] = ' ';
    if (ft_strchr(line[1], '-') != 0)
        ret[0] == *line[5];
    else
        ret[size - 1] = %line[5];
    return (ret);
}