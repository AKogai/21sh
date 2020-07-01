/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_again.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:07:08 by cchieko           #+#    #+#             */
/*   Updated: 2020/06/21 17:11:25 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

static void	ft_create_delimiter(t_token *dless, char **delimiter)
{
	if (*delimiter)
		return ;
	if (ft_strchr(dless->next->str, '"') || ft_strchr(dless->next->str, '\'')\
			|| ft_strchr(dless->next->str, '\\'))
	{
		*delimiter = ft_remove_quotes(dless->next->str);
		*delimiter = ft_charappend(*delimiter, '\n');
	}
	else
		*delimiter = ft_strjoin(dless->next->str, "\n");
}

static void	ft_wrap_heredoc(t_token *dless, char **hdoc_buff, char **delimiter)
{
	if (!*hdoc_buff)
		*hdoc_buff = ft_strdup("");
	dless->heredoc = ft_strdup(*hdoc_buff);
	ft_strdel(hdoc_buff);
	ft_strdel(delimiter);
}

int			ft_read_again_heredoc(t_shell *shell, t_lexer *lexer,
	t_token *dless)
{
	static char	*hdoc_buff;
	static char	*delimiter;
	char		*line;

	ft_create_delimiter(dless, &delimiter);
	read_line(shell, &line, write(1, HEREDOC_PROMPT,
		ft_strlen(HEREDOC_PROMPT)), HEREDOC);
	if (!*line)
	{
		ft_wrap_heredoc(dless, &hdoc_buff, &delimiter);
		free(line);
		return (PARSER_SUCCESS);
	}
	if (ft_strequ(line, delimiter))
		ft_wrap_heredoc(dless, &hdoc_buff, &delimiter);
	else
		ft_strmerge(&hdoc_buff, line);
	free(line);
	return (parser(shell, lexer));
}

int			ft_read_again_list(t_shell *shell, t_lexer *lexer, int list_type)
{
	char *line;

	line = NULL;
	if (list_type == PIPE)
		read_line(shell, &line, write(1, PIPE_PROMPT, ft_strlen(PIPE_PROMPT)),
			LIST);
	if (list_type == AND_IF)
	{
		read_line(shell, &line, write(1, AND_IF_PROMPT,
			ft_strlen(AND_IF_PROMPT)), LIST);
	}
	if (list_type == OR_IF)
		read_line(shell, &line, write(1, OR_IF_PROMPT, ft_strlen(OR_IF_PROMPT)),
			LIST);
	if (!*line)
	{
		free(line);
		if (shell->sigint)
			return (EXIT_FAILURE);
		return (PARSER_ERROR);
	}
	ft_del_lasttoken(lexer);
	tokenizer(&lexer, line);
	free(line);
	return (parser(shell, lexer));
}

int			ft_read_again_quoting(t_shell *shell, t_lexer *lexer)
{
	char *line;
	char *tmp;

	lexer->last->quoting & SQUOTES ? read_line(shell, &tmp,
		write(1, SQUOTES_PROMPT, ft_strlen(SQUOTES_PROMPT)), QUOTES) : 0;
	lexer->last->quoting & DQUOTES ? read_line(shell, &tmp,
		write(1, DQUOTES_PROMPT, ft_strlen(DQUOTES_PROMPT)), QUOTES) : 0;
	lexer->last->quoting & ESCAPE ? read_line(shell, &tmp,
		write(1, ESCAPE_PROMPT, ft_strlen(ESCAPE_PROMPT)), QUOTES) : 0;
	if (!*tmp)
	{
		lexer->last->quoting = 0;
		free(tmp);
		if (shell->sigint)
			return (EXIT_FAILURE);
		return (PARSER_ERROR);
	}
	line = !ft_strequ(lexer->last->str, "\\\n") ?\
		ft_strjoin(lexer->last->str, tmp) : ft_strdup(tmp);
	ft_del_lasttoken(lexer);
	tokenizer(&lexer, line);
	free(line);
	free(tmp);
	return (parser(shell, lexer));
}
