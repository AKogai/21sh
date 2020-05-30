/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supprtotab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 11:22:57 by sfranc            #+#    #+#             */
/*   Updated: 2019/06/07 15:51:39 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_supprtotab(char **tab, int suppr)
{
	char	**new;
	int		len;
	int		i;
	int		j;

	if (tab)
		len = ft_tablen(tab) - 1;
	else
		return (NULL);
	if (!(new = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	*(new + len) = 0;
	i = 0;
	j = 0;
	while (*(tab + j))
	{
		if (j != suppr)
			*(new + i++) = *(tab + j++);
		else
			free(*(tab + j++));
	}
	free(tab);
	return (new);
}
