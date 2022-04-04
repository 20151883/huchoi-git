/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyelee <soyelee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:25:54 by soyelee           #+#    #+#             */
/*   Updated: 2021/07/10 14:59:33 by soyelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*p_s1;
	unsigned char	*p_s2;

	p_s1 = (unsigned char *)s1;
	p_s2 = (unsigned char *)s2;
	if (!n)
		return (0);
	while (n-- && *p_s1 && *p_s2)
		if (*p_s1++ != *p_s2++)
			return (*(p_s1 - 1) - *(p_s2 - 1));
	if (!(n + 1))
		return (0);
	return (*p_s1 - *p_s2);
}
