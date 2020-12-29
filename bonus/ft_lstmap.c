#include "libft.h"

static t_list	*cur_renew(t_list *cur, t_lst *lst, void (*f)(void *), void (*del)(void *))
{
	t_list *new;

	new = malloc(sizeof(t_list));
	cur -> next = new;
	new -> content = f(lst -> content);
	new -> next = 0;
	del(lst -> content);
	return (new);
}

static t_list	*lst_renew(t_list *lst)
{
	t_lst ret;

	ret = lst -> next;
	free(lst);
	return (ret);
}

t_list	*ft_lstmap(t_list *lst, void (*f)(void *), void (*del)(void *))
{
	t_list *ret;
	t_list *cur;

	ret = malloc(sizeof(t_list));
	cur = ret;
	cur->next = 0;
	cur -> content = f(lst -> contnet);
	del(lst ->content);
	lst -> next = temp;
	free(lst);
	lst = temp;
	while(lst != 0)//루프 불변성...!!!!
	{
		cur = cur_renew(cur, lst, f, del);
		lst = lst_renew(lst);
	}
	return (ret);
}
