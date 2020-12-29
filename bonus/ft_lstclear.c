#include "libft.h"

void ft_lstclear(t_list **lst,void (*del)(void *))
{
	t_list *cur;
	t_list *temp;

	cur = *lst;
	while(cur != 0)
	{
		del(cur -> content);
		temp = cur -> next;
		free(cur);
		cur = temp;
	}
}
