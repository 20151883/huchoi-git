#include "ft_printf.h"


char *free_ret_zero(char **p, char *s1, char *s2)
{
    int i;

    i = 1;
    while(i <= 5)
    {
        free[p[i++]];
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
char *first(char *str, int *p_i)
{
    char *alloc;
    char *temp;

    while(ft_strchr("cspdiuxX%", str[i]) == 0)
	{
		if (my_case != what_my_case(str[i], my_case))
		{
			final[my_case] = ft_strdup(temp);
			my_case++;
			ft_memset(temp, '\0', sizeof(char)*(ft_strlen(temp) + 1));
			*temp = '\0';
			continue;
		}
		if(str[i] == '.')
		{	
			i++;
			continue;
		}
		if (str[i] == '-' || str[i] == '0')
    	{
			two[0] = str[i];
			temp = ft_strjoin(temp, two);
			i++;
			continue;
		}
		if (str[i] != '*')
		{
            not_star(str, &temp, &i)
			/*two[0] = str[i];
			temp = ft_strjoin(temp, two);
			i++;
			continue;*/
		}
		else
		{
            star(str, i, ft_itoa(va_arg(ap, int)));
			/*buf = ft_itoa(va_arg(ap, int));
			if (my_case == 2 && (ft_strchr(buf, '-')))
			{
				two[0] = '-';
				final[1] = ft_strjoin(final[1], two);
				buf[0] = '0';//minus is interchaned to '0'
			}
			temp = ft_strjoin(temp, buf);
			free(buf);
			buf = 0;*/
			i++;
			if (what_my_case(str[i], my_case) == my_case)
				return (-1);
			continue;
		}
	}
}

int not_star(char **line, char *str, char **p_temp, int *p_i)
{
    char two[2];
    char *arr;

    two[1] = '\0';
	two[0] = str[i];
	if (0 == (arr = ft_strjoin(*p_temp, two)))
        return (free_ret_zero(line, *p_temp, NULL));
    free(*p_temp);
    *p_temp = arr;
	*p_i++;
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
	if (0 == (arr = ft_strjoin(temp, buf)))
        return (free_ret_zero(line, *p_temp, buf));
    free(*p_temp);
    free(buf);
    *p_temp = arr;
    return (1);
}

int case_changed(char **line, char **p_temp, int *p_my_case)
{
    if (0 == (line[*p_my_case] = ft_strdup(*p_temp)))
        return (free_ret_zero(line, temp, 0));//***
    (*p_my_case)++;
    ft_memeset(*p_temp, '\0', ft_strlen(*p_temp));
    **p_temp = '\0';
    return (1);
}

int flag_precise(char **line, char **p_temp,char *str, int *p_i)
{
    char two[2];
    char *arr;

    two[1] = '\0';
    if (str[*p_i] == '.')
        *p_i++;
    else if (str[*p_i] == '-' || str[*p_i] == '0')
    {
        two[0] = str[i];
        if (0 == (arr = ft_strjoin(temp, two)))
            return (free_ret_zero(line, *p_temp, 0));
        (*p_i)++
    }
    return (1);
}