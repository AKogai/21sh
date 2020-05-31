
#include "shell21.h"

void	ft_builtin_exit(char **cmd)
{
	if (!cmd[1])
		ft_exit_shell(CMD_EXIT, g_shell->ret_cmd);
	else if (!ft_isnumber(cmd[1]))
	{
		ft_put_cmd_error(CMD_EXIT, STR_NUM);
		exit(EXIT_ERROR);
	}
	else if (cmd[2])
		ft_put_cmd_error(CMD_EXIT, STR_TOO_MANY);
	else
		ft_exit_shell(CMD_EXIT, ft_atoi(cmd[1]));
}
