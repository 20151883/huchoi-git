#include "ft_printf.h"

va_list ap;
int what_my_case(char c, int now_case)//처리의 목적을 밝히시오....
{
    if (c == '-' || c == '0')
    {
		if (now_case <= 1)
			return (1);
	}
    if(('0' <= c && c <= '9') || c == '*')
    {    if ((now_case <= 2))
			return (2);
	}
    if(('0' <= c && c <= '9') || c == '.' || c == '*')
    {
	    if (now_case <= 3)
			return (3);
	}
    if (ft_strchr("cspdiuxX%%", c) != 0)
        return (5);
    return (-1);
}	

void init_node(t_node* p_node, const char *str)
{
	p_node->count = 0;
	p_node->idx = 0;
	p_node->my_case = 1;
	p_node->string = (char *)str;
	p_node->buf = 0;
	p_node->is_precision = 0;
}

int ft_printf(const char* str, ...)
{
	char *temp;
	char *final[6];
	t_node node;

	init_node(&node, str);
	va_start(ap, str);
	while (str[node.idx] != '\0')
	{
		if(str[node.idx++] != '%')
		{
			my_putchar_fd(&node);
			continue;
		}
		if (0 == (temp = ft_calloc(1, sizeof(char))))
			return (free_ret_zero(NULL, temp, NULL,node.my_case));
		while (ft_strchr("cspdiuxX%%", str[node.idx]) == 0)
		{   
        	if (important(&node, final, &temp) == 0)
				return (0);
		}
		node.value = va_arg(ap, unsigned long long);
		if (finale(&node, final, &temp) == 0)
			return (0);
	}
	return (node.count);
}
