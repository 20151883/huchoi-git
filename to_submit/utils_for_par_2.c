/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_par_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:03:33 by huchoi            #+#    #+#             */
/*   Updated: 2021/03/08 17:38:24 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_clear(char **lst)
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

int		give_start(char const *s1, char *deli, int end)
{
	int ret;
	int i;

	ret = end + 1;
	if (s1[ret] == '\0')
		return (-1);
	i = 0;
	while (s1[ret + i] != '\0')
	{
		if (ft_strchr(deli, s1[ret + i]) == 0)
			return (ret + i);
		else
			i++;
	}
	return (-1);
}

int		give_end(char const *s1, char *deli, int start)
{
	int ret;
	int i;

	if (start == -1)
		return (-1);
	ret = start;
	i = 0;
	while (s1[ret + i] != '\0')
	{
		if (ft_strchr(deli, s1[ret + i]) != 0)
			return (ret + i - 1);
		else
			i++;
	}
	return (ret + i - 1);
}

char	**new_ret(char **ret, char const *s1, int start, int end)
{
	int		i;
	int		len;
	char	**return_value;
	char	*str;

	len = 0;
	while (ret[len] != 0)
		len++;
	if (0 == (return_value = (char **)malloc(sizeof(char *) * (len + 2))))
		message_exit();
	if (return_value == 0)
	{
		my_clear(ret);
		return (0);
	}
	i = -1;
	while (ret[++i] != '\0')
		return_value[i] = ret[i];
	free(ret);
	if (NULL == (str = (char *)malloc(sizeof(char) * (end - start + 2))))
		message_exit();
	strlcpy(str, &s1[start], end - start + 2);
	return_value[i++] = str;
	return_value[i] = 0;
	return (return_value);
}

char	**my_split(char const *s1, char *deli)
{
	char	**ret;
	int		start;
	int		end;

	if (0 == (ret = (char **)malloc(sizeof(char *) * 1)))
		message_exit();
	if (ret == 0)
		return (0);
	*ret = 0;
	start = give_start(s1, deli, -1);
	end = give_end(s1, deli, start);
	while (start != -1)
	{
		ret = new_ret(ret, s1, start, end);
		if (ret == 0)
			return (0);
		start = give_start(s1, deli, end);
		end = give_end(s1, deli, start);
	}
	return (ret);
}
