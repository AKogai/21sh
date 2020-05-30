//
// Created by A Kosimovsky on 28.05.20.
//

#include "shell.h"

static int 		pop_index(int index, t_sh *shell)
{
	int 		i;
	int 		k;
	int 		len;
	char 		**tmp;

	i = -1;
	k = 0;
	len = 0;
	while (shell->env[len])
		len++;
	if (!(tmp = (char**)ft_memalloc(sizeof(char*) * len)))
	{
		print_error(ERR_MALLOC_FAIL);
		ft_putchar_fd('\n', 2);
		return (0);
	}
	while (shell->env[++i] && i < len)
		if (i != index)
			tmp[k++] = ft_strdup(shell->env[i]);
	ft_free_array(shell->env);
	tmp[k] = NULL;
	shell->env = tmp;
	return (1);
}

int 			bltn_unsetenv(t_sh *shell)
{
	int 		i;
	int 		len;

	if (shell->argc == 2)
	{
		i = -1;
		len = ft_strlen(shell->argv[1]);
		while (shell->env[++i])
			if (ft_strnequ(shell->env[i], shell->argv[1], len) && shell->env[i][len] == '=')
			{
				pop_index(i, shell);
				break ;
			}
	}
	else
	{
		ft_putendl("minishell: unsetenv: invalid arguments");
		return (0);
	}
	return (1);
}
