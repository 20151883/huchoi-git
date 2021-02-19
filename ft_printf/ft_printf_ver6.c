/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ver6.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:04:41 by huchoi            #+#    #+#             */
/*   Updated: 2021/02/05 15:04:46 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

va_list	g_ap;

int		what_my_case(char c, int now_case)
{
	if (c == '-' || c == '0')
	{
		if (now_case <= 1)
			return (1);
	}
	if (('0' <= c && c <= '9') || c == '*')
	{
		if ((now_case <= 2))
			return (2);
	}
	if (('0' <= c && c <= '9') || c == '.' || c == '*')
	{
		if (now_case <= 3)
			return (3);
	}
	if (ft_strchr("cspdiuxX%%", c) != 0)
		return (5);
	return (-1);
}

void	init_node(t_node *p_node, const char *str)
{
	p_node->count = 0;
	p_node->idx = 0;
	p_node->my_case = 1;
	p_node->string = (char *)str;
	p_node->buf = 0;
	p_node->is_precision = 0;
	p_node->two_star = 0;
}

int		ft_printf(const char *str, ...)
{
	char	*temp;
	char	*final[6];//final[1] = flag, final[2] = width, final[3] = precision,  final[5] = transformed string
	t_node	node;

	init_node(&node, str);
	va_start(g_ap, str);
	while (str[node.idx] != '\0')//ft_printf("test: %-10.5c",'a');
	{
		if (str[node.idx++] != '%')
		{
			my_putchar_fd(&node);
			continue;
		}
		if (0 == (temp = ft_calloc(1, sizeof(char))))
			return (free_ret_zero(NULL, temp, NULL, node.my_case));
		while (ft_strchr("cspdiuxX%%", str[node.idx]) == 0)
		{
			if (important(&node, final, &temp) == 0)
				return (0);
		}
		if (finale(&node, final, &temp) == 0)//final[1] = "-", final[2] = "10", final[3] = "5", final[5] = "a"
			return (0);//"a         "  count = count + 10;
	}
	va_end(g_ap);
	return (node.count);
}
