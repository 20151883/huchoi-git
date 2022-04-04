/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyelee <soyelee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 15:29:13 by soyelee           #+#    #+#             */
/*   Updated: 2021/06/30 20:30:15 by soyelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*put_digit(int n, int sign, int digit)
{
	char	*result;

	result = (char *)malloc(digit + 1 + sign);
	if (!result)
		return (NULL);
	result[digit + sign] = '\0';
	if (n == 0)
		result[0] = 48;
	while (n)
	{
		result[digit-- - 1 + sign] = n % 10 + 48;
		n /= 10;
	}
	if (sign == 1)
		result[0] = '-';
	return (result);
}

char	*ft_itoa(int n)
{
	int		digit;
	int		sign;
	char	*result;

	if (n <= -2147483648 || 2147483647 < n)
	{
		result = (char *)malloc(12);
		if (!result)
			return (NULL);
		ft_strlcpy(result, "-2147483648", 12);
		return (result);
	}
	digit = count_digit(n);
	if (n < 0)
	{
		sign = 1;
		n *= -1;
	}
	else
		sign = 0;
	result = put_digit(n, sign, digit);
	if (!result)
		return (NULL);
	return (result);
}
