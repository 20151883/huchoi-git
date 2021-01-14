/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:11:23 by marvin            #+#    #+#             */
/*   Updated: 2021/01/14 10:24:58 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET_NEXT_LINE__
#define __GET_NEXT_LINE__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#define BUFFER_SIZE 이거 안넣어도 됨...
int get_next_line(int fd, char **line); 
int check_buffer(char *buf, int size);
int add_new_str(char **line, char *str);
void get_new_str(char **str, char *buf, int plus);
int ft_strlen(char *str);
int ft_strlcat(char *dest, char *src, int size);
#endif
