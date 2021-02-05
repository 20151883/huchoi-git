/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_printf_utils_ver2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:07:19 by huchoi            #+#    #+#             */
/*   Updated: 2021/02/05 15:07:21 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int complete_final(char **line, int *p_my_case, char **p_temp)
{
    if (0 == (line[*p_my_case] = ft_strdup(*p_temp)))
        return (free_ret_zero(line, *p_temp, 0, *p_my_case));
    (*p_my_case)++;
    while(*p_my_case <= 5)
    {
        if (0 == (line[*p_my_case] = ft_strdup("")))
            return (free_ret_zero(line, *p_temp, 0, *p_my_case));
        (*p_my_case)++;
    }
    ft_memset(*p_temp, '\0', ft_strlen(*p_temp) + 1);
    **p_temp = '\0';
    return (1);
}

void renewer_line(char **line, int num)
{
    char *temp;

    temp = ft_calloc(sizeof(char),1);
    temp = ft_strdup("");
    free(line[num]);
    line[num] = temp;
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

int letter_c_percent(char **line, char **p_temp, unsigned long long value)
{
    char two[2];
    char *arr;

    if (value == 0)
        arr = ft_strdup("(null)");
    else
    {
        two[0] = (char)value;
        two[1] = '\0';
        if (0 == (arr = ft_strjoin(*p_temp, two)))
            return (free_ret_zero(line, *p_temp, NULL, 5));
    }
    free(*p_temp);
    *p_temp = arr;
    return (1);
}

int letter_s(char **line, char **p_temp, unsigned long long value)
{
    char *arr;

    if (value == 0)
        arr = ft_strdup("(null)");
    else if (0 == (arr = (ft_strjoin(*p_temp, (char *)value))))
        return (free_ret_zero(line, *p_temp, 0, 5));
    free(*p_temp);
    *p_temp = arr;
    return (1);
}

int letter_p(char **line, char **p_temp, unsigned long long value)
{
    char *buf;
    int idx;
    char *hex;

    if (value == 0)
        return (value_is_zero(p_temp));
    if ( 0 == (hex = ft_strdup("0123456789abcdef")))
        return (free_ret_zero(line, *p_temp, NULL, 5));
    if (0 == (buf = malloc(sizeof(char) * 15)))
        return (free_ret_zero(line, *p_temp, hex, 5));
    ft_memset(buf, '0', 15);
    idx = 13;
    while (idx > 1 && value > 0)
    {
        buf[idx--] = hex[value % 16];
        value = value / 16;
    }
    buf[idx] = '0';
    buf[0] = '0';
    buf[1] = 'x';
    buf[14] = '\0';
    free(*p_temp);
    free(hex);
    *p_temp = buf;
    return (1);
}

int value_is_zero(char **p_temp)
{
    char *arr;

    if (0== (arr = malloc(sizeof(char) * 4)))
        return (0);
    arr[0] = '0';
    arr[1] ='x';
    arr[2] = '0';
    arr[3] = '\0';
    free(*p_temp);
    *p_temp = arr;
    return (1);
}

int letter_di(char **line, char **p_temp, unsigned long long value)
{
    char *arr;

    if (0 == (arr = ft_itoa((int)value)))
        return (free_ret_zero(line, *p_temp, NULL, 5));
    if (value == 0)
    {
        free(arr);
        if (0 == (arr = malloc(sizeof(char) * 2)))
            return (free_ret_zero(line, *p_temp, 0, 5));
        arr[0] = '0';
        arr[1] = '\0';
    }
    free(*p_temp);
    *p_temp = arr;
    return (1);
}

int letter_uxX(char **line, char **p_temp, unsigned long long value, char the_type)
{
    char *arr;
    unsigned int num;

    arr = NULL;
    num = (unsigned int)value;
    if (the_type == 'u')
    {
        if (NULL == (arr = ten_unsigned(num)))
            return (free_ret_zero(line, *p_temp, NULL, 5));
    }
    else if (the_type == 'x')
    {
        if (0 == (arr = ten_small_hex(num)))
            return (free_ret_zero(line, *p_temp, NULL, 5));
    }
    else
    {
        if (0 == (arr = ten_big_hex(num)))
            return (free_ret_zero(line, *p_temp, 0, 5));
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
        if (flag_precise(line, p_temp, p_node))
            return (42);
        else   
            return (0);
    }
    if (p_node->string[p_node->idx] != '*')
    {
        if (1 == not_star(line, (char*)p_node->string, p_temp, p_node))
            return (42);
        else   
            return (0);
    }
    return (1);
}

int over_star(t_node *p_node, char **line, char**p_temp)
{
    if (0 == star(line, p_temp, p_node->buf, p_node->my_case, p_node))
        return (0);
    p_node->buf = 0;
    line[p_node->my_case] = *p_temp;
    if (what_my_case(p_node->string[++(p_node->idx)], p_node->my_case) == p_node->my_case)
        return (free_ret_zero(line, *p_temp, NULL, p_node->my_case));
    return (1);
}

void type_case_sort(t_node *p_node)
{
	char *str;

	str = p_node->string;
	if (str[p_node->idx] == '%')
		p_node->value = '%';
	else
	{
		if (str[p_node->idx] == 'c')
			p_node->value = va_arg(ap, int);
		else
			p_node->value = va_arg(ap ,unsigned long long);
	}
}

int finale(t_node *p_node, char **line, char **p_temp)
{
    char *str;

    str = p_node->string;
    type_case_sort(p_node);
    if (!complete_final(line, &(p_node->my_case), p_temp))
        return (0);
    if (!inter_type(line, p_temp, p_node->value, str[p_node->idx]))
        return (0);     
    if (!real_complete_final(p_node, line, p_temp))
        return (0);
    return (1);
}

int important(t_node *p_node, char **line, char **p_temp)
{
    if (42 == (p_node->ret = contact_with_format(p_node, line, p_temp)))
        return (1);//free is not done in here
    else if (p_node->ret == 0)
        return (0);
    if (0 == (p_node->buf = ft_itoa(va_arg(g_ap, int))))//itoa malloc is done...
        return (free_ret_zero(line,*p_temp, 0, p_node->my_case));
    if (over_star(p_node, line, p_temp) == 0)
        return (0);
    return (1);
}

void my_putchar_fd(t_node *p_node)
{
    char *str;

    str = p_node->string;
    ft_putchar_fd(str[(p_node->idx) - 1], 1);
    p_node->count++;
}
