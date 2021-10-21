/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyelee <soyelee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 10:41:09 by soyelee           #+#    #+#             */
/*   Updated: 2020/10/08 14:55:28 by soyelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*tmp_dst;
	const char	*tmp_src;
	int			i;

	if (!dst && !src)
		return (NULL);
	tmp_dst = (char *)dst;
	tmp_src = (const char *)src;
	i = 0;
	if (src < dst && dst < src + len)
		while (i++ < (int)len)
			tmp_dst[len - i] = tmp_src[len - i];
	else
		while (i++ < (int)len)
			tmp_dst[i - 1] = tmp_src[i - 1];
	return (dst);
}
