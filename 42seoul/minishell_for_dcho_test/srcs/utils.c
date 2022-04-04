/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:02:43 by soyelee           #+#    #+#             */
/*   Updated: 2021/10/20 17:13:32 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_null(void *address)
{
	free(address);
	address = NULL;
}

int	my_strchr(const char *s, int c)
{
	int	res;

	res = 0;
	while (*s)
	{
		if (*s++ == (char)c)
			return (res);
		res++;
	}
	return (-1);
}

char	*my_strdup_len(const char *s1, int len)
{
	char	*result;

	result = (char *)my_malloc(len + 1);
	ft_strlcpy(result, s1, len + 1);
	return (result);
}

char	*my_malloc(int size)
{
	char	*res;

	res = malloc(size);
	if (res == NULL)
		exit_error_malloc();
	return (res);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*p_s1;
	unsigned char	*p_s2;

	p_s1 = (unsigned char *)s1;
	p_s2 = (unsigned char *)s2;
	while (*p_s1 && *p_s2)
		if (*p_s1++ != *p_s2++)
			return (*(p_s1 - 1) - *(p_s2 - 1));
	return (*p_s1 - *p_s2);
}
