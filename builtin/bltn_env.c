//
// Created by A Kosimovsky on 26.05.20.
//
#include "shell.h"

int    bltn_env(t_sh *shell)
{
	t_sh    *tmp;
	int     i;

	tmp = shell;
	i = 0;
	while (tmp->env[i] != NULL)
	{
		ft_putendl(tmp->env[i]);
		i++;
	}
	return (1);
}

