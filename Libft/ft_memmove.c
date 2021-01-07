/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:45:59 by huchoi            #+#    #+#             */
/*   Updated: 2021/01/04 13:46:00 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_move(unsigned char *dst, unsigned char *src, size_t n)
{
	size_t			i;

	i = 0;
	if (src < dst)
	{
		while (i < n)
		{
			dst[n - i - 1] = src[n - i - 1];
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	dst_ptr = ft_move(dst_ptr, src_ptr, n);
	return (dst);
}
