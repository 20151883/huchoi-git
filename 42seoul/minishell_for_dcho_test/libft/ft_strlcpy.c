/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyelee <soyelee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 10:57:43 by soyelee           #+#    #+#             */
/*   Updated: 2020/10/07 17:34:14 by soyelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	int		i;

	len_src = 0;
	i = 0;
	while (i < (int)dstsize - 1 && src[len_src])
		dst[i++] = src[len_src++];
	while (src[len_src])
		len_src++;
	if (dstsize > 0)
		dst[i] = '\0';
	return (len_src);
}
