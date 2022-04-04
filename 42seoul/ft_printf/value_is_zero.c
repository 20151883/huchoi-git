/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_is_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 18:20:48 by huchoi            #+#    #+#             */
/*   Updated: 2021/02/07 18:21:12 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int		value_is_zero(char **p_temp)
{
	char	*arr;

	if (0 == (arr = malloc(sizeof(char) * 4)))
		return (0);
	arr[0] = '0';
	arr[1] = 'x';
	arr[2] = '0';
	arr[3] = '\0';
	free(*p_temp);
	*p_temp = arr;
	return (1);
}
