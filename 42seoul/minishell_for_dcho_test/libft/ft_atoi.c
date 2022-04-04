/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyelee <soyelee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:57:25 by soyelee           #+#    #+#             */
/*   Updated: 2021/06/30 20:29:02 by soyelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	if (ch == '\t' || ch == '\n' || ch == '\v'
		|| ch == '\f' || ch == '\r' || ch == ' ')
		return (1);
	return (0);
}

static void	ft_isflow(unsigned long long *result, int sign)
{
	if (*result > LONG_MAX && sign == 1)
		*result = -1;
	else if (*result > LONG_MAX && sign == -1)
		*result = 0;
}

int	ft_atoi(const char *str)
{
	char				*p_str;
	int					sign;
	unsigned long long	result;

	p_str = (char *)str;
	sign = 1;
	result = 0;
	while (ft_isspace((int)(*p_str)))
		p_str++;
	if (*p_str == '+' || *p_str == '-')
	{
		if (*p_str++ == '-')
			sign = -1;
	}
	while (ft_isdigit((int)(*p_str)))
		result = result * 10 + (int)(*p_str++) - 48;
	ft_isflow(&result, sign);
	return ((int)result * sign);
}
