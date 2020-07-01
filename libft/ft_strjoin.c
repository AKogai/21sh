/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 13:05:06 by cchieko           #+#    #+#             */
/*   Updated: 2019/04/27 12:39:51 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	if (!(result = (char*)ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	ft_strcpy(result, s1);
	ft_strcat(result, s2);
	return (result);
}
