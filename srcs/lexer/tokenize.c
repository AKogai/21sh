/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:07:08 by cchieko           #+#    #+#             */
/*   Updated: 2020/06/21 17:11:25 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

int		ft_get_newline(t_lexer *lexer)
{
	t_token	*token;

	token = ft_newtoken("<newline>", NEWLINE, NONE);
	ft_addtoken(lexer, token);
	return (1);
}

void	tokenizer(t_lexer **lexer, char *line)
{
	if (!line || !*line)
		return ;
	if (!*lexer)
		*lexer = ft_memalloc(sizeof(t_lexer));
	while (*line)
	{
		if (ft_part_operator(*line))
			line = line + ft_get_operator(*lexer, line);
		else if (ft_part_word(*line))
			line = line + ft_get_word(*lexer, line);
		else if (*line == '\n' && !*(line + 1))
			line = line + ft_get_newline(*lexer);
		else
			line++;
	}
}
