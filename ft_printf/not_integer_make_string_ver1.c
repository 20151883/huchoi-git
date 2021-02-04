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

int compute_lenth(t_node *p_node, char **line, int *p_size, int *p_lenth)
{
    *p_size = ft_strlen(line[5]);
    if ((0 < ft_atoi(line[3])) && (ft_atoi(line[3])) < *p_size)
        *p_size = ft_atoi(line[3]);
    *p_lenth = *p_size;
    if (lenth < atoi_positive(line[2]) && *line[2] != '\0')
        *p_lenth =atoi_positive(line[2]);
    else
        *p_lenth = *p_lenth + 0;
    if (ft_atoi(line[3]) == 0 && p_node->is_precision == 1)
    {
        if (ft_atoi(line[3]) == 0)
        {
            *p_lenth = 0;
            *p_size = 0;
        }
        if (atoi_positive(line[2]) > 0)
        {
            p_node->count += atoi_positive(line[2]);
            while ((*p_size)++ < atoi_positive(line[2]))
                ft_putchar_fd(' ', 1);
            return (0);
        }
    }
    return (1);
}
