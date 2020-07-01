/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:07:08 by cchieko           #+#    #+#             */
/*   Updated: 2020/06/21 17:11:25 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

static int	ft_remove_escape_withindquotes(char **str)
{
	int escape;

	escape = 0;
	if (**str == '\\')
	{
		if (*(*str + 1) && (*(*str + 1) == '"' || *(*str + 1) == '$'\
					|| *(*str + 1) == '\\' || *(*str + 1) == '\n'))
			(*str)++;
		if (**str == '\n')
			(*str)++;
		else
			escape = ESCAPE;
	}
	return (escape);
}

static int	ft_remove_escape(char **str)
{
	int escape;

	escape = 0;
	if (**str == '\\')
	{
		(*str)++;
		if (**str == '\n')
			(*str)++;
		else
			escape = ESCAPE;
	}
	return (escape);
}

static char	*ft_remove_squotes(char *new, char **str)
{
	(*str)++;
	while (**str && **str != '\'')
	{
		new = ft_charappend(new, **str);
		(*str)++;
	}
	(*str)++;
	return (new);
}

static char	*ft_remove_dquotes(char *new, char **str)
{
	int	escape;

	(*str)++;
	while (**str && **str != '"')
	{
		escape = ft_remove_escape_withindquotes(str);
		if (((escape && **str == '\\') || **str != '\\')\
			&& ((escape && **str == '"') || **str != '"'))
		{
			new = ft_charappend(new, **str);
			(*str)++;
		}
	}
	(*str)++;
	return (new);
}

char		*ft_remove_quotes(char *str)
{
	char	*new;
	int		escape;

	new = NULL;
	while (*str)
	{
		escape = ft_remove_escape(&str);
		if (!escape && *str == '"')
			new = ft_remove_dquotes(new, &str);
		else if (!escape && *str == '\'')
			new = ft_remove_squotes(new, &str);
		else
		{
			if ((escape && *str == '\\') || *str != '\\')
			{
				new = ft_charappend(new, *str);
				str++;
			}
		}
	}
	if (!new)
		new = ft_strdup("");
	return (new);
}
