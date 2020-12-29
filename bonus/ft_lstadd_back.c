#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *cur;

	cur = *list;
	while((cur -> next) != 0)
		cur = cur -> next;
	cur -> next = new;
	new -> next = 0;
}
