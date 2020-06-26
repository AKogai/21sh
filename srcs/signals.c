
#include "shell21.h"

static void	backup_str(t_shell *shell, char **save_line, char **save_tmp)
{
	*save_line = NULL;
	*save_tmp = NULL;
	if (shell->input.line)
	{
		*save_line = ft_strdup(shell->input.line);
		free(shell->input.line);
	}
	if (shell->input.tmp)
	{
		*save_tmp = ft_strdup(shell->input.tmp);
		free(shell->input.tmp);
	}
}

void	*sigwinch_handler(t_shell *shell)
{
	char *save_line;
	char *save_tmp;
	int save_prompt;
	int save_index;

	backup_str(shell, &save_line, &save_tmp);
	save_index = shell->input.y * (shell->input.width + 1)\
 + shell->input.x - shell->input.prompt;
	save_prompt = shell->input.origin_prompt;
	init_input_struct(&shell->input, save_prompt);
	if (save_line)
	{
		ft_memmove(shell->input.line, save_line, ft_strlen(save_line));
		free(save_line);
	}
	if (save_tmp)
	{
		ft_memmove(shell->input.tmp, save_tmp, ft_strlen(save_tmp));
		free(save_tmp);
	}
	shell->input.len = ft_strlen(shell->input.line);
	shell->input.x = (save_index + shell->input.prompt)\
		% (shell->input.width + 1);
	shell->input.y = (save_index + shell->input.prompt)\
		/ (shell->input.width + 1);
	return ((void *)0);
}

static void sigint_handler(int sig)
{
	write(1, "\n", 1);
	ft_display_prompt();
	(void)sig;
}

static void	void_handler(int sig)
{
	(void)sig;
}

void		signal_handler(t_shell *shell, int exec)
{
//	signal(SIGTERM, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGWINCH, sigwinch_handler(shell));
	if (!exec)
	{
		shell->sigint = 1;
		shell->return_value = EXIT_FAILURE;
		signal(SIGINT, sigint_handler);
	}
	else
		signal(SIGINT, void_handler);
}
