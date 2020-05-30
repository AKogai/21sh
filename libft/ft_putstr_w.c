/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_w.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:32:39 by cchieko           #+#    #+#             */
/*   Updated: 2019/12/21 17:37:57 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_w(char *str, int width, int left_aligned)
{
	int i;
	int length;

	i = 0;
	length = (int)ft_strlen(str);
	if (!left_aligned)
		while (i++ < width - length)
			ft_putchar(' ');
	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
	if (left_aligned)
		while (i++ < width)
			ft_putchar(' ');
}
