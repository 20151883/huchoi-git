#include "ft_printf.h"

int free_ret_zero(char **p, char *s1, char *s2, int my_case)
{
    int i;

    i = 1;
    while(i < my_case)
    {
        free(p[i++]);
    }
    if (s1 != 0)
        free(s1);
    if (s2 != 0)
        free(s2);
    return (0);
}

/*char *renewer_str(char**p_dest, char *dest, char *joined_str)
{
    char *temp;
    if (p_dest != 0)
    {
        if (0 == (temp = (ft_strjoin(*p_dest, joined_str))))
        {
             free_ret_zero(p_dest, 0, 0);
             return (NULL);
        }
        *p_dest = temp;
    }
    else if (dest != 0)
    {
        if (0 == (temp =(ft_strjoin(dest))))
        {
            free_ret_zero(0, dest, 0);
            return (NULL);
        }
    }
}//renewer str... if error it rturn (0) (free is done)
*/
int not_star(char **line, char *str, char **p_temp, t_node *p_node)
{
    char two[2];
    char *arr;

    two[1] = '\0';
	two[0] = str[p_node->idx];
	if (0 == (arr = ft_strjoin(*p_temp, two)))
        return (free_ret_zero(line, *p_temp, NULL, p_node->my_case));
    free(*p_temp);
    *p_temp = arr;
	(p_node->idx)++;
    return (1);//free is not done in here
}

int star(char **line, char **p_temp, char *buf, int my_case, t_node *p_node)
{
    char two[2];
    char *arr;
    char *test;
    if (buf == 0)
        return (0);
    two[1] = '\0';
    if (0 == (arr = malloc(ft_strlen(buf) + 1)))
        return (free_ret_zero(line, *p_temp, buf, my_case));
	if (my_case == 2 && (ft_strchr(buf, '-')))
    {
		two[0] = '-';
		if (0 == (test = ft_strjoin(line[1], two)))
            return (free_ret_zero(line, *p_temp, buf, my_case));
        free(line[1]);
        line[1] = test;
	}
    if (my_case == 3)
        p_node->two_star = 1;
	if (0 == (arr = ft_strjoin(*p_temp, buf)))
        return (free_ret_zero(line, *p_temp, buf, my_case));
    free(*p_temp);
    free(buf);
    *p_temp = arr;
    //printf("\n\n\n\%s\n\n", arr);
    return (1);
}

int case_changed(char **line, char **p_temp, int *p_my_case)
{
    if (0 == (line[*p_my_case] = ft_strdup(*p_temp)))
        return (free_ret_zero(line, *p_temp, 0, *p_my_case));//***
    (*p_my_case)++;
    ft_memset(*p_temp, '\0', ft_strlen(*p_temp));
    **p_temp = '\0';
    return (1);
}

int flag_precise(char **line, char **p_temp,t_node *p_node)
{
    char two[2];
    char *arr;
    char *str;

    str = p_node->string;
    two[1] = '\0';
    if (str[p_node->idx] == '.')
    {    
        (p_node->idx)++;
        p_node->is_precision = 1;
    }
    else if (str[p_node->idx] == '-' || str[p_node->idx] == '0')
    {
        two[0] = str[p_node->idx];
        if (0 == (arr = ft_strjoin(*p_temp, two)))
            return (free_ret_zero(line, *p_temp, 0, p_node->my_case));
        (p_node->idx)++;
        free(*p_temp);
        *p_temp = arr;
    }
    return (1);
}

int real_complete_final(t_node *p_node, char **line, char**p_temp)
{
    char *arr;
    char *str;
    int i;

    str = p_node->string;
    i = p_node->idx;
    if (0 == (line[5] = ft_strdup(*p_temp)))
        return (free_ret_zero(line, *p_temp, NULL, p_node->my_case));
    //printf("\n\n\ntset : %s", line[3]);
    if (0 == (arr = make_string(p_node, line,p_temp, str[i])))
        return (0);//free is done??? yes...!
    if (!ft_strncmp(line[5], "(null)"))
        ft_putstr_fd(arr, 1);
    //printf("line[1]%s line[2]%s line[3]%s line[4]%s line[5]%s",line[1], line[2], line[3], line[4], line[5]);
    free_ret_zero(line, *p_temp, arr, 6);
    (p_node->idx)++;
    p_node->my_case = 1;
    p_node->is_precision = 0;
    p_node->buf = 0;
    p_node->two_star = 0;
    return (1);
}