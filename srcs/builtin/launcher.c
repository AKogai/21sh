/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:07:08 by cchieko           #+#    #+#             */
/*   Updated: 2020/06/21 17:11:25 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

int		is_bltin(char *cmd)
{
	if (ft_strequ(cmd, CMD_ECHO) || ft_strequ(cmd, CMD_EXIT)\
			|| ft_strequ(cmd, CMD_ENV) || ft_strequ(cmd, CMD_SETENV)\
			|| ft_strequ(cmd, CMD_UNSETENV) || ft_strequ(cmd, CMD_CD)\
			|| ft_strequ(cmd, CMD_HIST))
		return (1);
	return (0);
}

int		ft_launch_builtin(t_shell *shell, char **cmd)
{
	if (ft_strequ(*cmd, CMD_ECHO))
		return (bltin_echo(cmd));
	if (ft_strequ(*cmd, CMD_CD))
		return (bltin_cd(shell, cmd));
	if (ft_strequ(*cmd, CMD_ENV))
		return (bltin_env(shell, cmd));
	if (ft_strequ(*cmd, CMD_SETENV))
		return (bltin_setenv(shell, cmd));
	if (ft_strequ(*cmd, CMD_UNSETENV))
		return (bltin_unsetenv(shell, cmd));
	if (ft_strequ(*cmd, CMD_HIST))
		return (bltin_history(shell, cmd));
	if (ft_strequ(*cmd, CMD_EXIT))
		bltin_exit(shell, cmd);
	return (0);
}
