/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyelee <soyelee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 10:59:23 by soyelee           #+#    #+#             */
/*   Updated: 2021/06/30 20:20:12 by soyelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	substr = (char *)malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	substr[len] = '\0';
	while (len--)
		substr[len] = s[start + len];
	return (substr);
}
