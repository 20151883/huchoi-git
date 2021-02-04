#include "includes/ft_printf.h"

char *case_d(t_node *p_node, char **line)
{
    int size;//number of character
    int plus;
    int lenth;//buffer lenth excluded the NULL
    char *ret;

    manage_minus_integer(p_node, line, &size, &plus);
    lenth = size + plus;
     if (p_node->is_precision == 1)
        check_zero(line, &size, &plus, &lenth);
    if (*line[2] != '\0' && lenth < atoi_positive(line[2]))
        lenth = atoi_positive(line[2]);
    (p_node->count) += lenth;
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

    manage_minus_integer(p_node, line, &size, &plus);
    lenth = size + plus;
    if (p_node->is_precision == 1)
        check_zero(line, &size, &plus, &lenth);
    if (*line[2] != '\0' && lenth < atoi_positive(line[2]))
        lenth = atoi_positive(line[2]);
    (p_node->count) += lenth;
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
        lenth = atoi_positive(line[2]);
    (p_node->count) += lenth;
    if (ft_atoi(line[3]) >= 0 && (p_node->is_precision == 1))
        ret = precision_unsigned(line, plus, size, lenth);
    else//precision is nit in line.//plus is zero.. 
        ret = no_precision_unsigned(line, plus, size, lenth);    
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
    if (p_node->is_precision == 1 && size <= 1)
        check_zero(line, &size, &plus, &lenth);
    if (*line[2] != '\0' && lenth < atoi_positive(line[2]))
        lenth = atoi_positive(line[2]);
    (p_node->count) += lenth;
    if (ft_atoi(line[3]) >= 0 && (p_node->is_precision == 1))
        ret = precision_unsigned(line, plus, size, lenth);
    else//precision is nit in line.//plus is zero.. 
        ret = no_precision_unsigned(line, plus, size, lenth);    
    return (ret);
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
    if (p_node->is_precision == 1 && size <= 1)
        check_zero(line, &size, &plus, &lenth);
    if (*line[2] != '\0' && lenth < atoi_positive(line[2]))
        lenth = atoi_positive(line[2]);
    (p_node->count) += lenth;
    if (ft_atoi(line[3]) >= 0 && (p_node->is_precision == 1))
        ret = precision_unsigned(line, plus, size, lenth);
    else//precision is nit in line.//plus is zero.. 
        ret = no_precision_unsigned(line, plus, size, lenth);    
    return (ret);
}
