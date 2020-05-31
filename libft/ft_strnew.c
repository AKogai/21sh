/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:35:09 by cchieko           #+#    #+#             */
/*   Updated: 2019/04/27 14:08:10 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;
	size_t	i;

	s = (char *)malloc(size + 1);
	if (s == NULL)
		return (NULL);
	i = 0;
	while (i <= size)
	{
		s[i] = '\0';
		i++;
	}
	return (s);
}
