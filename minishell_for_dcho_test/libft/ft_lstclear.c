/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyelee <soyelee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 16:12:13 by soyelee           #+#    #+#             */
/*   Updated: 2020/10/12 16:29:46 by soyelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*walker;

	while (*lst)
	{
		walker = *lst;
		(*del)(walker->content);
		*lst = (*lst)->next;
		free(walker);
	}
}
