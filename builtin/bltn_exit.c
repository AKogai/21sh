//
// Created by A Kosimovsky on 26.05.20.
//
#include "shell.h"

void    bltn_exit(t_sh *shell)
{
	ft_strdel(shell->env);
	ft_strdel(shell->argv);
	free(shell->path);
	free(shell->string);
	exit(EXIT_SUCCESS);
}