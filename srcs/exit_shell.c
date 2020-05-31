
#include "shell21.h"

void	ft_exit_shell(char *str, int ret)
{
	int i;

	if (str)
		ft_putendl_fd(str, 2);
	g_shell->env ? ft_freetab(&g_shell->env) : 0;
	g_shell->history ? ft_freetab(&g_shell->history) : 0;
	free(g_shell);
	i = 0;
	while (i < 32)
		signal(i++, SIG_DFL);
	exit(ret);
}
