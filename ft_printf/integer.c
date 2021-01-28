#include "ft_printf.h"

char *case_d(char **line)
{
    int size;//number of character
    int plus;
    int lenth;//buffer lenth excluded the NULL
    char *temp;
    char *ret;
    int i = 0;

    size = ft_strlen(line[5]);
    plus = 0;
    if (*line[3] != '\0' && size < atoi(line[3])
        plus = atoi(line[3]) - size;
    lenth = size + plus;
    if (*line[2] != '\0' && lenth < atoi(line[2]))
    {
        lenth = atoi(line[2]);
    }
    ret = malloc(sizeof(char) * (lenth + 1));
    //if (*line[3] != '\0') then flag has no power..
    ret[lenth] = '\0';
    if (*line[3] != '\0')
    {
        ft_memset(ret, ' ', lenth);
        if (ft_strchr(line[1], '-') != 0)
        {
            while(i<plus)
                ret[i++] = '0'
            while(i<plus + size)
                ft_strlcpy(&ret[i], line[5], size + 1);
            ret[i + size] = ' ';
        }
        else
        {
            i = lenth - size - plus;
            while(i < lenth - size)
                rer[i++] = '0';
            ft_strlcpy(&ret[i], line[5], size + 1);
        }
    }
    else//precision is nit in line.//plus is zero.. 
    {
        if (ft_strchr(line[1], '0') != '0')
            ft_memset(ret, '0', lenth);
        else
            ft_memset(ret, ' ', lenth);
        if (ft_strchr(line[1), '-')
        {
            ft_strlcpy(ret, line[5], size + 1);
            if (ft_strchr(line[1], '0') != 0)
                ret[size] = 0;
            else
                ret[size] = ' ';
        }
        else//right sort
        {
            ft_strlcpy(&ret[lenth - size], line[5], size + 1);
        }
    }
    return (ret);
}
char *case_i(char **line)
{
    return (0);
}
char *case_u(char **line)
{
    return (0);
}
char *case_x(char **line)
{
    return (0);
}
char *case_X(char **line)
{
    return (0);
}