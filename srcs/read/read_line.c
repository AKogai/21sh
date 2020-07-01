/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:07:08 by cchieko           #+#    #+#             */
/*   Updated: 2020/06/21 17:11:25 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

void		accept_line(t_input *input)
{
	ft_clear(input);
	input->line = ft_strcat(input->line, "\n");
	ft_putstr(input->line);
}

static void	ft_save_in_history(t_shell *shell, char *line)
{
	char *tmp;

	tmp = ft_strsub(line, 0, ft_strlen(line) - 1);
	shell->history = ft_addtotab(shell->history, tmp);
	free(tmp);
	shell->h_ind = ft_tablen(shell->history);
}

void		read_line(t_shell *shell, char **line, int len_prompt, int mode)
{
	char	buff[BUFFSIZE];

	init_raw_term(shell);
	init_input_struct(&shell->input, len_prompt);
	while (1)
	{
		ft_bzero(buff, BUFFSIZE);
		read(0, buff, BUFFSIZE - 1);
		if (shell->sigint || interpret(buff, shell, mode))
		{
			*line = ft_strdup(shell->input.line);
			break ;
		}
	}
	if (!shell->sigint && (mode == DEFAULT || mode == QUOTES || mode == LIST)\
			&& *line && !ft_strequ(*line, "\n") && !ft_strequ(*line, ""))
		ft_save_in_history(shell, *line);
	init_canonic_term();
	free(shell->input.line);
	free(shell->input.tmp);
}
