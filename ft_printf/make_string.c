#include "./includes/ft_printf.h"

char *make_string(t_node *p_node, char **final, char **p_temp, char the_type)//출력해야할 최종적 문자열을 만들어서 반환한다 (space,0채우기 &우측좌측정렬 완료된 문자열)
{
    if (the_type == 'c')
        return (case_c(p_node, final, p_temp));
    else if (the_type == 's')
        return (case_s(p_node, final, p_temp));
    else if (the_type == 'p')
        return (case_p(p_node, final, p_temp));
    else if (the_type == '%')
        return (case_percent(p_node, final, p_temp));
    else if (the_type == 'd')
        return (case_d(p_node, final));
    else if (the_type == 'i')
        return (case_i(p_node, final));
    else if (the_type == 'u')
        return (case_u(p_node, final));
    else if (the_type == 'x')
        return (case_x(p_node, final));
    else if (the_type == 'X')
        return (case_X(p_node, final));
    else
        return (0);
}
