#include "./includes/ft_printf.h"

int letter_c_percent(char **line, char **p_temp, char value)
{
    char two[2];
    char *arr;

    if (value == 0)
        arr = ft_strdup("(null)");
    else
    {
        two[0] = (char)value;
        two[1] = '\0';
        if (0 == (arr = ft_strjoin(*p_temp, two)))
            return (free_ret_zero(line, *p_temp, NULL, 5));
    }
    free(*p_temp);
    *p_temp = arr;
    return (1);
}

int letter_s(char **line, char **p_temp, char *value)
{
    char *arr;

    if (value == 0)
        arr = ft_strdup("(null)");
    else if (0 == (arr = (ft_strjoin(*p_temp, (char *)value))))
        return (free_ret_zero(line, *p_temp, 0, 5));
    free(*p_temp);
    *p_temp = arr;
    return (1);
}

int letter_p(char **line, char **p_temp, unsigned long long value)
{
    char *buf;
    int idx;
    char *hex;

    if (value == 0)
        return (value_is_zero(p_temp));
    if (0 == (hex = ft_strdup("0123456789abcdef")))
        return (free_ret_zero(line, *p_temp, NULL, 5));
    if (0 == (buf = malloc(sizeof(char) * 15)))
        return (free_ret_zero(line, *p_temp, hex, 5));
    ft_memset(buf, '0', 15);
    idx = 13;
    while (idx > 1 && value > 0)
    {
        buf[idx--] = hex[value % 16];
        value = value / 16;
    }
    buf[idx] = '0';
    buf[0] = '0';
    buf[1] = 'x';
    buf[14] = '\0';
    free(*p_temp);
    free(hex);
    *p_temp = buf;
    return (1);
}

int value_is_zero(char **p_temp)
{
    char *arr;

    if (0== (arr = malloc(sizeof(char) * 4)))
        return (0);
    arr[0] = '0';
    arr[1] ='x';
    arr[2] = '0';
    arr[3] = '\0';
    free(*p_temp);
    *p_temp = arr;
    return (1);
}

int letter_di(char **line, char **p_temp, int value)
{
    char *arr;

    if (0 == (arr = ft_itoa((int)value)))
        return (free_ret_zero(line, *p_temp, NULL, 5));
    if (value == 0)
    {
        free(arr);
        if (0 == (arr = malloc(sizeof(char) * 2)))
            return (free_ret_zero(line, *p_temp, 0, 5));
        arr[0] = '0';
        arr[1] = '\0';
    }
    free(*p_temp);
    *p_temp = arr;
    return (1);
}

int letter_uxX(char **line, char **p_temp, unsigned int value, char the_type)
{
    char *arr;
    unsigned int num;

    arr = NULL;
    num = (unsigned int)value;
    if (the_type == 'u')
    {
        if (NULL == (arr = ten_unsigned(num)))
            return (free_ret_zero(line, *p_temp, NULL, 5));
    }
    else if (the_type == 'x')
    {
        if (0 == (arr = ten_small_hex(num)))
            return (free_ret_zero(line, *p_temp, NULL, 5));
    }
    else
    {
        if (0 == (arr = ten_big_hex(num)))
            return (free_ret_zero(line, *p_temp, 0, 5));
    }
    free(*p_temp);
    *p_temp = arr;
    return (1);
}