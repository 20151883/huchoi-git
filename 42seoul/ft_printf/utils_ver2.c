/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ver2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 17:25:47 by huchoi            #+#    #+#             */
/*   Updated: 2021/02/07 17:27:32 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int		free_ret_zero(char **p, char *s1, char *s2, int my_case)
{
	int i;

	i = 1;
	while (i < my_case)
	{
		free(p[i++]);
	}
	if (s1 != 0)
		free(s1);
	if (s2 != 0)
		free(s2);
	return (0);
}

int		atoi_positive(char *str)
{
	int num;

	if (ft_strchr(str, '-'))
		*(ft_strchr(str, '-')) = '0';
	num = ft_atoi(str);
	return (num);
}

char	*trim_the_zero(char **line)
{
	int		size;
	char	*ret;
	char	*save;

	if (ft_strlen(line[5]) == 3 && line[5][2] == '0')
		return (ft_strdup("0x0"));
	save = ft_strchr(line[5], 'x');
	save++;
	while (*save == '0')
		save++;
	size = ft_strlen(save) + 2;
	ret = malloc(sizeof(char) * (size + 1));
	ret[size] = '\0';
	ret[0] = '0';
	ret[1] = 'x';
	ft_strlcpy(&ret[2], save, size - 1);
	return (ret);
}
