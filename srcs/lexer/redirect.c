/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:07:08 by cchieko           #+#    #+#             */
/*   Updated: 2020/06/21 17:11:25 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

void		ft_get_io_number(t_lexer *lexer, char *line)
{
	if (lexer->last && ft_isnumber(lexer->last->str) &&\
			ft_strncmp(line - ft_strlen(lexer->last->str),\
				lexer->last->str, ft_strlen(lexer->last->str)) == 0)
	{
		lexer->last->token_type = IO_NUMBER;
	}
}

static char	*ft_goto_dash(char *line)
{
	while (*line && ft_isspace(*line))
		line++;
	if (*line == '-')
		return (line);
	return (NULL);
}

int			ft_aggreg_fetch_dash(t_lexer *lexer, char *line)
{
	t_token	*token;
	char	*dash;

	if (!(dash = ft_goto_dash(line)))
		return (0);
	if (!ft_isspace(*(dash + 1)))
	{
		token = ft_newtoken("-", WORD, NONE);
		ft_addtoken(lexer, token);
		return (dash - line + 1);
	}
	return (0);
}
