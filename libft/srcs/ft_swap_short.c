/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_short.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 21:17:10 by sfranc            #+#    #+#             */
/*   Updated: 2019/02/16 21:17:21 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned short	ft_swap_short(unsigned short n)
{
	unsigned short	swap;

	swap = ((n >> 8) & 0xFF)
		| ((n << 8) & 0xFF00);
	return (swap);
}
