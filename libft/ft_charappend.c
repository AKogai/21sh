/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charappend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:07:08 by cchieko           #+#    #+#             */
/*   Updated: 2019/12/21 17:11:25 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_charappend(char *str, char c)
{
	char	*append;

	if (str)
	{
		append = ft_strnew(ft_strlen(str) + 1);
		append = ft_strcpy(append, str);
	}
	else
		append = ft_strnew(1);
	*(append + ft_strlen(append)) = c;
	ft_strdel(&str);
	return (append);
}
