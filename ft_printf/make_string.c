#include "ft_printf.h"

char *make_string(char **final, char the_type)//출력해야할 최종적 문자열을 만들어서 반환한다 (space,0채우기 &우측좌측정렬 완료된 문자열)
{
    if (the_type == 'c')
        return (case_c(final));
    else if (the_type == 's')
        return (case_s(final));
    else if (the_type == 'p')
        return (case_p(final));
    else if (the_type == '%')
        return (case_percent(final));
    else if (the_type == 'd')
        return (case_d(final));
    else if (the_type == 'i')
        return (case_i(final));
    else if (the_type == 'u')
        return (case_u(final));
    else if (the_type == 'x')
        return (case_x(final));
    else if (the_type == 'X')
        return (case_X(final));
    else
        return (0);
}
