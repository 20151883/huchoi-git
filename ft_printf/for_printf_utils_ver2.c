#include "ft_printf.h"

int complete_final(char **line, int *p_my_case, char **p_temp)
{
    if (0 == (final[*p_my_case] = ft_strdup(*p_temp)))
        return (free_ret_zero(line, *p_temp, 0));
    (*p_my_case)++;
    while(*p_my_case < 5)
        if (0 == (final[*p_my_case] = ft_strdup("")))
            return (free_ret_zero(line, *p_temp, 0));
        (*p_my_case)++;
    ft_memset(*p_temp, '\0', ft_strlen(*p_temp) + 1);
    **p_temp = '\0';
    return (1);
}

int pro_arg(char the_tpye, void )
{
    if(the_type == 'c')
	{
		two[0] = (char)va_arg(*p_ap, int);
		temp = ft_strjoin(temp, two);
	}
	else if(the_type == 's')
	{
		arr = va_arg(*p_ap, char *);
		temp = ft_strdup(arr);
	}
	else if(the_type == 'p')
	{
	    return (-1);
	}
	else if(the_type == '%')
	{
		two[0] = '%';
		temp = ft_strjoin(temp, two);
	}
	else if (ft_strchr("di", the_type))//숫자 부분
		temp = ft_itoa(va_arg(*p_ap, int));
	else
		temp = ft_itoa(va_arg(*p_ap, unsigned int));
}