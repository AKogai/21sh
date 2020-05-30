/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 17:10:58 by cchieko           #+#    #+#             */
/*   Updated: 2019/04/26 13:12:08 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = -1;
	while (dst[i] && i < size)
		i++;
	while ((src[++j]) && ((i + j + 1) < size))
		dst[i + j] = src[j];
	if (i != size)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
