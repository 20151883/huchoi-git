/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:11:17 by marvin            #+#    #+#             */
/*   Updated: 2021/01/14 12:05:26 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int check_buffer(char *buf, int size)//return the count value and this function's return value is prommised
{
    int count;
    
    count = 0;
    while (count < size)
    {
        if (buf[count] == '\n')
            return (count);
        count++;
    }
    return (count);
}

int ft_strlen(char *str)// fact : max_idx = the number of member - 1  
{
    int ret;

    ret = 0;
    while (str[ret])
    {
        ret++;
    }
    return (ret);
}

int ft_strlcat(char *dest, char *src, int size)//study this function
{
    int i;
    int j;

	i = 0;
	j = 0;
	if (ft_strlen(dest) > size)
		return (ft_strlen(src) + size);
	else
	{
		while(dest[i] != '\0')
			i++;
		while (src[j] && i < (size - 1))
		{
			dest[i] = src[j];
			j++;
			i++;
		}
		dest[i] = '\0';
		//while(*src)
		//	i++;
		return (i);
	}
}

int add_new_str(char **line, char *str)
{
    int size;
    int i;
    char **temp;

    size = 0;
    while(line[size])
        size++;
    temp = (char **)malloc(sizeof(char *) * (size + 2));
    if (temp == 0)
        return (-1);
    i = 0;
    while(line[i] != 0)
    {
        temp[i] = line[i];
        i++;
    }
    free(line);
    line = temp;
    line[i++] = str;
    line[i] = 0;
	return (0);
}

void get_new_str(char **str, char *buf, int plus)
{
    char * temp;

    temp = malloc(sizeof(char) * ft_strlen(*str) + plus+ 1);
    temp[0] = '\0';
    ft_strlcat(temp, *str, ft_strlen(*str) + 1);
    ft_strlcat(temp, buf, plus + 1);//in this line ret has the number of byte that read func has read...
    free(*str);
    *str = temp;
}
