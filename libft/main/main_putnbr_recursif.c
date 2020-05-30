/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_putnbr_recursif.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 12:35:10 by sfranc            #+#    #+#             */
/*   Updated: 2016/11/16 16:01:56 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	if (c)
		write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long int	nb;

	nb = (long int)n;
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (nb <= 9)
	 	ft_putchar(nb + 48);
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
}

int		main()
{
	int n = 2147483647;

	ft_putnbr(n);
	ft_putchar('\n');
	n = 25;
	while (n-- > 0)
	{
		ft_putnbr(n);
		ft_putchar('\n');
	}
	n = -2147483648;
	ft_putnbr(n);
	return (0);
}
