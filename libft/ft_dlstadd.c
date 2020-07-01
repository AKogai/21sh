/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:07:08 by cchieko           #+#    #+#             */
/*   Updated: 2019/12/21 17:11:25 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd(t_dlst **alst, t_dlst *new)
{
	if (alst != NULL && *alst == NULL)
		*alst = new;
	else if (alst != NULL && *alst != NULL && new != NULL)
	{
		new->next = *alst;
		new->prev = NULL;
		(*alst)->prev = new;
		*alst = new;
	}
}
