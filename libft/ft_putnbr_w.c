/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_w.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:22:33 by cchieko           #+#    #+#             */
/*   Updated: 2019/12/21 17:24:39 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_w(int number, int width)
{
	int i;

	i = ft_intlen(number);
	while (i++ < width)
		ft_putchar(' ');
	ft_putnbr(number);
}
