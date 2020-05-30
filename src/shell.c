//
// Created by kosimovsky on 28.04.2020.
//

#include "shell.h"
#include <stdio.h>

static int loop()
{
	int     	status;
	char		*line;
	extern char **environ;

	g_sh = init_sh(environ);
	status = YES;
	ft_catch_signals(0);
	while (status)
	{
		ft_read_line(&line, ft_put_prompt_sigint(), DEFAULT);
		if (!(g_sh->string = line))
		{
			status = NO;
			free(g_sh->string);
			print_error(ERR_READ);
			ft_putchar_fd('\n', 2);
			return (ERR_READ);
		}
		if (g_sh->string[0] != '\0')
		{
			if (!(status = split_cmd(g_sh)))
				status = exec_cmd_ops(g_sh);
		} else
			free(g_sh->string);
		//ft_strdel(&line);
	}
	return (status);
}

int main(void)
{
	loop();
	return (EXIT_SUCCESS);
}