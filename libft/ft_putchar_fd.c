/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 11:04:59 by cchieko           #+#    #+#             */
/*   Updated: 2019/04/27 11:50:02 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	unsigned char	ch;
	unsigned char	u[2];

	ch = (unsigned char)c;
	if (ch < 128)
		write(fd, &c, 1);
	else
	{
		u[0] = 192 | (ch >> 6);
		u[1] = 128 | (63 & ch);
		write(fd, u, 2);
	}
}
