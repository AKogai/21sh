/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_itoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:10:48 by sfranc            #+#    #+#             */
/*   Updated: 2017/01/11 16:24:46 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		main(int ac, char **av)
{
	int		value;
	int		base;
	char 	*result;

	if (ac != 3)
		return (0);
	value = ft_atoi(av[1]);
	base = ft_atoi(av[2]);
	result = ft_itoa_base(value, base);
	ft_putendl(result);
	return (0);	
}

