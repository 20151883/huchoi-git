/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 10:43:14 by marvin            #+#    #+#             */
/*   Updated: 2021/01/18 20:13:03 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
    static char *backup;
    char *buf;
    int ret;
    char * p;
    char *temp;

	if (BUFFER_SIZE == 0 || BUFFER_SIZE == -1)
		return (-1);
    buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    while((ret = read(fd, buf, BUFFER_SIZE)) >= 0)
    {
        buf[ret] = '\0';//NULL terminated
        if (ret == 0)
        {
            if (backup != NULL)
            {
                *line = (char *)ft_strdup(backup);
                free(buf);
                free(backup);
				if ()
                	backup = NULL;
                return (0);//return zero or one ??!!!???!!!
            }
            else
            {
                *line = ft_strdup("");
				free(buf);
                return (0);//return zero is coreect...! because main process the free(line)!!
            }
        }
        else if (0 < ret && ret <= BUFFER_SIZE)
        {
            if (backup != NULL)
            {
                temp = ft_strjoin(backup, buf);
                free(backup);
                backup = temp;
				p = ft_strchr(backup, '\n');
                if (p == (char *)NULL)
                {
                    continue;
                }
                else
                {
                    *p = 0;
                    *line = ft_strdup(backup);
                    temp = ft_strdup(++p);
                    free(backup);
					free(buf);
                    backup = temp;
                    return (1);
                }
            }
            else
            {
                backup = ft_strdup(buf);
				p = ft_strchr(backup, '\n');
                if (p == (char *)NULL)
                {
                    continue;
                }
                else
                {
                    *p = 0;
                    *line = ft_strdup(backup);
                    temp = ft_strdup(++p);
                    free(backup);
					free(buf);
                    backup = temp;
                    return (1);
                }
            }
        }
    }
    return (-1);
}
