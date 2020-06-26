/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:07:08 by cchieko           #+#    #+#             */
/*   Updated: 2020/06/21 17:11:25 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

static void	ft_put_cd_error(char *dir, int err)
{
	char *tmp;

	tmp = ft_strjoin("cd: ", dir);
	if (err == EACCES)
		ft_put_cmd_error(tmp, STR_PERM_DENIED);
	else if (err == ENOENT)
		ft_put_cmd_error(tmp, STR_NO_FILE);
	else if (err == ENOTDIR)
		ft_put_cmd_error(tmp, STR_NOT_DIR);
	free(tmp);
}

static void	ft_modify_env(t_shell *shell, char *key, char *name)
{
	char	*var;

	var = ft_strjoin(key, name);
	modify_variable(&shell->env, var);
	free(var);
}

static int	ft_move_to_dest(t_shell *shell, char *dest)
{
	char	*old_pwd;
	char	*pwd;

	errno = 0;
	old_pwd = getcwd(NULL, 0);
	if ((chdir(dest)) != -1)
	{
		pwd = getcwd(NULL, 0);
		pwd ? ft_modify_env(shell, "PWD=", pwd) : 0;
		old_pwd ? ft_modify_env(shell, "OLDPWD=", old_pwd) : 0;
		free(old_pwd);
		free(pwd);
		free(dest);
		return (EXIT_SUCCESS);
	}
	else
	{
		ft_put_cd_error(dest, errno);
		free(old_pwd);
		free(dest);
		return (EXIT_FAILURE);
	}
}

int			bltin_cd(t_shell *shell, char **cmd)
{
	char	*dest;

	if (!cmd[1])
	{
		if (!(dest = get_env(shell->env, "HOME")))
		{
			ft_put_cmd_error(CMD_CD, STR_HOME);
			return (EXIT_FAILURE);
		}
	}
	else if (ft_strequ(cmd[1], "-"))
	{
		if (!(dest = get_env(shell->env, "OLDPWD")))
		{
			ft_put_cmd_error(CMD_CD, STR_OLDPWD);
			return (EXIT_FAILURE);
		}
		ft_putendl(dest);
	}
	else
		dest = ft_strdup(cmd[1]);
	return (ft_move_to_dest(shell, dest));
}
