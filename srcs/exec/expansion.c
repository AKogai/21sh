/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:07:08 by cchieko           #+#    #+#             */
/*   Updated: 2020/06/21 17:11:25 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

static int	ft_tilde_expansion(t_shell *shell, char **str, char *tilde)
{
	char *home;
	char *exp;

	if (!(home = get_env(shell->env, "HOME")))
		return (0);
	exp = ft_memalloc(ft_strlen(*str) + ft_strlen(home));
	ft_memmove(exp, *str, tilde - *str);
	ft_memmove(exp + ft_strlen(exp), home, ft_strlen(home));
	ft_memmove(exp + ft_strlen(exp), tilde + 1, ft_strlen(tilde + 1));
	free(home);
	free(*str);
	*str = exp;
	return (1);
}

static char	*ft_expand_new_str(char *str, char *dollar, char *key, char *value)
{
	char	*exp;
	int		len;

	len = ft_strlen(str);
	if (value)
		len += ft_strlen(value);
	if (key)
		len -= ft_strlen(key);
	exp = ft_memalloc(len);
	ft_memmove(exp, str, dollar - str);
	if (value)
		ft_memmove(exp + ft_strlen(exp), value, ft_strlen(value));
	len = (key ? ft_strlen(key) : 0);
	ft_memmove(exp + ft_strlen(exp), dollar + len + 1,\
			ft_strlen(dollar + len + 1));
	return (exp);
}

void		ft_var_expansion(t_shell *shell, char **str, char *dollar)
{
	char	*key;
	char	*value;
	char	*exp;
	char	*tmp;

	tmp = dollar + 1;
	if (*tmp == '?')
	{
		key = ft_strdup("?");
		value = ft_itoa(shell->return_value);
	}
	else
	{
		key = NULL;
		while (*tmp && (ft_isalnum(*tmp) || *tmp == '_'))
			key = ft_charappend(key, *tmp++);
		value = get_env(shell->env, key);
	}
	exp = ft_expand_new_str(*str, dollar, key, value);
	free(key);
	free(value);
	free(*str);
	*str = exp;
}

int			ft_is_valid_expand(char *dollar)
{
	if (ft_strequ(dollar, "$") || (*(dollar + 1) && *(dollar + 1) != '?' \
				&& *(dollar + 1) != '_' && !ft_isalnum(*(dollar + 1))))
		return (0);
	else
		return (1);
}

void		ft_expand(t_shell *shell, t_token *token)
{
	t_token *tmp;
	char	*tilde;
	char	*dollar;

	tmp = token;
	while (tmp)
	{
		if (tmp->token_type == WORD)
		{
			while ((tilde = ft_strchr(tmp->str, '~'))\
					&& !ft_is_quoted(tmp->str, tilde))
			{
				if (!(ft_tilde_expansion(shell, &tmp->str, tilde)))
					break ;
			}
			while ((dollar = ft_strchr(tmp->str, '$'))\
					&& !ft_is_quoted_no_dquotes(tmp->str, dollar))
			{
				if (!ft_is_valid_expand(dollar))
					break ;
				ft_var_expansion(shell, &tmp->str, dollar);
			}
		}
		tmp = tmp->next;
	}
}
