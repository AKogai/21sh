
#include "shell.h"

static void	ft_sigint_handler(int sig)
{
	write(1, "\n", 1);
	(void)sig;
	g_sh->ret_cmd = EXIT_FAILURE;
	g_sh->sigint = 1;
}

static void	ft_void_handler(int sig)
{
	(void)sig;
}

static void	ft_save_str(char **save_line, char **save_tmp)
{
	*save_line = NULL;
	*save_tmp = NULL;
	if (g_sh->input.line)
		*save_line = ft_strdup(g_sh->input.line);
	free(g_sh->input.line);
	if (g_sh->input.tmp)
		*save_tmp = ft_strdup(g_sh->input.tmp);
	free(g_sh->input.tmp);
}

static void	ft_sigwinch_handler(int sig)
{
	char	*save_line;
	char	*save_tmp;
	int		save_prompt;
	int		save_index;

	(void)sig;
	ft_save_str(&save_line, &save_tmp);
	save_index = g_sh->input.y * (g_sh->input.width + 1)\
 + g_sh->input.x - g_sh->input.prompt;
	save_prompt = g_sh->input.origin_prompt;
	ft_init_input_struct(&g_sh->input, save_prompt);
	if (save_line)
		ft_memmove(g_sh->input.line, save_line, ft_strlen(save_line));
	free(save_line);
	if (save_tmp)
		ft_memmove(g_sh->input.tmp, save_tmp, ft_strlen(save_tmp));
	free(save_tmp);
	g_sh->input.len = ft_strlen(g_sh->input.line);
	g_sh->input.x = (save_index + g_sh->input.prompt)\
 % (g_sh->input.width + 1);
	g_sh->input.y = (save_index + g_sh->input.prompt)\
 / (g_sh->input.width + 1);
}

void		ft_catch_signals(int exec)
{
	signal(SIGTERM, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGWINCH, ft_sigwinch_handler);
	if (!exec)
		signal(SIGINT, ft_sigint_handler);
	else
		signal(SIGINT, ft_void_handler);
}
