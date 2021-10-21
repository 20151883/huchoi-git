/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyelee <soyelee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 10:45:38 by soyelee           #+#    #+#             */
/*   Updated: 2020/10/23 16:20:42 by soyelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int					i;
	const unsigned char	*temp_s;

	temp_s = (const unsigned char *)s;
	i = 0;
	while (i++ < (int)n)
		if (temp_s[i - 1] == (unsigned char)c)
			return ((void *)(s + i - 1));
	return (NULL);
}
