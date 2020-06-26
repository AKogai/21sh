/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:07:08 by cchieko           #+#    #+#             */
/*   Updated: 2020/06/21 17:11:25 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

void	bltin_exit(t_shell *shell, char **cmd)
{
	if (!cmd[1])
		exit_shell(shell, CMD_EXIT, shell->return_value);
	else if (!ft_isnumber(cmd[1]))
	{
		ft_put_cmd_error(CMD_EXIT, STR_NUM);
		exit(EXIT_ERROR);
	}
	else if (cmd[2])
		ft_put_cmd_error(CMD_EXIT, STR_TOO_MANY);
	else
		exit_shell(shell, CMD_EXIT, ft_atoi(cmd[1]));
}
