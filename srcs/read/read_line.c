
#include "shell21.h"

void		ft_accept_line(t_input *input)
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

void		ft_read_line(t_shell *shell, char **line, int len_prompt, int mode)
{
	char	buff[BUFFSIZE];

	ft_raw_term(shell);
	ft_init_input_struct(&shell->input, len_prompt);
	while (1)
	{
		ft_bzero(buff, BUFFSIZE);
		read(0, buff, BUFFSIZE - 1);
		if (shell->sigint || ft_interpret(buff, shell, mode))
		{
			*line = ft_strdup(shell->input.line);
			break ;
		}
	}
	if (!shell->sigint && (mode == DEFAULT || mode == QUOTES || mode == LIST)\
			&& *line && !ft_strequ(*line, "\n") && !ft_strequ(*line, ""))
		ft_save_in_history(shell, *line);
	ft_canonic_term();
	free(shell->input.line);
	free(shell->input.tmp);
}
