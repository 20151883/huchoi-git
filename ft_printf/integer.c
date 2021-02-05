/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:07:58 by huchoi            #+#    #+#             */
/*   Updated: 2021/02/05 15:08:00 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

char *case_d(t_node *p_node, char **line)
{
    int size;//number of character
    int plus;
    int lenth;//buffer lenth excluded the NULL
    char *ret;

    minus_express(line, &size, &plus, &lenth);
     if (p_node->is_precision == 1)
        check_zero(line, &size, &plus, &lenth);
    if (*line[2] != '\0' && lenth < atoi_positive(line[2]))
        lenth = atoi_positive(line[2]);
    (p_node->count) += lenth;
    if (p_node->is_precision == 1 && ft_atoi(line[3]) >= 0)
        ret = precision_int(line, plus, size, lenth);
    else//precision is nit in line.//plus is zero.. 
        ret = no_precision_int(line, size, lenth);    
    return (ret);
}

void minus_express(char **line, int *p_size, int *p_plus, int *p_lenth)
{
    *p_size = ft_strlen(line[5]);
    if (ft_atoi(line[5]) < 0)
    {
        if (ft_atoi(line[3]) > (*p_size - 1))
            *p_plus = ft_atoi(line[3]) - (*p_size - 1);
        else
            *p_plus = 0;
    }
    else
    {
        if (*line[3] != '\0' && *p_size < atoi(line[3]))
            *p_plus = atoi(line[3]) - *p_size;
        else
            *p_plus = 0;
    }
    *p_lenth = *p_size + *p_plus;
}

char *case_i(t_node *p_node, char **line)
{
    int size;//number of character
    int plus;
    int lenth;//buffer lenth excluded the NULL
    char *ret;

    minus_express(line, &size, &plus, &lenth);
    if (p_node->is_precision == 1)
        check_zero(line, &size, &plus, &lenth);
    if (*line[2] != '\0' && lenth < atoi_positive(line[2]))
        lenth = atoi_positive(line[2]);
    (p_node->count) += lenth;
    if (p_node->is_precision == 1 && ft_atoi(line[3]) >= 0)
        ret = precision_int(line, plus, size, lenth);
    else
        ret = no_precision_int(line, size, lenth);    
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
        ret = no_precision_unsigned(line, size, lenth);    
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
    if (p_node->is_precision == 1 && size <= 1 && ft_atoi(line[3]) == 0)
        for_hex_check_zero(line, &size, &plus, &lenth);
    if (*line[2] != '\0' && lenth < atoi_positive(line[2]))
        lenth = atoi_positive(line[2]);
    (p_node->count) += lenth;
    if (ft_atoi(line[3]) >= 0 && (p_node->is_precision == 1))
        ret = precision_unsigned(line, plus, size, lenth);
    else//precision is nit in line.//plus is zero.. 
        ret = no_precision_unsigned(line, size, lenth);    
    return (ret);
}

int for_hex_check_zero(char **line, int *p1, int *p2, int *p3)
{
    if (*line[5] == '0' &&ft_atoi(line[3]) == 0)
    {
        *p1 = 0;
        *p2 = 0;
        *pe = 0;
        return (1)
    }
    else
        return (0);
}
int hex_zero_check(t_node *p_node, int *p1, int *p2, int *p3)
{
    if (p_node->un_int == 0)
	{
		*p1 = 0;
		*p2 = 0;
		*p3 = 0;
		return (1);
	}
	else
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
    if (p_node->is_precision == 1 && size <= 1)
        check_zero(line, &size, &plus, &lenth);
    if (*line[2] != '\0' && lenth < atoi_positive(line[2]))
        lenth = atoi_positive(line[2]);
    (p_node->count) += lenth;
    if (ft_atoi(line[3]) >= 0 && (p_node->is_precision == 1))
        ret = precision_unsigned(line, plus, size, lenth);
    else//precision is nit in line.//plus is zero.. 
        ret = no_precision_unsigned(line, size, lenth);    
    return (ret);
}
