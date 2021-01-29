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
    if (*line[3] != '\0' && size < atoi(line[3]))
        plus = atoi(line[3]) - size;
    else
        plus = 0;
    lenth = size + plus;
    if (*line[2] != '\0' && lenth < atoi(line[2]))
    {
        lenth = atoi(line[2]);
    }
    //if (*line[3] != '\0') then flag has no power..
    if (*line[3] != '\0')
        ret = no_precision_int(line, plus, size, lenth);
    else//precision is nit in line.//plus is zero.. 
        ret = precision_int(line, plus, size, lenth);    
    return (ret);
}
char *case_i(char **line)
{
        int size;//number of character
    int plus;
    int lenth;//buffer lenth excluded the NULL
    char *temp;
    char *ret;
    int i = 0;

    size = ft_strlen(line[5]);
    if (*line[3] != '\0' && size < atoi(line[3]))
        plus = atoi(line[3]) - size;
    else
        plus = 0;
    lenth = size + plus;
    if (*line[2] != '\0' && lenth < atoi(line[2]))
    {
        lenth = atoi(line[2]);
    }
    //if (*line[3] != '\0') then flag has no power..
    if (*line[3] != '\0')
        ret = no_precision_int(line, plus, size, lenth);
    else//precision is nit in line.//plus is zero.. 
        ret = precision_int(line, plus, size, lenth);    
    return (ret);
    return (0);
}
char *case_u(char **line)
{
    int size;//number of character
    int plus;
    int lenth;//buffer lenth excluded the NULL
    char *temp;
    char *ret;
    int i = 0;

    size = ft_strlen(line[5]);
    if (*line[3] != '\0' && size < atoi(line[3]))
        plus = atoi(line[3]) - size;
    else
        plus = 0;
    lenth = size + plus;
    if (*line[2] != '\0' && lenth < atoi(line[2]))
    {
        lenth = atoi(line[2]);
    }
    //if (*line[3] != '\0') then flag has no power..
    if (*line[3] != '\0')
        ret = no_precision_int(line, plus, size, lenth);
    else//precision is nit in line.//plus is zero.. 
        ret = precision_int(line, plus, size, lenth);    
    return (ret);
    return (0);
}
char *case_x(char **line)
{
    int size;//number of character
    int plus;
    int lenth;//buffer lenth excluded the NULL
    char *temp;
    char *ret;
    int i = 0;

    line[5] = ten_small_hex(line[5]);//malloc
    size = ft_strlen(line[5]);
    if (*line[3] != '\0' && size < atoi(line[3]))
        plus = atoi(line[3]) - size;
    else
        plus = 0;
    lenth = size + plus;
    if (*line[2] != '\0' && lenth < atoi(line[2]))
    {
        lenth = atoi(line[2]);
    }
    //if (*line[3] != '\0') then flag has no power..
    if (*line[3] != '\0')
        ret = no_precision_int(line, plus, size, lenth);
    else//precision is nit in line.//plus is zero.. 
        ret = precision_int(line, plus, size, lenth);    
    return (ret);
    return (0);
}
char *case_X(char **line)
{
        int size;//number of character
    int plus;
    int lenth;//buffer lenth excluded the NULL
    char *temp;
    char *ret;
    int i = 0;

    line[5] = ten_big_hex(line[5]);
    size = ft_strlen(line[5]);
    if (*line[3] != '\0' && size < atoi(line[3]))
        plus = atoi(line[3]) - size;
    else
        plus = 0;
    lenth = size + plus;
    if (*line[2] != '\0' && lenth < atoi(line[2]))
    {
        lenth = atoi(line[2]);
    }
    //if (*line[3] != '\0') then flag has no power..
    if (*line[3] != '\0')
        ret = no_precision_int(line, plus, size, lenth);
    else//precision is nit in line.//plus is zero.. 
        ret = precision_int(line, plus, size, lenth);    
    return (ret);
    return (0);
}
