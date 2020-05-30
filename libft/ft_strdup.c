/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 13:55:38 by cchieko           #+#    #+#             */
/*   Updated: 2019/04/25 18:47:26 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*result;

	if (!(result = (char *)ft_memalloc(ft_strlen(src) + 1)))
		return (NULL);
	return (ft_strcpy(result, src));
}
