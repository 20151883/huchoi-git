#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list cur;
	int count;

	cur = lst;
	count = 0;
	while(cur++ != 0)
		count++;
	return (count);
}
