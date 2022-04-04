/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyelee <soyelee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:31:55 by soyelee           #+#    #+#             */
/*   Updated: 2020/10/23 16:40:14 by soyelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p_s;

	p_s = (char *)s;
	while (*p_s)
		p_s++;
	if ((char)c == '\0')
		return (p_s);
	while ((char *)s < p_s--)
		if (*p_s == (char)c)
			return (p_s);
	return (NULL);
}
