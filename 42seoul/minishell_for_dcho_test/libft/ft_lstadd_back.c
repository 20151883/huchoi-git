/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyelee <soyelee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 16:00:23 by soyelee           #+#    #+#             */
/*   Updated: 2020/10/12 16:03:39 by soyelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newlst)
{
	t_list	*walker;

	if (*lst)
	{
		walker = *lst;
		while (walker->next)
			walker = walker->next;
		walker->next = newlst;
	}
	else
		*lst = newlst;
}
