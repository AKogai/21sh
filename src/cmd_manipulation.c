//
// Created by A Kosimovsky on 23.05.20.
//

#include "shell.h"

static int 		array_length(char **ptr)
{
	int length;

	length = 0;
	while (ptr[length] != NULL)
		length++;
	return (length);
}

int     split_cmd(t_sh *shell)
{
	char    *tmp;
	uint8_t status;

	status = 0;
	tmp = ft_strtrim(shell->string);
	if (tmp[0] != '\0')
	{
		shell->argv = ft_strsplit_wd(tmp);
		if (shell->argv != NULL)
		{
			shell->argc = array_length(shell->argv);
		} else
		{
			print_error(ERR_MALLOC_FAIL);
			return (status = EXIT_FAILURE);
		}
	} else
	{
		print_error(ERR_CMD_NTFND);
		return (status = EXIT_FAILURE);
	}
	free(tmp);
//	if (!status)
//		free(shell->input);
	return (status);
}

int			free_cmd(t_sh *shell)
{
	free(shell->string);
	shell->string = NULL;
	ft_strdel(shell->argv);
	shell->argv = NULL;
	ft_strdel(shell->env);
	shell->env = NULL;
	free(shell->path);
	shell->path = NULL;
	shell->argc = 0;
	return (0);
}