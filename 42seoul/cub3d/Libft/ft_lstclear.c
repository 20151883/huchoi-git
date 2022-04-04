/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 12:56:32 by huchoi            #+#    #+#             */
/*   Updated: 2021/01/09 12:00:32 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*delnode;
	t_list	*cur;

	delnode = (*lst);
	if (delnode == 0)
		return ;
	cur = delnode->next;
	del(delnode->content);
	free(delnode);
	while (cur != 0)
	{
		delnode = cur;
		cur = cur->next;
		del(delnode->content);
		free(delnode);
	}
	*lst = 0;
}
