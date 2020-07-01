/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:07:08 by cchieko           #+#    #+#             */
/*   Updated: 2020/06/21 17:11:25 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

void		ft_history_back(t_shell *shell)
{
	if (!shell->history)
		tputs(tgetstr("bl", NULL), 1, &ft_intputchar);
	else
	{
		if (shell->h_ind > 0)
		{
			ft_clear_screen(&shell->input);
			ft_insertchar(shell->history[shell->h_ind - 1], &shell->input);
			shell->h_ind--;
		}
		else
			tputs(tgetstr("bl", NULL), 1, &ft_intputchar);
	}
}

void		ft_history_forth(t_shell *shell)
{
	if (!shell->history)
		tputs(tgetstr("bl", NULL), 1, &ft_intputchar);
	else
	{
		if (shell->h_ind < ft_tablen(shell->history) - 1)
		{
			ft_clear_screen(&shell->input);
			shell->h_ind++;
			ft_insertchar(shell->history[shell->h_ind], &shell->input);
		}
		else
		{
			ft_clear_screen(&shell->input);
			tputs(tgetstr("bl", NULL), 1, &ft_intputchar);
		}
	}
}

static char	*ft_search_in_history(t_shell *shell, char *line)
{
	int		len;

	if (!line || !*line)
		return (NULL);
	if (!shell->history)
		return (NULL);
	len = ft_tablen(shell->history);
	while (len--)
	{
		if (ft_strstr(shell->history[len], line))
			return (ft_strdup(shell->history[len]));
	}
	return (NULL);
}

static void	ft_close_termcaps(t_shell *shell)
{
	shell->return_value = EXIT_SUCCESS;
	free(shell->input.line);
	free(shell->input.tmp);
	init_canonic_term();
	write(1, "\n", 1);
}

void		ft_history_search(t_shell *shell)
{
	char	*line;
	char	*little;
	char	*tmp;

	ft_clear_screen(&shell->input);
	ft_close_termcaps(shell);
	read_line(shell, &line, write(1, HISTO_PROMPT, ft_strlen(HISTO_PROMPT)), 3);
	init_raw_term(shell);
	tmp = NULL;
	if (!shell->sigint)
	{
		little = ft_strsub(line, 0, ft_strlen(line) - 1);
		if (!(tmp = ft_search_in_history(shell, little)))
		{
			ft_putendl("No match found...");
			tmp = ft_strdup(little);
		}
		free(little);
	}
	init_input_struct(&shell->input, ft_display_prompt());
	if (tmp)
		ft_insertchar(tmp, &shell->input);
	free(tmp);
	free(line);
}
