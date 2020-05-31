/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:06:12 by cchieko           #+#    #+#             */
/*   Updated: 2019/04/26 18:56:52 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t				index;
	unsigned char		*output;
	unsigned const char	*input;

	output = dst;
	input = src;
	index = 0;
	while (index < len)
	{
		output[index] = input[index];
		index++;
	}
	return (dst);
}