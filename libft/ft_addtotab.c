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

char	**ft_addtotab(char **tab, char *add)
{
	char	**new;
	int		len;
	int		i;

	if (tab)
		len = ft_tablen(tab) + 1;
	else
		len = 1;
	if (!(new = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	*(new + len) = 0;
	i = 0;
	while (tab && *(tab + i))
	{
		*(new + i) = *(tab + i);
		i++;
	}
	*(new + i) = ft_strdup(add);
	free(tab);
	return (new);
}
