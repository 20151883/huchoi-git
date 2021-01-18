/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:42:25 by huchoi            #+#    #+#             */
/*   Updated: 2021/01/06 15:47:51 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_comp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (0);
	}
	return (1);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;

	i = 0;
	if (*to_find == '\0')
		return (char *)(str);
	while (str[i] && (i < n))
	{
		if (n - i < ft_strlen(to_find))
			return (char *)(NULL);
		if (ft_comp(&str[i], to_find) == 1)
			return ((char *)&str[i]);
		i++;
	}
	return (char*)(NULL);
}
