/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:07:08 by cchieko           #+#    #+#             */
/*   Updated: 2020/06/21 17:11:25 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

static	void	ft_put_syntax_error(char *token)
{
	ft_putstr_fd(SHELL, 2);
	ft_putstr_fd(SYNTAX_ERR, 2);
	ft_putstr_fd(token, 2);
	ft_putendl_fd(END_ERR, 2);
}

static	int		ft_token_not_handled(t_token *token)
{
	if (token->operator_type == DSEMI || token->operator_type == AND\
			|| token->operator_type == CLOBBER\
			|| token->operator_type == LESS_GREAT\
			|| token->operator_type == DLESS_DASH)
	{
		ft_put_syntax_error(token->str);
		return (1);
	}
	return (0);
}

static	int		ft_check_operator(t_token *token)
{
	if ((token->token_type == OPERATOR && !token->prev) ||\
			(token->token_type == OPERATOR && token->prev->token_type != WORD))
	{
		ft_put_syntax_error(token->str);
		return (1);
	}
	if ((token->token_type == REDIRECT && token->next->token_type != WORD))
	{
		ft_put_syntax_error(token->next->str);
		return (1);
	}
	return (0);
}

int				check_syntax(t_lexer *lexer)
{
	t_token *tmp;

	tmp = lexer->first;
	while (tmp)
	{
		if (ft_token_not_handled(tmp) || ft_check_operator(tmp))
			return (PARSER_ERROR);
		tmp = tmp->next;
	}
	return (PARSER_SUCCESS);
}
