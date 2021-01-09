/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:58:37 by huchoi            #+#    #+#             */
/*   Updated: 2021/01/09 12:12:51 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char ch, char const *set)
{
	int i;

	i = 0;
	while (set[i] != '\0')
	{
		if (ch == set[i])
			return (1);
		i++;
	}
	return (0);
}

static	int	get_head(char const *s1, char const *set)
{
	int ret;

	ret = 0;
	while (s1[ret] != '\0')
	{
		if (is_set(s1[ret], set) == 0)
			return (ret);
		ret++;
	}
	return (-1);
}

static	int	get_tail(char const *s1, char const *set)
{
	int ret;

	ret = ft_strlen(s1) - 1;
	if (is_set(s1[ret], set) == 0)
		return (ret);
	while (ret >= 0)
	{
		if (is_set(s1[ret], set) == 0)
			return (ret);
		ret--;
	}
	return (-1);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	char	temp[ft_strlen(s1) + 1];
	int		head;
	int		tail;

	head = get_head(s1, set);
	tail = get_tail(s1, set);
	if (head == -1 || tail == -1)
	{
		ret = (char *)malloc(1);
		*ret = 0;
		return (ret);
	}
	ft_strlcpy(temp, &(s1[head]), tail - head + 2);
	ret = (char *)malloc(sizeof(char) * (ft_strlen(temp) + 1));
	if (ret == 0)
		return (0);
	ft_strlcpy(ret, temp, ft_strlen(temp) + 1);
	return (ret);
}
