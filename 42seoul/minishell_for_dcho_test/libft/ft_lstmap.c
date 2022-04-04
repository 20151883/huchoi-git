/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyelee <soyelee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 16:59:28 by soyelee           #+#    #+#             */
/*   Updated: 2021/07/23 21:56:10 by soyelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_lst(int iter, t_list *init_lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*temp_next;

	temp = init_lst;
	while (iter--)
	{
		(*del)(temp->content);
		temp_next = temp->next;
		free(temp);
		temp = temp_next;
	}
}

int	new_lst(t_list *lst, t_list **result, void *(*f)(void *))
{
	if (!lst)
		return (-1);
	*result = ft_lstnew((*f)(lst->content));
	if (!result)
		return (-1);
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*d)(void *))
{
	t_list	*result;
	t_list	*init_result;
	int		iter;

	if (new_lst(lst, &result, f) == -1)
		return (NULL);
	init_result = result;
	iter = 1;
	while (lst->next)
	{
		result->next = (t_list *)malloc(sizeof(t_list));
		if (!(result->next))
		{
			free_lst(iter, init_result, d);
			return (NULL);
		}
		result = result->next;
		lst = lst->next;
		result->content = (*f)(lst->content);
		iter++;
	}
	result->next = NULL;
	return (init_result);
}
