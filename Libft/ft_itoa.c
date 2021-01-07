/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 12:24:16 by huchoi            #+#    #+#             */
/*   Updated: 2021/01/07 12:26:10 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_num_len(int n)
{
	int		len;

	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_minus(char *res, int n, int len)
{
	while (n < 0)
	{
		res[--len] = '0' + ((n % 10) * (-1));
		n /= 10;
	}
	res[--len] = '-';
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;

	len = ft_num_len(n) + 2;
	res = (char *)malloc(len);
	if (!res)
		return (NULL);
	res[--len] = '\0';
	if (n < 0)
		res = ft_minus(res, n, len);
	else if (n == 0)
		res[--len] = '0';
	else
	{
		res[--len] = '\0';
		while (n > 0)
		{
			res[--len] = '0' + (n % 10);
			n /= 10;
		}
	}
	return (res);
}
