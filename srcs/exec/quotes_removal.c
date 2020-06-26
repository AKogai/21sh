/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_removal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:07:08 by cchieko           #+#    #+#             */
/*   Updated: 2020/06/21 17:11:25 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

void	ft_remove_quoting(t_shell *shell, t_token *token)
{
	t_token *tmp;
	char	*new;

	tmp = token;
	while (tmp)
	{
		if (tmp->token_type == WORD)
		{
			new = ft_remove_quotes(tmp->str);
			free(tmp->str);
			tmp->str = new;
		}
		if (tmp->operator_type == DLESS)
		{
			ft_heredoc_expand_remove_quoting(shell, tmp);
		}
		tmp = tmp->next;
	}
}
