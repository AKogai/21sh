/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intputchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:07:08 by cchieko           #+#    #+#             */
/*   Updated: 2019/12/21 17:11:25 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_array(char **array)
{
	size_t i;

	i = 0;
	if (array == NULL || array[0] == NULL)
		return (-1);
	while (array[i] != NULL)
	{
		ft_putendl(array[i]);
		i++;
	}
	return (0);
}
