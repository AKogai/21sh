
#include "shell.h"

void		ft_accept_line(t_input *input)
{
	ft_clear(input);
	input->line = ft_strcat(input->line, "\n");
	ft_putstr(input->line);
}

static void	ft_save_in_history(char *line)
{
	char *tmp;

	tmp = ft_strsub(line, 0, ft_strlen(line) - 1);
	g_sh->history = ft_addtotab(g_sh->history, tmp);
	free(tmp);
	g_sh->histo_index = ft_tablen(g_sh->history);
}

void		ft_read_line(char **line, int len_prompt, int mode)
{
	char	buff[BUFFSIZE];

	ft_raw_term();
	ft_init_input_struct(&g_sh->input, len_prompt);
	while (1)
	{
		ft_bzero(buff, BUFFSIZE);
		read(0, buff, BUFFSIZE - 1);
		if (g_sh->sigint || ft_interpret(buff, &g_sh->input, mode))
		{
			*line = ft_strdup(g_sh->input.line);
			break ;
		}
	}
	if (!g_sh->sigint && (mode == DEFAULT || mode == QUOTES || mode == LIST)\
 && *line && !ft_strequ(*line, "\n") && !ft_strequ(*line, ""))
		ft_save_in_history(*line);
	ft_canonic_term();
	free(g_sh->input.line);
	free(g_sh->input.tmp);
}
