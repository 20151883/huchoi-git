#ifndef _FT_PRINTF_H_
#define _FT_PRINTF_H_
#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>

int what_my_case(char c, int now_case);
char *make_string(char **final, char the_type);
char *case_c(char **final);
char *case_s(char **final);
char *case_p(char **final);
char *case_percent(char **final);
char *case_d(char **final);
char *case_i(char **final);
char *case_u(char **final);
char *case_x(char **final);
char *case_X(char **final);
#endif