
#include "shell21.h"

static void ft_sigint_handler(int sig)
{
	write(1, "\n", 1);
	ft_display_prompt();
	(void)sig;
}

static void	ft_void_handler(int sig)
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
	if (!exec)
	{
		shell->sigint = 1;
		shell->return_value = EXIT_FAILURE;
		signal(SIGINT, ft_sigint_handler);
	}
	else
		signal(SIGINT, ft_void_handler);
}
