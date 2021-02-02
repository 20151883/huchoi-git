#include "ft_printf.h"

char *case_d(t_node *p_node, char **line)
{
    int size;//number of character
    int plus;
    int lenth;//buffer lenth excluded the NULL
    char *ret;

    size = ft_strlen(line[5]);
    if (*line[3] != '\0' && size < atoi(line[3]))
        plus = atoi(line[3]) - size;
    else
        plus = 0;
    lenth = size + plus;
     if (p_node->is_precision == 1)
        check_zero(line, &size, &plus, &lenth);
    if (*line[2] != '\0' && lenth < atoi(line[2]))
        lenth = atoi(line[2]);
    (p_node->count) += lenth;
    //if (*line[3] != '\0') then flag has no power..
    if (*line[3] != '\0' || (p_node->is_precision == 1))
        ret = precision_int(line, plus, size, lenth);
    else//precision is nit in line.//plus is zero.. 
        ret = no_precision_int(line, plus, size, lenth);    
    return (ret);
}

char *case_i(t_node *p_node, char **line)
{
    int size;//number of character
    int plus;
    int lenth;//buffer lenth excluded the NULL
    char *ret;

    size = ft_strlen(line[5]);
    if (*line[3] != '\0' && size < atoi(line[3]))
        plus = atoi(line[3]) - size;
    else
        plus = 0;
    lenth = size + plus;
     if (p_node->is_precision == 1)
        check_zero(line, &size, &plus, &lenth);
    if (*line[2] != '\0' && lenth < atoi(line[2]))
    {
        lenth = atoi(line[2]);
    }
    (p_node->count) += lenth;
    //if (*line[3] != '\0') then flag has no power..
    if (*line[3] != '\0' || (p_node->is_precision == 1))
        ret = precision_int(line, plus, size, lenth);
    else//precision is nit in line.//plus is zero.. 
        ret = no_precision_int(line, plus, size, lenth);    
    return (ret);
    return (0);
}

char *case_u(t_node *p_node, char **line)
{
    int size;//number of character
    int plus;
    int lenth;//buffer lenth excluded the NULL
    char *ret;

    size = ft_strlen(line[5]);
    if (*line[3] != '\0' && size < atoi(line[3]))
        plus = atoi(line[3]) - size;
    else
        plus = 0;
    lenth = size + plus;
     if (p_node->is_precision == 1)
        check_zero(line, &size, &plus, &lenth);
    if (*line[2] != '\0' && lenth < atoi(line[2]))
    {
        lenth = atoi(line[2]);
    }
    (p_node->count) += lenth;
    //if (*line[3] != '\0') then flag has no power..
    if (*line[3] != '\0' || (p_node->is_precision == 1))
        ret = precision_int(line, plus, size, lenth);
    else//precision is nit in line.//plus is zero.. 
        ret = no_precision_int(line, plus, size, lenth);    
    return (ret);
    return (0);
}

char *case_x(t_node *p_node, char **line)
{
    int size;//number of character
    int plus;
    int lenth;//buffer lenth excluded the NULL
    char *ret;

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
    (p_node->count) += lenth;
    //if (*line[3] != '\0') then flag has no power..
    if (*line[3] != '\0' || (p_node->is_precision == 1))
        ret = precision_int(line, plus, size, lenth);
    else//precision is nit in line.//plus is zero.. 
        ret = no_precision_int(line, plus, size, lenth);    
    return (ret);
    return (0);
}

char *case_X(t_node *p_node, char **line)
{
    int size;//number of character
    int plus;
    int lenth;//buffer lenth excluded the NULL
    char *ret;

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
    (p_node->count) += lenth;
    //if (*line[3] != '\0') then flag has no power..
    if (*line[3] != '\0' || (p_node->is_precision == 1))
        ret = precision_int(line, plus, size, lenth);
    else//precision is nit in line.//plus is zero.. 
        ret = no_precision_int(line, plus, size, lenth);    
    return (ret);
    return (0);
}
