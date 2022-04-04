/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:07:30 by huchoi            #+#    #+#             */
/*   Updated: 2021/02/07 17:35:44 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void	my_putchar_fd(t_node *p_node)
{
	char	*str;

	str = p_node->string;
	ft_putchar_fd(str[(p_node->idx) - 1], 1);
	p_node->count++;
}

char	*ten_small_hex(unsigned int num)
{
	int		i;
	int		j;
	char	*hex;
	char	temp[15];
	char	*ret;

	if (num == 0)
		return (intger_value_is_zero(num));
	i = 0;
	if (0 == (hex = malloc(sizeof(char) * 17)))
		return (0);
	ft_strlcpy(hex, "0123456789abcdef", 17);
	while (num > 0)
	{
		temp[i++] = hex[num % 16];
		num = num / 16;
	}
	if (0 == (ret = malloc(sizeof(char) * (i-- + 1))))
		return (0);
	j = 0;
	while (i >= 0)
		ret[j++] = temp[i--];
	ret[j] = '\0';
	free(hex);
	return (ret);
}

char	*ten_big_hex(unsigned int num)
{
	int		i;
	int		j;
	char	*hex;
	char	temp[15];
	char	*ret;

	if (num == 0)
		return (intger_value_is_zero(num));
	i = 0;
	if (0 == (hex = malloc(sizeof(char) * 17)))
		return (0);
	ft_strlcpy(hex, "0123456789ABCDEF", 17);
	while (num > 0)
	{
		temp[i++] = hex[num % 16];
		num = num / 16;
	}
	if (0 == (ret = malloc(sizeof(char) * (i-- + 1))))
		return (0);
	j = 0;
	while (i >= 0)
		ret[j++] = temp[i--];
	ret[j] = '\0';
	free(hex);
	return (ret);
}

char	*ten_unsigned(unsigned int num)
{
	int		i;
	int		j;
	char	arr[16];
	char	*ret;

	if (num == 0)
		return (intger_value_is_zero(num));
	i = 0;
	while (num > 0)
	{
		arr[i++] = (num % 10) + '0';
		num = num / 10;
	}
	if (0 == (ret = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	j = 0;
	i--;
	while (i >= 0)
		ret[j++] = arr[i--];
	ret[j] = '\0';
	return (ret);
}

char	*intger_value_is_zero(unsigned int num)
{
	char *arr;

	if (0 == (arr = malloc(sizeof(char) * 2)))
		return (0);
	if (num != 0)
		return (0);
	arr[0] = '0';
	arr[1] = '\0';
	return (arr);
}
