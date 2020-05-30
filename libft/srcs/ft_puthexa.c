/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:15:43 by sfranc            #+#    #+#             */
/*   Updated: 2019/06/07 15:49:21 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthexa(unsigned long long nbr)
{
	const char	hex[16] = "0123456789abcdef";
	char		s[16];
	int			i;

	i = 0;
	ft_memset(s, '0', 16);
	while (nbr != 0)
	{
		s[i++] = hex[nbr % 16];
		nbr /= 16;
	}
	i = 16;
	while (i--)
		ft_putchar(s[i]);
}

void	ft_puthexa_uint64(uint64_t nbr)
{
	const char	hex[16] = "0123456789abcdef";
	char		s[16];
	int			i;

	i = 0;
	ft_memset(s, '0', 16);
	while (nbr != 0)
	{
		s[i++] = hex[nbr % 16];
		nbr /= 16;
	}
	i = 16;
	while (i--)
		ft_putchar(s[i]);
}

void	ft_puthexa_uint32(uint32_t nbr)
{
	const char	hex[16] = "0123456789abcdef";
	char		s[8];
	int			i;

	i = 0;
	ft_memset(s, '0', 8);
	while (nbr != 0)
	{
		s[i++] = hex[nbr % 16];
		nbr /= 16;
	}
	i = 8;
	while (i--)
		ft_putchar(s[i]);
}
