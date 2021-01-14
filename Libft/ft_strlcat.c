/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:42:29 by huchoi            #+#    #+#             */
/*   Updated: 2021/01/04 14:48:56 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstlen >= size)
		return (srclen + size);
	else
	{
		i = 0;
		j = dstlen;
		while (size - dstlen - 1 > 0 && src[i] != '\0')
		{
			dst[j] = src[i];
			j++;
			i++;
			size--;
		}
		dst[j] = '\0';
			return (dstlen + srclen);
		}
}
