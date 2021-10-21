/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyelee <soyelee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 11:29:14 by soyelee           #+#    #+#             */
/*   Updated: 2020/10/08 17:18:09 by soyelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int	len_dst;
	int	len_src;

	len_dst = 0;
	len_src = 0;
	while (dst[len_dst])
		len_dst++;
	while (len_src < (int)dstsize - len_dst - 1 && src[len_src])
	{
		dst[len_dst + len_src] = src[len_src];
		len_src++;
	}
	if (len_dst < (int)dstsize)
		dst[len_dst + len_src] = '\0';
	while (src[len_src])
		len_src++;
	if (len_dst < (int)dstsize)
		return ((size_t)len_src + (size_t)len_dst);
	else
		return ((size_t)len_src + dstsize);
}
