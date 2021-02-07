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

/*void renewer_line(char **line, int num)
{
    char *temp;

    temp = ft_calloc(sizeof(char),1);
    temp = ft_strdup("");
    free(line[num]);
    line[num] = temp;
}*/

int finale(t_node *p_node, char **line, char **p_temp)
{
    char *str;

    str = p_node->string;
    type_case_sort(p_node);
    if (!complete_final(line, &(p_node->my_case), p_temp))
        return (0);
    if (!inter_type(line, p_temp, p_node, str[p_node->idx]))//p_node, str[p_node->idx]))
        return (0);     
    if (!real_complete_final(p_node, line, p_temp))
        return (0);
    return (1);
}

void type_case_sort(t_node *p_node)
{
	char *str;

	str = p_node->string;
	if (str[p_node->idx] == '%')
		p_node->for_c = '%';
	else
	{
		if (str[p_node->idx] == 'c')
			p_node->for_c = (char)va_arg(g_ap, int);
		else if (str[p_node->idx] == 's')
			p_node->for_s = va_arg(g_ap , char *);//
        else if (str[p_node->idx] == 'p')
            p_node->p_p = va_arg(g_ap, unsigned long long);
        else if (ft_strchr("di", str[p_node->idx]) != 0)
            p_node->yes_int = va_arg(g_ap, int);
        else
            p_node->un_int = va_arg(g_ap, unsigned int);
	}
}


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

int inter_type(char **line, char **p_temp, t_node *p_node, char the_type)
{
    if (the_type == 'c' || the_type == '%')
        return (letter_c_percent(line, p_temp, p_node->for_c));
    if (the_type == 's')
        return (letter_s(line, p_temp, p_node->for_s));
    if (the_type == 'p')
        return (letter_p(line, p_temp, p_node->p_p));
    if (ft_strchr("di", the_type) != 0)
        return (letter_di(line, p_temp, p_node->yes_int));
    if (ft_strchr("uxX", the_type) != 0)
        return (letter_uxX(line, p_temp, p_node->un_int, the_type));
    else
        return (free_ret_zero(line, *p_temp, NULL, 5));
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
        return (free_ret_zero(line, *p_temp, 0, 6));//free is not already done..! 
    ft_putstr_fd(arr, 1);
    free_ret_zero(line, *p_temp, arr, 6);
    (p_node->idx)++;
    p_node->my_case = 1;
    p_node->is_precision = 0;
    p_node->buf = 0;
    p_node->two_star = 0;
    return (1);
}