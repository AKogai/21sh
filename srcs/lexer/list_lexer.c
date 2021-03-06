/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:07:08 by cchieko           #+#    #+#             */
/*   Updated: 2020/06/21 17:11:25 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

t_token	*ft_newtoken(char *str, int token, int operator)
{
	t_token	*elem;

	elem = ft_memalloc(sizeof(t_token));
	elem->str = ft_strdup(str);
	elem->token_type = token;
	elem->operator_type = operator;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

void	ft_addtoken(t_lexer *lexer, t_token *token)
{
	t_token	*temp;

	lexer->nbr_token++;
	if (lexer->first == NULL)
	{
		lexer->first = token;
		lexer->last = token;
	}
	else
	{
		temp = lexer->first;
		while (temp->next)
			temp = temp->next;
		temp->next = token;
		token->prev = temp;
		lexer->last = token;
	}
}

void	ft_del_lasttoken(t_lexer *lexer)
{
	t_token *suppr;

	suppr = lexer->last;
	if (lexer->last != lexer->first)
	{
		lexer->last = suppr->prev;
		suppr->prev->next = NULL;
	}
	else
	{
		lexer->first = NULL;
		lexer->last = NULL;
	}
	lexer->nbr_token--;
	free(suppr->str);
	if (suppr->heredoc)
		free(suppr->heredoc);
	free(suppr);
}

void	ft_dellexer(t_lexer **lexer)
{
	t_token	*temp;
	t_token	*prev;

	if (!*lexer || !(*lexer)->first)
		return ;
	temp = (*lexer)->first;
	while (temp)
	{
		free(temp->str);
		if (temp->heredoc)
			free(temp->heredoc);
		prev = temp;
		temp = temp->next;
		free(prev);
	}
	free(*lexer);
	*lexer = NULL;
}

void	ft_deltokens(t_token **token)
{
	t_token	*temp;
	t_token	*prev;

	if (!*token)
		return ;
	temp = *token;
	while (temp)
	{
		free(temp->str);
		if (temp->heredoc)
			free(temp->heredoc);
		prev = temp;
		temp = temp->next;
		free(prev);
	}
	*token = NULL;
}
