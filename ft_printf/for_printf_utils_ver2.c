#include "includes/ft_printf.h"

int important(t_node *p_node, char **line, char **p_temp)
{
    if (42 == (p_node->ret = contact_with_format(p_node, line, p_temp)))
        return (1);
    else if (p_node->ret == 0)
        return (0);
    if (0 == (p_node->buf = ft_itoa(va_arg(ap, int))))
        return (free_ret_zero(line,*p_temp, 0, p_node->my_case));
    if (over_star(p_node, line, p_temp) == 0)
        return (0);
    return (1);
}

int complete_final(char **line, int *p_my_case, char **p_temp)
{
    if (0 == (line[*p_my_case] = ft_strdup(*p_temp)))
        return (free_ret_zero(line, *p_temp, 0, *p_my_case));
    (*p_my_case)++;
    while (*p_my_case <= 5)
    {
        if (0 == (line[*p_my_case] = ft_strdup("")))
            return (free_ret_zero(line, *p_temp, 0, *p_my_case));
        (*p_my_case)++;
    }
    ft_memset(*p_temp, '\0', ft_strlen(*p_temp) + 1);
    **p_temp = '\0';
    return (1);
}

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
        return (free_ret_zero(line, *p_temp, NULL, 5));
}

int finale(t_node *p_node, char **line, char **p_temp)
{
    char *str;

    str = p_node->string;
    type_case_sort(p_node, line);
    if (!complete_final(line, &(p_node->my_case), p_temp))
        return (0);
    if (!inter_type(line, p_temp, p_node->value, str[p_node->idx]))
        return (0);
    if (!real_complete_final(p_node, line, p_temp))
        return (0);
    return (1);
}

int real_complete_final(t_node *p_node, char **line, char**p_temp)
{
    char *arr;
    char *str;
    int i;

    str = p_node->string;
    i = p_node->idx;
    if (0 == (line[5] = ft_strdup(*p_temp)))
        return (free_ret_zero(line, *p_temp, NULL, p_node->my_case));
    if (0 == (arr = make_string(p_node, line,p_temp, str[i])))
        return (0);
    free_ret_zero(line, *p_temp, arr, 6);
    (p_node->idx)++;
    p_node->my_case = 1;
    p_node->is_precision = 0;
    p_node->buf = 0;
    p_node->two_star = 0;
    return (1);
}