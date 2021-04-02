/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:00:21 by huchoi            #+#    #+#             */
/*   Updated: 2021/01/09 13:40:41 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	my_clear(char **lst)
{
	int		i;
	char	*cur;
	char	*del;

	i = 0;
	del = lst[i];
	if (del == 0)
	{
		free(del);
		return ;
	}
	else
	{
		cur = lst[++i];
		free(del);
		while (cur != 0)
		{
			del = cur;
			cur = lst[++i];
			free(del);
		}
	}
}

static	int		get_start(char const *s1, char const c, int end)
{
	int ret;
	int i;

	ret = end + 1;
	if (s1[ret] == '\0')
		return (-1);
	i = 0;
	while (s1[ret + i] != '\0')
	{
		if (s1[ret + i] != c)
			return (ret + i);
		else
			i++;
	}
	return (-1);
}

static	int		get_end(char const *s1, char const c, int start)
{
	int ret;
	int i;

	if (start == -1)
		return (-1);
	ret = start;
	i = 0;
	while (s1[ret + i] != '\0')
	{
		if (c == (s1[ret + i]))
			return (ret + i - 1);
		else
			i++;
	}
	return (ret + i - 1);
}

static	char	**new_ret(char **ret, char const *s1, int start, int end)
{
	int		i;
	int		len;
	char	**return_value;
	char	*str;

	len = 0;
	while (ret[len] != 0)
		len++;
	return_value = (char **)malloc(sizeof(char *) * (len + 2));
	if (return_value == 0)
	{
		my_clear(ret);
		return (0);
	}
	i = -1;
	while (ret[++i] != NULL)
		return_value[i] = ret[i];
	free(ret);
	str = (char *)malloc(sizeof(char) * (end - start + 2));
	ft_strlcpy(str, &s1[start], end - start + 2);
	return_value[i++] = str;
	return_value[i] = 0;
	return (return_value);
}

char			**ft_split(char const *s1, char const c)
{
	char	**ret;
	int		start;
	int		end;

	ret = (char **)malloc(sizeof(char *) * 1);
	if (ret == 0)
		return (0);
	*ret = 0;
	start = get_start(s1, c, -1);
	end = get_end(s1, c, start);
	while (start != -1)
	{
		ret = new_ret(ret, s1, start, end);
		if (ret == 0)
			return (0);
		start = get_start(s1, c, end);
		end = get_end(s1, c, start);
	}
	return (ret);
}
