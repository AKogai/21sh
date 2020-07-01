/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:43:03 by cchieko           #+#    #+#             */
/*   Updated: 2019/04/27 14:04:49 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *string;

	string = (unsigned char *)malloc(size);
	if (!string)
		return (NULL);
	while (size > 0)
	{
		size--;
		string[size] = '\0';
	}
	return ((void *)string);
}
