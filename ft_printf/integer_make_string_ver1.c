#include "ft_printf.h"

void manage_minus_integer(t_node * p_node, char **line, int *p_size, int *p_plus)
{
    *p_size = ft_strlen(line[5]);
    if (ft_atoi(line[5]) < 0)
    {
        if (ft_atoi(line[3]) > (*p_size - 1))
            *p_plus = ft_atoi(line[3]) - (*p_size - 1);
        else
            *p_plus = 0;
    }
    else
    {
        if (p_node->is_precision == 1 && *p_size < ft_atoi(line[3]))
            *p_plus = ft_atoi(line[3]) - *p_size
        else
            *p_plus = 0;
    }
}