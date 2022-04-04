/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyelee <soyelee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 13:47:09 by soyelee           #+#    #+#             */
/*   Updated: 2021/07/23 21:48:40 by soyelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_ary(char const *param_s, char c)
{
	int		count;
	char	*s;

	s = (char *)param_s;
	if (!c && *s)
		return (1);
	while (*s && *s == c)
		s++;
	count = 0;
	while (*s)
	{
		count++;
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	return (count);
}

static int	count_string(char const *param_s, char c)
{
	int		count;
	char	*s;

	s = (char *)param_s;
	count = 0;
	while (*s && *s != c)
	{
		count++;
		s++;
	}
	return (count);
}

static char	**ft_free(char **ary, int i)
{
	int	idx;

	idx = 0;
	while (idx < i)
		free(ary[idx++]);
	free(ary);
	ary = NULL;
	return (NULL);
}

static int	copy_string(char **s, char c, char **ary, int i)
{
	int	j;

	while (**s && **s == c)
		(*s)++;
	if (**s && **s != c)
	{
		ary[i] = (char *)malloc(count_string(*s, c) + 1);
		if (!ary[i])
			return (-1);
	}
	j = 0;
	while (**s && **s != c)
		ary[i][j++] = *(*s)++;
	ary[i][j] = '\0';
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**ary;
	int		len_ary;
	int		i;
	char	*tmp_s;

	if (!s)
		return (NULL);
	tmp_s = (char *)s;
	len_ary = count_ary(tmp_s, c);
	ary = (char **)malloc(sizeof(char *) * (len_ary + 1));
	if (!ary)
		return (NULL);
	i = -1;
	while (*tmp_s && ++i < len_ary)
	{
		if (copy_string(&tmp_s, c, ary, i) == -1)
			return (ft_free(ary, i));
	}
	ary[len_ary] = NULL;
	return (ary);
}
