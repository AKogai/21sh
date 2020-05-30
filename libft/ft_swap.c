/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 15:44:08 by cchieko           #+#    #+#             */
/*   Updated: 2019/12/23 15:49:40 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(void *data1, void *data2, size_t size)
{
	unsigned char	*temp;

	if (!(temp = (unsigned char*)malloc(sizeof(unsigned char) * size)))
		return ;
	else
	{
		ft_memmove(temp, data1, size);
		ft_memmove(data1, data2, size);
		ft_memmove(data2, temp, size);
	}
	free(temp);
}
