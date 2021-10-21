/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyelee <soyelee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:10:07 by soyelee           #+#    #+#             */
/*   Updated: 2021/06/30 20:21:30 by soyelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		len_s;
	int		i;

	len_s = ft_strlen(s);
	result = (char *)malloc(len_s + 1);
	if (!result)
		return (NULL);
	i = -1;
	while (++i < len_s)
		result[i] = (*f)((unsigned int)i, s[i]);
	result[len_s] = '\0';
	return (result);
}
