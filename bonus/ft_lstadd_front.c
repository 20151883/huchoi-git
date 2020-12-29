#include "linbft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list *head;

	head = *lst;
	new -> next = head;
	head = new;
	*lst = head;
}
