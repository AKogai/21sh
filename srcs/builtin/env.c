/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:07:08 by cchieko           #+#    #+#             */
/*   Updated: 2020/06/21 17:11:25 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

static int	ft_launch_cmd_env(t_shell *shell, char **cmd, int i,
	char **exec_env)
{
	char	**new_cmd;
	char	*path;
	int		ret_cmd;

	ret_cmd = EXIT_SUCCESS;
	new_cmd = NULL;
	while (cmd[i])
		ft_addtotab(new_cmd, cmd[i++]);
	if (!new_cmd)
	{
		if (exec_env)
			ft_puttab(exec_env);
		return (ret_cmd);
	}
	if (is_bltin(new_cmd[0]))
		ret_cmd = ft_launch_builtin(shell, new_cmd);
	else if ((ret_cmd = ft_get_path(shell, new_cmd[0], &path)) == PATH_OK)
	{
		ret_cmd = ft_fork(shell, path, new_cmd);
		free(path);
	}
	ft_freetab(&new_cmd);
	return (ret_cmd);
}

static int	ft_create_exec_env(t_shell *shell, char **cmd, char ***exec_env)
{
	int		i;

	i = 1;
	if (!ft_strequ(cmd[i], "-i"))
		*exec_env = ft_tabdup(shell->env);
	else
		++i;
	while (cmd[i] && ft_strchr(cmd[i], '='))
	{
		if (!*exec_env)
			ft_addtotab(*exec_env, cmd[i++]);
		else
			modify_variable(exec_env, cmd[i++]);
	}
	return (i);
}

int			bltin_env(t_shell *shell, char **cmd)
{
	char	**sauv_env;
	char	**exec_env;
	int		ret_cmd;
	int		i;

	ret_cmd = EXIT_SUCCESS;
	if (!cmd[1] || ft_strequ(cmd[1], CMD_ENV))
		shell->env ? ft_puttab(shell->env) : 0;
	else
	{
		sauv_env = ft_tabdup(shell->env);
		exec_env = NULL;
		i = ft_create_exec_env(shell, cmd, &exec_env);
		ft_freetab(&shell->env);
		shell->env = exec_env;
		ret_cmd = ft_launch_cmd_env(shell, cmd, i, exec_env);
		exec_env ? ft_freetab(&exec_env) : 0;
		shell->env = ft_tabdup(sauv_env);
		ft_freetab(&sauv_env);
	}
	return (ret_cmd);
}

char		*get_env(char **env, char *var)
{
	char	*temp;
	char	*stop;
	int		i;

	if (!env)
		return (NULL);
	i = 0;
	while (*(env + i))
	{
		temp = ft_strsub(*(env + i), 0,\
				ft_strchr(*(env + i), '=') - *(env + i));
		if (ft_strequ(temp, var))
		{
			stop = ft_strchr(*(env + i), '=');
			free(temp);
			return (ft_strsub(*(env + i), stop - *(env + i) + 1,\
						ft_strlen(stop)));
		}
		i++;
		free(temp);
	}
	return (NULL);
}
