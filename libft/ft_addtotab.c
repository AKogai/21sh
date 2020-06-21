/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addtotab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 14:57:36 by sfranc            #+#    #+#             */
/*   Updated: 2019/06/07 15:48:35 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    **ft_addtotab(char **tab, char *add)
{
	char    **new;
	char    **tmp;
	int             len;
	int             i;

	if (tab)
		len = ft_tablen(tab) + 1;
	else
		len = 1;
	if (!(tmp = (char **)ft_memalloc(sizeof(char *) * (len + 1))))
		return (NULL);
	new = tab;
	i = 0;
	while (new && *(new + i))
	{
		*(tmp + i) = ft_strdup(*(new + i));
		i++;
	}
	*(tmp + i) = ft_strdup(add);
	i++;
	*(tmp + i) = NULL;
	ft_free_array(new);
	tab = tmp;
	return (tab);
}
