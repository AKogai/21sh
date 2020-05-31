/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 13:41:08 by cchieko           #+#    #+#             */
/*   Updated: 2019/04/26 20:01:14 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	char	*b;
	int		i;
	int		length;

	if (s == NULL)
		return (NULL);
	length = ft_strlen(s);
	while (s[length - 1] == ' ' || s[length - 1] == '\t' ||
		s[length - 1] == '\n')
		length--;
	i = -1;
	while (s[++i] == ' ' || s[i] == '\t' || s[i] == '\n')
		length--;
	if (length <= 0)
		length = 0;
	if (!(b = (char *)ft_memalloc(sizeof(char) * length + 1)))
		return (NULL);
	s += i;
	i = -1;
	while (++i < length)
		b[i] = *s++;
	b[i] = '\0';
	return (b);
}
