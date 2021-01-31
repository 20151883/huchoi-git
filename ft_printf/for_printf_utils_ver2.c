#include "ft_printf.h"

int complete_final(char **line, int *p_my_case, char **p_temp)
{
    if (0 == (line[*p_my_case] = ft_strdup(*p_temp)))
        return (free_ret_zero(line, *p_temp, 0));
    (*p_my_case)++;
    while(*p_my_case < 5)
    {
        if (0 == (line[*p_my_case] = ft_strdup("")))
            return (free_ret_zero(line, *p_temp, 0));
        (*p_my_case)++;
    }
    ft_memset(*p_temp, '\0', ft_strlen(*p_temp) + 1);
    **p_temp = '\0';
    return (1);
}

//***********************************************************
int inter_type(char **line, char **p_temp, unsigned long long value, char the_type)
{
    if (the_type == 'c' || the_type == '%')
        return (letter_c_percent(line, p_temp, value));
    if (the_type == 's')
        return (letter_s(line, p_temp, value));
    if (the_type == 'p')
        return (letter_p(line, p_temp, value));
    if (ft_strchr("di", the_type) != 0)
        return (letter_di(line, p_temp, value));
    if (ft_strchr("uxX", the_type) != 0)
        return (letter_uxX(line, p_temp, value, the_type));
    else
        return (free_ret_zero(line, *p_temp, NULL));//******!!!!
}

int letter_c_percent(char **line, char **p_temp, unsigned long long value)
{
    char two[2];
    char *arr;

    two[0] = (char)value;
    two[1] = '\0';
    if (0 == (arr = ft_strjoin(*p_temp, two)))
        return (free_ret_zero(line, *p_temp, NULL));
    free(*p_temp);
    *p_temp = arr;
    return (1);
}

int letter_s(char **line, char **p_temp, unsigned long long value)
{
    char *arr;

    if (0 == (arr = (ft_strjoin(*p_temp, (char *)value))))
        return (free_ret_zero(line, *p_temp, 0));
    free(*p_temp);
    *p_temp = arr;
    return (1);
}

int letter_p(char **line, char **p_temp, unsigned long long value)
{
    char *arr;
    char *buf;//not array declare buf malloc declare****
    int idx;
    char *hex;

    if ( 0 == (hex = ft_strdup("0123456789abcdef")))
        return (0);
    if (0 == (buf = malloc(sizeof(char) * 15)))
        return (0);
    ft_memset(buf, '0', 15);
    buf[0] = '0';
    buf[1] = 'x';
    buf[14] = '\0';
    idx = 13;
    while (idx > 1 || value > 0)
    {
        buf[idx--] = hex[value % 16];
        value = value / 16;
    }
    free(*p_temp);
    free(hex);
    *p_temp = buf;
    return (1);
}

int letter_di(char **line, char **p_temp, unsigned long long value)
{
    char *arr;

    if (0 == (arr = ft_itoa((int)value)))
        return (free_ret_zero(line, *p_temp, NULL));
    free(*p_temp);
    *p_temp = arr;
    return (1);
}

int letter_uxX(char **line, char **p_temp, unsigned long long value, char the_type)
{
    char *arr;
    unsigned int num;

    num = (unsigned int)value;
    if(the_type == 'u')
    {
        if (NULL == (arr = ten_unsigned(num)))
            return (free_ret_zero(line, *p_temp, NULL));
    }
    else if (the_type == 'x')
    {
        if (0 == (arr = ten_small_hex(num)))
            return (free_ret_zero(line, *p_temp, NULL));
    }
    else if (the_type == 'X')
    {
        if (0 == (arr = ten_big_hex(num)))
            return (free_ret_zero(line, *p_temp, 0));
    }
    free(*p_temp);
    *p_temp = arr;
    return (1);
}

int contact_with_format(t_node *p_node, char **line, char **p_temp)
{
    if (p_node->my_case != what_my_case((p_node->string)[p_node->idx], p_node->my_case))
    {
        if (!case_changed(line, p_temp, &(p_node->my_case)))
            return (0);
        return (42);
    }
    if (ft_strchr(".-0", p_node->string[p_node->idx]) != 0)
    {
        if (flag_precise(line, p_temp, (char *)p_node->string, &(p_node->idx)))
            return (42);
        else   
            return (0);
    }
    if (p_node->string[p_node->idx] != '*')
    {
        if (1 == not_star(line, (char*)p_node->string, p_temp, &(p_node->idx)))
            return (42);
        else   
            return (0);
    }
    return (1);
}

int over_star(t_node *p_node, char **line, char**p_temp)
{
    if (0 == star(line, p_temp, p_node->buf, p_node->my_case))
        return (0);
    p_node->buf = 0;
    if (what_my_case(p_node->string[++(p_node->idx)], p_node->my_case) == p_node->my_case)
        return (free_ret_zero(line, *p_temp, NULL));
    return (1);
}

int finale(t_node*p_node, char **line, char **p_temp)
{
    if (!complete_final(line, &(p_node->my_case), p_temp)
        return (0);
    if (!inter_type(line, p_temp, p_node->value, p_node->string[p_node->idx]))
        return (0);
    if (!real_complete_final(line, p_temp, p_node->string, &(p_node->idx)))
        return (0);
    return (1);
}