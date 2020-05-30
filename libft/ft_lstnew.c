/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 20:21:48 by cchieko           #+#    #+#             */
/*   Updated: 2019/07/11 20:29:59 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new)
	{
		if (!content)
		{
			new->content = NULL;
			new->content_size = 0;
		}
		else
		{
			if (!(new->content = malloc(content_size)))
			{
				free(new);
				return (NULL);
			}
			ft_memcpy(new->content, content, content_size);
			new->content_size = content_size;
		}
		new->next = NULL;
		return (new);
	}
	return (NULL);
}
