/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:07:08 by cchieko           #+#    #+#             */
/*   Updated: 2019/12/21 17:11:25 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlst		*ft_dlstnew(void const *data, size_t data_size)
{
	t_dlst	*elem;

	if ((elem = (t_dlst*)malloc(sizeof(t_dlst))) == NULL)
		return (NULL);
	if (data == NULL || data_size == 0)
	{
		elem->data = NULL;
		elem->data_size = 0;
		free(elem);
	}
	else
	{
		if ((elem->data = (void*)malloc(data_size)) == NULL)
			return (NULL);
		ft_memcpy(elem->data, data, data_size);
		elem->data_size = data_size;
	}
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}
