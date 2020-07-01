/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:07:08 by cchieko           #+#    #+#             */
/*   Updated: 2019/12/21 17:11:25 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstdel(t_dlst **elem, void (*del)(void *, size_t))
{
	t_dlst	*lst;

	if (!elem || !*elem || !del)
		return ;
	lst = *elem;
	while (*elem)
	{
		del((*elem)->data, (*elem)->data_size);
		lst = lst->next;
		ft_memdel((void**)elem);
		*elem = lst;
	}
}
