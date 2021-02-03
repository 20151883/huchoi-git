#include "ft_printf.h"

char *case_d(t_node *p_node, char **line)
{
    int size;//number of character
    int plus;
    int lenth;//buffer lenth excluded the NULL
    char *ret;

    size = ft_strlen(line[5]);
    /*if (ft_atoi(line[5]) < 0)
    {
        char *temp;
        if (ft_atoi(line[3]) > size - 1)
        {
            plus = ft_atoi(line[3]) - (size - 1);
            p_node->is_precision = 0;
            temp = malloc(sizeof(char) * (size + plus + 1));
            temp[size + plus] = '\0';
            ft_memset(temp, '0', size + plus);
            ft_strlcpy(&(temp[plus]), line[5], ft_strlen(line[5]) + 1);
            *(ft_strchr(temp, '-')) = '0';
            temp[0] = '-';
            free(line[5]);
            line[5] = temp;
            printf("test : %s", temp);
            size = size + plus;
            plus = 0;
        }
        else
            plus = 0;
    } */
    //else
    //{
    if (ft_atoi(line[5]) < 0)
    {
        if (ft_atoi(line[3]) > (size - 1))
            plus = ft_atoi(line[3]) - (size - 1);
        else
            plus = 0;
    }
    else
    {
        if (*line[3] != '\0' && size < atoi(line[3]))
            plus = atoi(line[3]) - size;
        else
            plus = 0;
    }
    //}
    lenth = size + plus;
     if (p_node->is_precision == 1)
        check_zero(line, &size, &plus, &lenth);
    if (*line[2] != '\0' && lenth < atoi_positive(line[2]))
        lenth = atoi_positive(line[2]);
    (p_node->count) += lenth;
    //if (*line[3] != '\0') then flag has no power..
    if (p_node->is_precision == 1 && ft_atoi(line[3]) >= 0)
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
    char *temp;

    size = ft_strlen(line[5]);
    if (ft_atoi(line[5]) < 0)
    {
        if (ft_atoi(line[3]) > (size - 1))
            plus = ft_atoi(line[3]) - (size - 1);
        else
            plus = 0;
    }
    else
    {
        if (*line[3] != '\0' && size < atoi(line[3]))
            plus = atoi(line[3]) - size;
        else
            plus = 0;
    }
    lenth = size + plus;
    if (p_node->is_precision == 1)
        check_zero(line, &size, &plus, &lenth);
    if (*atoi_positive != '\0' && lenth < atoi_positive(line[2]))
        lenth = atoi_positive(line[2]);
    (p_node->count) += lenth;
    //if (*line[3] != '\0') then flag has no power..
    if (p_node->is_precision == 1 && ft_atoi(line[3]) >= 0)
        ret = precision_int(line, plus, size, lenth);
    else//precision is nit in line.//plus is zero.. 
        ret = no_precision_int(line, plus, size, lenth);    
    return (ret);
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
    if (*line[2] != '\0' && lenth < atoi_positive(line[2]))
    {
        lenth = atoi_positive(line[2]);
    }
    (p_node->count) += lenth;
    //if (*line[3] != '\0') then flag has no power..
    if (ft_atoi(line[3]) >= 0 && (p_node->is_precision == 1))
        ret = precision_int(line, plus, size, lenth);
    else//precision is nit in line.//plus is zero.. 
        ret = no_precision_int(line, plus, size, lenth);    
    return (ret);
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
    if (*line[2] != '\0' && lenth < atoi_positive(line[2]))
    {
        lenth = atoi_positive(line[2]);
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
    if (*line[2] != '\0' && lenth < atoi_positive(line[2]))
    {
        lenth = atoi_positive(line[2]);
    }
    (p_node->count) += lenth;
    //if (*line[3] != '\0') then flag has no power..
    if (*line[3] != '\0' || (p_node->is_precision == 1))
        ret = precision_int(line, plus, size, lenth);
    else//precision is nit in line.//plus is zero.. 
        ret = no_precision_int(line, plus, size, lenth);    
    return (ret);
}
