/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 17:39:58 by cchieko           #+#    #+#             */
/*   Updated: 2019/04/14 17:54:52 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	const char *s1;

	s1 = s;
	while (*s != '\0')
		s++;
	while (s != s1)
	{
		if (*s == (char)c)
			return ((char *)s);
		s--;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
