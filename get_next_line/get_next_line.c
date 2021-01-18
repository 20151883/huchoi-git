/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 10:43:14 by marvin            #+#    #+#             */
/*   Updated: 2021/01/14 10:14:13 by huchoi           ###   ########.fr       */
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

    buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    while((ret = read(fd, buf, BUFFER_SIZE)) >= 0)
    {
        buf[ret] = '\0';//NULL terminated
        if (ret = 0)
        {
            if (!backup)
            {
                *line = strdup(backup);
                free(buf);
                free(backup);
                backup = NULL;
                return (1);//return zero or one ??!!!???!!!
            }
            else
            {
                *line = strdup("");
                return (0);//return zero is coreect...! because main process the free(line)!!
            }
        }
        else if (0 < ret && ret <= BUFFER_SIZE)
        {
            if (!backup)
            {
                temp = strjoin(backup, buf);
                free(backup);
                backup = temp;
                if ((p = strchr(backup, '\n') == 0)
                {
                    continue;
                }
                else
                {
                    *p = 0;
                    *line = strdup(backup);
                    temp = strdup(++p);
                    free(backup);
                    backup = temp;
                    return (1);
                }
            }
            else
            {
                backup = strdup(buf);
                if ((p = strchr(backup, '\n') == 0)
                {
                    continue;
                }
                else
                {
                    *p = 0;
                    *line = strdup(backup);
                    temp = strdup(++p);
                    free(backup);
                    backup = temp;
                    return (1);
                }
            }
        }
    }
    return (-1);
}
