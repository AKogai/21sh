/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 09:52:11 by cchieko           #+#    #+#             */
/*   Updated: 2019/04/26 16:55:36 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	int_length(int n)
{
	size_t		i;
	size_t		negative;

	i = 1;
	negative = 0;
	if (n < 0)
	{
		n = -n;
		negative = 1;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i + negative);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		length;
	int		negative;

	negative = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	length = int_length(n);
	if (!(str = ft_strnew(length)))
		return (NULL);
	if (n < 0)
	{
		n = -n;
		negative = 1;
	}
	while (length--)
	{
		str[length] = (n % 10) + '0';
		n = n / 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}
