
#include "shell21.h"

void *ft_sigint_handler(int sig)
{
	write(1, "\n", 1);
//	shell->return_value = EXIT_FAILURE;
	sig ^= 0;
	return ((void *)1);
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
		signal(SIGINT, ft_sigint_handler(shell->sigint));
	else
		signal(SIGINT, ft_void_handler);
}
