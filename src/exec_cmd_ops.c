//
// Created by A Kosimovsky on 24.05.20.
//

#include "shell.h"

static int	check_access(char *path)
{
	if (access(path, F_OK) != 0)
	{
		ft_putstr_fd(path, 2);
		ft_putchar_fd(' ', 2);
		print_error(ERR_PATH);
		return (ERR_PATH);
	}
	if (access(path, X_OK) != 0)
	{
		ft_putstr_fd(path, 2);
		ft_putchar_fd(' ', 2);
		print_error(ERR_ACCESS);
		return (ERR_ACCESS);
	}
	return (0);
}

static int	execute_cmd(t_sh *cmd)
{
	int		stat_loc;
	int		status;
	pid_t	pid;

	stat_loc = 0;
	status = NO;
	if ((check_access(cmd->path)) == 0)
	{
		if ((pid = fork()) < 0)
		{
			print_error(ERR_FORK);
			return (status = EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if ((execve(cmd->path, cmd->argv, cmd->env)) < 0) {
				print_error(ERR_EXECVE);
				exit(ERR_EXECVE);
			}
		}
		if ((waitpid(pid, &stat_loc, 0)) < 0)
		{
			print_error(ERR_WAIT);
			exit(EXIT_FAILURE);
		}
		status = WIFEXITED(stat_loc);
	}
	return (status);
}


static int	execute_bltn(t_sh *shell)
{
	int	status;

	status = -1;
	if (ft_strcmp(shell->argv[0], "cd") == 0)
		status = bltn_cd(shell);
	else if (ft_strcmp(shell->argv[0], "echo") == 0)
		status = bltn_echo(shell);
	else if (ft_strcmp(shell->argv[0], "exit") == 0)
		bltn_exit(shell);
	else if (ft_strcmp(shell->argv[0], "env") == 0)
		status = bltn_env(shell);
	else if (ft_strcmp(shell->argv[0], "setenv") == 0)
		status = bltn_setenv(shell);
	else if (ft_strcmp(shell->argv[0], "unsetenv") == 0)
		status = bltn_unsetenv(shell);
	return (status);
}

int			exec_cmd_ops(t_sh *shell)
{
	int status;

	status = expand_it(shell->env, shell->argv);
	if (status == 0)
	{
		status = find_binary_in_path(shell);
		if (status == 0)
		{
			if (shell->path[0] != '\0')
				status = execute_cmd(shell);
			else
				status = execute_bltn(shell);
		}
		else
		{
			ft_putendl_fd(shell->argv[0], 2);
			print_error(ERR_CMD_NTFND);
			ft_putchar_fd('\n', 2);
			status = ERR_CMD_NTFND;
		}
	}
	//free_cmd(shell);
	return (status);
}