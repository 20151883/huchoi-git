/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyelee <soyelee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 11:54:53 by soyelee           #+#    #+#             */
/*   Updated: 2020/11/07 16:50:17 by soyelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	int			found;
	const char	*init_needle;

	if (!*needle)
		return ((char *)hay);
	found = 0;
	init_needle = needle;
	while (*hay && *needle && len--)
	{
		if (*hay == *needle)
		{
			needle++;
			found++;
			hay++;
			continue ;
		}
		hay -= found;
		len += found;
		found = 0;
		needle = init_needle;
		hay++;
	}
	if (!*needle && found)
		return ((char *)hay - found);
	return (NULL);
}
