/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_signed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 16:33:17 by huchoi            #+#    #+#             */
/*   Updated: 2021/02/07 16:38:02 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

char	*case_d(t_node *p_node, char **line)
{
	int		size;
	int		plus;
	int		lenth;
	char	*ret;

	minus_express(line, &size, &plus, &lenth);//음수일때 정밀도값과  ft_strlen()값을 비교하는게 아닌 ft_strlen()-1과 비교한다
	if (p_node->is_precision == 1)//정밀도값이 0이고 정수값도 0이라면 value를 출력하지 않는다. 나오는건 space뿐일것.
		check_zero(line, &size, &plus, &lenth);
	if (*line[2] != '\0' && lenth < atoi_positive(line[2]))
		lenth = atoi_positive(line[2]);
	(p_node->count) += lenth;
	if (p_node->is_precision == 1 && ft_atoi(line[3]) >= 0)//분기한 이유 : 그냥...? 함수길이 줄이기 위함이지 별 다른 큰 이유는 없음
		ret = precision_int(line, plus, size, lenth);
	else
		ret = no_precision_int(line, size, lenth);
	return (ret);
}

int		check_zero(char **line, int *p1, int *p2, int *p3)
{
	if (ft_atoi(line[5]) == 0 && ft_atoi(line[3]) == 0)
	{
		*p1 = 0;
		*p2 = 0;
		*p3 = 0;
		return (1);
	}
	else
		return (0);
}

void	minus_express(char **line, int *p_size, int *p_plus, int *p_lenth)
{
	*p_size = ft_strlen(line[5]);
	if (ft_atoi(line[5]) < 0)
	{
		if (ft_atoi(line[3]) > (*p_size - 1))
			*p_plus = ft_atoi(line[3]) - (*p_size - 1);
		else
			*p_plus = 0;
	}
	else
	{
		if (*line[3] != '\0' && *p_size < atoi(line[3]))
			*p_plus = atoi(line[3]) - *p_size;
		else
			*p_plus = 0;
	}
	*p_lenth = *p_size + *p_plus;
}

char	*case_i(t_node *p_node, char **line)//same with the 'd'...
{
	int		size;
	int		plus;
	int		lenth;
	char	*ret;

	minus_express(line, &size, &plus, &lenth);
	if (p_node->is_precision == 1)
		check_zero(line, &size, &plus, &lenth);
	if (*line[2] != '\0' && lenth < atoi_positive(line[2]))
		lenth = atoi_positive(line[2]);
	(p_node->count) += lenth;
	if (p_node->is_precision == 1 && ft_atoi(line[3]) >= 0)
		ret = precision_int(line, plus, size, lenth);
	else
		ret = no_precision_int(line, size, lenth);
	return (ret);
}
