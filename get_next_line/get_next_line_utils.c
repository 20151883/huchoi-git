/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:11:17 by marvin            #+#    #+#             */
/*   Updated: 2021/01/18 19:05:39 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *src)
{
	char	*ret;
	int		i;

	i = ft_strlen(src);
	ret = (char *)malloc(i + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		ret[i] = src[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strrchr(char *s, int c)
{
	int		i;
	char	*ret;

	i = 0;
	ret = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			ret = (char *)s + i;
		i++;
	}
	if (c == 0)
		return (char *)(s + i);
	return (ret);
}

int ft_strlen(char *str)// fact : max_idx = the number of member - 1  
{
    int ret;

    ret = 0;
    while (str[ret])
    {
        ret++;
    }
    return (ret);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ret)
		return (NULL);
	while (s1[i] != '\0')
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ret[i] = s2[j];
		i++;
		j++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strchr(char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return (char *)(s + i);
}
