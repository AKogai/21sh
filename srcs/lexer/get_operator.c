/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_operator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:07:08 by cchieko           #+#    #+#             */
/*   Updated: 2020/06/21 17:11:25 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

int			ft_part_operator(char c)
{
	return (c == ';' || c == '|' || c == '&' || c == '<' || c == '>' ? 1 : 0);
}

int			ft_create_operator_token(t_lexer *lexer, char *line,\
		char *operator, int i)
{
	int			len;
	t_token		*token;

	if (i < 6)
	{
		token = ft_newtoken(operator, OPERATOR, i + 1);
		ft_addtoken(lexer, token);
	}
	else
	{
		ft_get_io_number(lexer, line);
		token = ft_newtoken(operator, REDIRECT, i + 1);
		ft_addtoken(lexer, token);
		if (ft_strequ(operator, ">&") || ft_strequ(operator, "<&"))
		{
			if ((len = ft_aggreg_fetch_dash(lexer, line + ft_strlen(operator))))
				return (len + ft_strlen(operator));
		}
	}
	return (ft_strlen(operator));
}

int			ft_get_operator(t_lexer *lexer, char *line)
{
	static char	operator[15][5] = {";;", ";", "&&", "&", "||", "|", "<<-",\
		"<<", "<&", "<>", "<", ">>", ">&", ">|", ">"};
	int			i;

	i = 0;
	while (operator[i])
	{
		if (ft_strncmp(line, operator[i], ft_strlen(operator[i])) == 0)
			return (ft_create_operator_token(lexer, line, operator[i], i));
		++i;
	}
	return (0);
}
