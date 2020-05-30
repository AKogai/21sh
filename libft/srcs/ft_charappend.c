/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charappend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 14:46:21 by sfranc            #+#    #+#             */
/*   Updated: 2017/07/21 14:47:28 by sfranc           ###   ########.fr       */
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
