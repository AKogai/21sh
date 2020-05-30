/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 17:55:41 by cchieko           #+#    #+#             */
/*   Updated: 2019/04/27 13:26:05 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n && (s1[0] || s2[0]) && s1[0] != s2[0])
		return ((unsigned char)s1[0] - (unsigned char)s2[0]);
	if (n && s1[0] && s1[0] == s2[0])
		return (ft_strncmp(s1 + 1, s2 + 1, n - 1));
	return (0);
}
