/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huchoi <huchoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:52:44 by huchoi            #+#    #+#             */
/*   Updated: 2021/01/06 15:54:31 by huchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			multipl;
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	multipl = count * size;
	ptr = (unsigned char *)malloc(multipl);
	if (!ptr)
		return (void *)(NULL);
	while (i < multipl)
	{
		ptr[i] = '\0';
		i++;
	}
	return (void *)(ptr);
}
