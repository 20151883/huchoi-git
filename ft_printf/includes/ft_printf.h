#ifndef _FT_PRINTF_H_
#define _FT_PRINTF_H_
#include <stdarg.h>
#include <stdio.h>
#include "../libft/libft.h"
extern va_list ap;
typedef struct s_node{
	int count;
	int idx;
	int my_case;
	//va_list...???
	char *string;
	char *buf;
    int ret;
    unsigned long long value;
    int num[3];
	int two_star;
	int is_precision;
}t_node;
char *trim_the_zero(char **line);
int atoi_positive(char *str);
int check_zero(char **line, int *p1, int *p2, int *p3);
void manage_minus_integer(t_node * p_node, char **line, int *p_size, int *p_plus);
void my_putchar_fd(t_node *p_node);
int important(t_node *p_node, char **line, char **p_temp);
int finale(t_node*p_node, char **line, char **p_temp);
int over_star(t_node *p_node, char **line, char**p_temp);
void init_node(t_node* p_node, const char *str);
int contact_with_format(t_node *p_node, char **line, char **p_temp);
int real_complete_final(t_node *p_node, char **line, char**p_temp);
char *ten_unsigned(unsigned int num);
int letter_uxX(char **line, char **p_temp, unsigned long long value, char the_tpye);
int letter_di(char **line, char **p_temp, unsigned long long value);
int letter_p(char **line, char **p_temp, unsigned long long value);
int letter_s(char **line, char **p_temp, unsigned long long value);
int letter_c_percent(char **line, char **p_temp, unsigned long long value);
int inter_type(char **line, char **p_temp, unsigned long long value, char the_type);
int complete_final(char **line, int *p_my_case, char **p_temp);
int flag_precise(char **line, char **p_temp, t_node *p_node);
int case_changed(char **line, char **p_temp, int *p_my_case);
int star(char **line, char **p_temp, char *buf, int my_case, t_node *p_node);
int not_star(char **line, char *str, char **p_temp, t_node *p_node);
int free_ret_zero(char **p, char *s1, char *s2, int my_case);
char *precision_int(char **line, int plus, int size, int lenth);
char *precision_unsigned(char **line, int plus, int size, int lenth);
char *no_precision_unsigned(char **line, int plus, int size, int lenth);
char *no_precision_int(char **line, int plus, int size, int lenth);
char *ten_big_hex(unsigned int num);
char *ten_small_hex(unsigned int num);
int ft_printf(const char *str, ...);
int what_my_case(char c, int now_case);
char *make_string(t_node *p_node, char **final, char **p_tmep, char the_type);
char *case_c(t_node *p_node, char **final, char **p_temp);
char *case_s(t_node *p_node, char **final, char **p_temp);
char *case_p(t_node *p_node, char **final, char **p_temp);
char *case_percent(t_node *p_node, char **final, char **p_temp);
char *case_d(t_node *p_node, char **final);
char *case_i(t_node *p_node, char **final);
char *case_u(t_node *p_node, char **final);
char *case_x(t_node *p_node, char **final);
char *case_X(t_node *p_node, char **final);
#endif
