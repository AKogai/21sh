//
// Created by A Kosimovsky on 20.05.20.
//
#include "shell.h"

static char *err_str_return(t_error error)
{
	static struct s_errors errtab[] = {
			{ERR_ACCESS, "Permission denied!"},
			{ERR_FORK, "fork() call error!"},
			{ERR_MALLOC_FAIL, "Memory allocation failed!"},
			{ERR_CMD_NTFND, "Command not found!"},
			{ERR_ENV, "Environment initialization failed!"},
			{ERR_NO_ENV, "There is no such an environment variable."},
			{ERR_READ, "Error occurred while read from STDIN"},
			{ERR_CMD_MNPL, "Local error! 'cmd' manipulation failed!"},
			{ERR_PATH, "No such file or directory!"},
			{ERR_EXECVE, "execve() call error!"},
			{ERR_WAIT, "wait() call error!"},
			{ERR_GET_CWD, "getcwd() call error!"},
			{ERR_CD, "cd: no such file or directory: "},
			{ERR_ENV_OVERWRITE, " : env overwriting failed!"},
			{ERR_PATHCONF, "pathconf() call error!"},
			{ERR_SETENV, "setenv() call error!"}
	};
	return (errtab[error].error_str);
}

char    *print_error(t_error error)
{
	ft_putstr_fd(err_str_return(error), 2);
	return (err_str_return(error));
}