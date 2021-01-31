#include "ft_printf.h"


int free_ret_zero(char **p, char *s1, char *s2)
{
    int i;

    i = 1;
    while(i <= 5)
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
int not_star(char **line, char *str, char **p_temp, int *p_i)
{
    char two[2];
    char *arr;

    two[1] = '\0';
	two[0] = str[*p_i];
	if (0 == (arr = ft_strjoin(*p_temp, two)))
        return (free_ret_zero(line, *p_temp, NULL));
    free(*p_temp);
    *p_temp = arr;
	(*p_i)++;
    return (1);
}

int star(char **line, char **p_temp, char *buf, int my_case)
{
    char two[2];
    char *arr;

    if (buf == 0)
        return (0);
    two[1] = '\0';
    if (0 == (arr = malloc(ft_strlen(buf) + 1)))
        return (free_ret_zero(line, *p_temp, buf));
	if (my_case == 2 && (ft_strchr(buf, '-')))
    {
		two[0] = '-';
		if (0 == (line[1] = ft_strjoin(line[1], two)))
            return (free_ret_zero(line, *p_temp, buf));
		*(ft_strchr(buf, '-')) = '0';//minus is interchaned to '0'
	}
	if (0 == (arr = ft_strjoin(*p_temp, buf)))
        return (free_ret_zero(line, *p_temp, buf));
    free(*p_temp);
    free(buf);
    *p_temp = arr;
    return (1);
}

int case_changed(char **line, char **p_temp, int *p_my_case)
{
    if (0 == (line[*p_my_case] = ft_strdup(*p_temp)))
        return (free_ret_zero(line, *p_temp, 0));//***
    (*p_my_case)++;
    ft_memset(*p_temp, '\0', ft_strlen(*p_temp));
    **p_temp = '\0';
    return (1);
}

int flag_precise(char **line, char **p_temp,char *str, int *p_i)
{
    char two[2];
    char *arr;

    two[1] = '\0';
    if (str[*p_i] == '.')
        (*p_i)++;
    else if (str[*p_i] == '-' || str[*p_i] == '0')
    {
        two[0] = str[*p_i];
        if (0 == (arr = ft_strjoin(*p_temp, two)))
            return (free_ret_zero(line, *p_temp, 0));
        (*p_i)++;
        free(*p_temp);
        *p_temp = arr;
    }
    return (1);
}

int real_complete_final(char **line, char**p_temp, int *p_i)
{
    char *arr;

    if (0 == (final[5] = ft_strdup(*p_temp)))
        return (free_ret_zero(line, *p_temp, NULL));
    if (0 == (arr = make_string(final,str[i])))
        return (0);//free is done??? yes...!
    ft_putstr_fd(arr, 1);
    free_ret_zero(final, temp, 0);
    (*p_i)++;
    return (1);
}

int over_star(char **line, char **p_temp, char **p_buf, int my_case)
{
    if (0 == star(line, p_temp, *p_buf, my_case))
}