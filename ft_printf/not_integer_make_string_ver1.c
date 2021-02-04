#include "./includes/ft_printf.h"

void check_null(t_node *p_node, char **line, char **p_temp)
{
    int i;

    i = 0;
    if (ft_strncmp(line[5], "(null", 10) == 0)
    {
        if (1 > atoi_positive(line[2]))
            lenth = 1;
        else
            lenth = atoi_positive(line[2]);
    }
    else
    {
        while ((i++ < lenth - 1) && p_node->two_star == 0)
        {
            ft_putchar_fd(' ', 1);
            p_node->count++;
        }
        ft_putchar_fd(0, 1);
        p_node->count++;
    }
    return (ft_strdup(""));
}