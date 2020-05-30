/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 17:28:32 by sfranc            #+#    #+#             */
/*   Updated: 2017/08/02 17:29:39 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strmerge(char **origin, char *add)
{
	char *temp;

	if (!*origin)
		*origin = ft_strdup(add);
	else
	{
		temp = *origin;
		*origin = ft_strjoin(*origin, add);
		free(temp);
	}
}
