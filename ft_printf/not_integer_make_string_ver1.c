#include "./includes/ft_printf.h"

int check_null(t_node *p_node, char **line, char **p_temp, int *p_lenth)
{
    int i;

    i = 0;
    *p_lenth = 1;
    if (ft_strncmp(line[5], "(null", 10) == 0)
    {
        if (1 < atoi_positive(line[2]))
            *p_lenth = atoi_positive(line[2]);
        if (ft_strchr(line[2], '-'))
		{
			ft_putchar_fd(0,1);
			while ((i++ < *p_lenth - 1) && p_node->two_star == 0)
				ft_putchar_fd(' ' ,1);
		}
		else
		{
			while ((i++ < *p_lenth - 1) && p_node->two_star == 0)
				ft_putchar_fd(' ', 1);
			ft_putchar_fd(0, 1);
		}
        p_node->count += *p_lenth;
		return (1);
    }
    else
        return (0); 
}