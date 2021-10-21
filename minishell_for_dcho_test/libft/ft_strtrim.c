/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyelee <soyelee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 11:50:25 by soyelee           #+#    #+#             */
/*   Updated: 2021/06/30 20:21:04 by soyelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
		if (set[i++] == c)
			return (1);
	return (0);
}

static int	count_trim(char const *s1, char const *set, int front_back)
{
	int	i;

	i = 0;
	if (front_back == 1)
	{
		while (*(s1 + i))
		{
			if (is_set(set, *(s1 + i)))
				i++;
			else
				break ;
		}
	}
	else
	{
		while (*(s1 + ft_strlen(s1) - i - 1))
		{
			if (is_set(set, *(s1 + ft_strlen(s1) - i - 1)))
				i++;
			else
				break ;
		}
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		front;
	int		back;
	char	*trim;

	front = 0;
	back = 0;
	front = count_trim(s1, set, 1);
	if (front == (int)ft_strlen(s1))
		return (ft_strdup(""));
	back = count_trim(s1, set, 2);
	if (s1 + front < s1 + ft_strlen(s1) - back - 1)
	{
		trim = ft_substr(s1, front, ft_strlen(s1) - front - back);
		if (!trim)
			return (NULL);
	}
	else
		return (ft_strdup(""));
	return (trim);
}
