/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_par_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 10:53:56 by huchoi            #+#    #+#             */
/*   Updated: 2021/03/10 13:53:11 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	par_the_line(t_syn *p_syn, char **split, char *buf, int lenth)
{
	if (is_only_zero_blank_one(buf) == 1)
		message_exit();
	split = my_split(buf, " ,\t\v\r\f");
	free(buf);
	while (split[lenth] != 0)
		lenth++;
	case_by_lenth(split, p_syn, lenth);
	while (--lenth >= 0)
		free(split[lenth]);
	free(split);
}
