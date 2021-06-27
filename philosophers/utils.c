/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 19:27:49 by huchoi            #+#    #+#             */
/*   Updated: 2021/06/27 22:41:55 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			ft_isdigit(const char *arr)
{
	while (*arr)
	{
		if ('0' > *arr || *arr > '9')
			return (0);
		arr++;
	}
	return (1);
}

int			ft_strlen(char *str)
{
	int	ret;

	ret = 0;
	while (str[ret])
		ret++;
	return (ret);
}

int			ft_strcmp(char *s1, char *s2)
{
	int	idx;

	idx = 0;
	while (s1[idx] == s2[idx] && s1[idx])
		idx++;
	return (s1[idx] - s2[idx]);
}

int			my_atouit(char *positive_arr)
{
	int	ret;
	int	idx;

	ret = 0;
	idx = 0;
	if (ft_strlen(positive_arr) >= 10 && \
		ft_strcmp(positive_arr, "2147483647") > 0)
		return (-1);
	while (positive_arr[idx])
	{
		ret *= 10;
		ret += positive_arr[idx] - '0';
		idx++;
	}
	return (ret);
}

uint64_t	get_mstime(void)
{
	struct timeval current;

	gettimeofday(&current, NULL);
	return (current.tv_sec * (uint64_t)1000) + (current.tv_usec / 1000);
}
