/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:48:31 by huchoi            #+#    #+#             */
/*   Updated: 2021/01/23 15:28:33 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_back_buf(char *p1, char *p2)
{
	if (p1 != 0)
		free(p1);
	if (p2 != 0)
		free(p2);
}

int		renewer_backup(char **line, char **p_backup, char **p_buf, char *p)
{//개행문자 전까지 문자열 line에 집어넣기, 개행문자 이후의 내용을 backup에대가 저장
	char *temp;

	*p = '\0';
	if (0 == (*line = ft_strdup(*p_backup)))
	{
		free_back_buf(*p_backup, *p_buf);
		return (-1);
	}
	if (0 == (temp = ft_strdup(++p)))
	{
		free_back_buf(*p_backup, *p_buf);
		return (-1);
	}
	free_back_buf(*p_backup, *p_buf);
	*p_backup = temp;
	return (1);
}

int		case_ret_zero(char **line, char **p_backup, char **p_buf)
{
	char *p;

	if (*p_backup != NULL)//backup = "\n\n\n\0"
	{
		if (0 != (p = ft_strchr(*p_backup, '\n')))
			return (renewer_backup(line, p_backup, p_buf, p));//line = ""  backup = "\n\n\0"
		if (0 == (*line = (char *)ft_strdup(*p_backup)))
		{
			free_back_buf(*p_backup, *p_buf);
			return (-1);
		}
		free_back_buf(*p_backup, *p_buf);
		*p_backup = NULL;
		return (0);
	}
	if (0 == (*line = ft_strdup("")))
	{
		free(*p_buf);
		return (-1);
	}
	free(*p_buf);
	return (0);
}

int		case_ret_non_zero(char **line, char **p_backup, char **p_buf)//buf = new(\n)n(\0)
{
	char *p;
	char *temp;

	if (*p_backup != NULL)
	{
		if (0 == (temp = ft_strjoin(*p_backup, *p_buf)))
		{
			free_back_buf(*p_backup, *p_buf);
			return (-1);
		}
		free(*p_backup);
		*p_backup = temp;//backup :" new a"
		p = ft_strchr(*p_backup, '\n');
		if (p == (char *)NULL)
			return (42);
		return (renewer_backup(line, p_backup, p_buf, p));
	}
	if (0 == (*p_backup = ft_strdup(*p_buf)))//backup = new(\n)n(\0)
	{
		free_back_buf(*p_backup, *p_buf);
		return (-1);
	}
	if (0 == (p = ft_strchr(*p_backup, '\n')))//개행체크
		return (42);
	return (renewer_backup(line, p_backup, p_buf, p));
}

int		get_next_line(int fd, char **line)
{
	static char *backup;
	char		*buf;
	int			ret;

	if (BUFFER_SIZE < 1 || fd < 0 || line == 0)//backup = n(\0)
		return (-1);
	if (0 == (buf = malloc(sizeof(char) * (5 + 1))))//backup = "\n\n\n\0"
		return (-1);
	while ((ret = read(fd, buf, 5)) >= 0)//ret = 0
	{
		buf[ret] = '\0';//buf = "\0"
		if (ret == 0)
			return (case_ret_zero(line, &(backup), &buf));//
		else if (0 < ret && ret <= BUFFER_SIZE)
		{
			ret = case_ret_non_zero(line, &(backup), &buf);//line = "", backup = "\n\n\n"
			if (ret == 42)
				continue;
			return (ret);
		}
	}
	return (-1);
}
