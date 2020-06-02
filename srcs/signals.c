
#include "shell21.h"

static void	ft_sigint_handler(int sig)
{
	write(1, "\n", 1);
	(void)sig;
	g_shell->return_value = EXIT_FAILURE;
	g_shell->sigint = 1;
}

static void	ft_void_handler(int sig)
{
	(void)sig;
}

void		signal_handler(int exec)
{
	signal(SIGTERM, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	if (!exec)
		signal(SIGINT, ft_sigint_handler);
	else
		signal(SIGINT, ft_void_handler);
}
