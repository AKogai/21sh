//
// Created by A Kosimovsky on 28.05.20.
//

#include "shell.h"

int			bltn_echo(t_sh *shell)
{
	int 	i;
	int 	n;
	int     status;

	status = YES;
	if (shell->argc == 1)
	{
		ft_putchar('\n');
		return (status);
	}
	i = (ft_strequ(shell->argv[1], "-n") ? 1 : 0);
	n = i;
	while (++i < shell->argc)
	{
		ft_putstr(shell->argv[i]);
		i < shell->argc - 1 ? ft_putchar(' ') : 0;
	}
	ft_putstr(n ? "" : "\n");
	return (status);
}
