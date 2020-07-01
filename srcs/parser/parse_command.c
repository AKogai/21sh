/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:07:08 by cchieko           #+#    #+#             */
/*   Updated: 2020/06/21 17:11:25 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

static int		ft_incomplete_list(t_lexer *lexer)
{
	if (lexer->last->token_type == NEWLINE && lexer->nbr_token > 1\
			&& lexer->last->prev->operator_type == PIPE)
	{
		return (PIPE);
	}
	if (lexer->last->token_type == NEWLINE && lexer->nbr_token > 1\
			&& lexer->last->prev->operator_type == AND_IF)
	{
		return (AND_IF);
	}
	if (lexer->last->token_type == NEWLINE && lexer->nbr_token > 1\
			&& lexer->last->prev->operator_type == OR_IF)
	{
		return (OR_IF);
	}
	return (0);
}

static t_token	*ft_is_heredoc(t_lexer *lexer)
{
	t_token	*tmp;

	tmp = lexer->first;
	while (tmp)
	{
		if (tmp->operator_type == DLESS && tmp->heredoc == NULL)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int				parser(t_shell *shell, t_lexer *lexer)
{
	int		list_type;
	t_token	*dless;
	int		ret;

	if (!lexer || !lexer->nbr_token || shell->sigint)
		return (EXIT_FAILURE);
	if ((ret = check_syntax(lexer)))
		return (PARSER_ERROR);
	if (lexer->last->quoting)
		ret = ft_read_again_quoting(shell, lexer);
	else if ((dless = ft_is_heredoc(lexer)))
		ret = ft_read_again_heredoc(shell, lexer, dless);
	else if ((list_type = ft_incomplete_list(lexer)))
		ret = ft_read_again_list(shell, lexer, list_type);
	return (ret);
}
