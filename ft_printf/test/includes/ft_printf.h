#ifndef _FT_PRINTF_H_
#define _FT_PRINTF_H_
#include ../libft/libft.h
#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
char *precision_int(char **line, int plus, int size, int lenth);
char *no_precision_int(char **line, int plus, int size, int lenth);
char *ten_big_hex(char *str);
char *ten_small_hex(char *str);
int ft_printf(const char *str, ...);
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
