/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 12:52:19 by huchoi            #+#    #+#             */
/*   Updated: 2021/01/07 12:52:32 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		cnt;

	cnt = 0;
	if (lst == NULL)
		return (0);
	else
	{
		while (lst->next != NULL)
		{
			cnt++;
			lst = lst->next;
		}
		cnt++;
		return (cnt);
	}
}
