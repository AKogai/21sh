//
// Created by A Kosimovsky on 28.05.20.
//

#include "shell.h"

static int 		name_exists(t_sh *shell, char *name)
{
	int 		len;
	char 		**tmp;

	tmp = shell->env;
	len = ft_strlen(name);
	while (*tmp)
	{
		if (ft_strnequ(*tmp, name, len))
			if ((*tmp)[len] == '=')
				return (1);
		tmp++;
	}
	return (0);
}

static int 		append_name(t_sh *shell, char *name)
{
	int 		i;
	int 		len;
	char 		**new;

	i = -1;
	len = 0;
	while (shell->env[len])
		len++;
	if (!(new = (char**)ft_memalloc(sizeof(char*) * (len + 2))))
	{
		print_error(ERR_MALLOC_FAIL);
		ft_putchar_fd('\n', 2);
		return (0);
	}
	while (shell->env[++i] && i < len)
		new[i] = ft_strdup(shell->env[i]);
	ft_free_array(shell->env);
	new[i] = ft_strjoin(name, "=");
	new[++i] = NULL;
	shell->env = new;
	return (1);
}

static void 	append_value(t_sh *shell, char *name, char *value)
{
	int 		i;
	int 		len;
	char 		*tmp;

	i = -1;
	len = ft_strlen(name);
	while (shell->env[++i])
		if (ft_strnequ(shell->env[i], name, len) && shell->env[i][len] == '=')
		{
			tmp = shell->env[i];
			shell->env[i] = ft_strjoin(name, "=");
			free(tmp);
			tmp = shell->env[i];
			if (value)
			{
				shell->env[i] = ft_strjoin(shell->env[i], value);
				free(tmp);
			}
			return ;
		}
}

int 			bltn_setenv(t_sh *shell)
{
	char 		**tmp;

	if (shell->argc == 2)
	{
		tmp = ft_strsplit(shell->argv[1], '=');
		if (!name_exists(shell, tmp[0]))
		{
			if (!(append_name(shell, tmp[0])))
				return (-1);
		}
		append_value(shell,tmp[0], tmp[1]);
		free(tmp[0]);
		free(tmp[1]);
		free(tmp);
	}
	else
	{
		ft_putendl("minishel: setenv: invalid arguments");
		return (-1);
	}
	return (1);
}