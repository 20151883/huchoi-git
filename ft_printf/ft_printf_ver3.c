#include "ft_printf.h"

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
    if (ft_strchr("cspdiuxX%", c) != 0)
        return (5);
    return (-1);
}

typedef struct s_node{
	int count;
	int idx;
	int my_case;
	//va_list...???
	char *string;
	char *buf;
}t_node;

void init_node(t_node* p_node, const char *str)
{
	p_node->count = 0;
	p_node->idx = 0;
	p_node->my_case = 1;
	p_node->string = str;
	p_node->buf = 0;
}

int ft_printf(const char* str, ...)
{
	va_list ap;
	char *temp;
	char *final[6];//final is not use malloc 
	char *buf;
	t_node node;

	init_node(&node, str);
	va_start(ap, str);
	while (node.string[node.idx] != '\0')
	{
		if(node.string[node.idx] != '%')
		{
			ft_putchar_fd(node.string[node.idx], 1);
			node.idx++;
			continue;
		}
		node.idx++;
		if (0 == (temp = ft_calloc(1, sizeof(char))))
			return (free_ret_zero(NULL, temp, NULL));
		while (ft_strchr("cspdiuxX%", node.string[node.idx]) == 0)
		{
			if (node.my_case != what_my_case(node.string[node.idx], node.my_case))
			{
				if (!case_changed(final, &temp, &(node.my_case)))
					return (0);
				continue;
			}
			if (ft_strchr(".-0", node.string[node.idx]) != 0)
			{
				if (flag_precise(final, &temp, (char *)node.string, &(node.idx)) == 1)
					continue;
				else
					return (0);
			}
			if (str[node.idx] != '*')
			{
				if (1 == not_star(final, (char *)node.string, &temp, &(node.idx)))
					continue;
				else
					return (0);
			}
			else
			{	
				if (0 == (node.buf = ft_itoa(va_arg(ap, int))))
					return (free_ret_zero(final, temp, NULL));
				if (0 == star(final, &temp, node.buf, node.my_case))
					return (0);
				buf = 0;
				if (what_my_case(node.string[++node.idx], node.my_case) == node.my_case)
					return (free_ret_zero(final, temp, NULL));
			}
		}
		if (0 == complete_final(final, &node.my_case, &temp))
			return (0);//if over if is true... free action is done already
		if (0 == inter_type(final, &temp, va_arg(ap, unsigned long long), str[node.idx]))
            return (0);//if over if is ture... free actoin is already doen...!
        if (0 == real_complete_final(final, &temp, &node.idx))
			return (0);
		/*if (0 == (final[5] = ft_strdup(temp)))
			return (free_ret_zero(final, temp, 0));
		//printf("[1: %s][2: %s][3 : %s][4 : %s]\n",final[1], final[2], final[3], final[5]);
		ft_putstr_fd(make_string(final, str[i]), 1);
		free_ret_zero(final, temp, 0);
		i++;*/

	}
	return (node.count);
}
