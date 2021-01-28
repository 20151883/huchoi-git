#include "ft_printf.h"

char *case_c(char **line)//dot procedure is needed
{
    int size;
    char *ret;
    int idx;

    if (ft_strchr(line[1], '0') != 0 || *line[3] != '\0')//error처리
        return (0);
    if (*line[2] != '\0')
        size = ft_atoi(line[2]);
    else
        size = 1;
    ret = malloc(sizeof(char) * (size + 1));//[0] ~ [size-1]
	ret[size] = '\0';
    idx = 0;
    while(idx < size)
        ret[idx++] = ' ';
    if (ft_strchr(line[1], '-') != 0)
        ret[0] = *line[5];
    else
        ret[size - 1] = *line[5];
	printf("\n\n%c\n\n",*line[5]);
    return (ret);
}

char *case_p(char **line)
{
    return (0);
}
char *case_s(char **line)
{
    return (0);
}
char *case_percent(char **line)
{
    return (0);
}
