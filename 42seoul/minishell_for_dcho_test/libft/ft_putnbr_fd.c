/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyelee <soyelee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:34:45 by soyelee           #+#    #+#             */
/*   Updated: 2021/06/30 20:27:12 by soyelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recur_write(int n, int fd)
{
	char	num;

	if (n / 10)
		recur_write(n / 10, fd);
	num = n % 10 + 48;
	write(fd, &num, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(fd, "-2147483648", 11);
			return ;
		}
		else
			write(fd, "-", 1);
		n *= -1;
	}
	recur_write(n, fd);
}
