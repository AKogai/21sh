/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 12:35:10 by sfranc            #+#    #+#             */
/*   Updated: 2016/11/16 17:33:32 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	if (c)
		write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long int	nb;
	int			len;
	char		s[10];

	nb = (long int)n;
	if (nb == 0)
	 	ft_putchar('0');
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	len = 0;
	while (nb > 0)
	{
		s[len++] = nb % 10 + 48;
		nb = nb / 10;
	}
	while (len-- > 0)
		ft_putchar(s[len]);
}

int		main()
{
	int n = 2147483647;

	ft_putnbr(n);
	ft_putchar('\n');
	n = 9;
	while (n-- > 0)
	{
		ft_putnbr(n);
		ft_putchar('\n');
	}
	n = -2147483648;
	ft_putnbr(n);
	return (0);
}
