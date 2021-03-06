/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:07:08 by cchieko           #+#    #+#             */
/*   Updated: 2020/06/21 17:11:25 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

int		ft_is_valid_name(char *str)
{
	while (*str)
	{
		if (ft_isalnum(*str) || *str == '_')
			str++;
		else
			return (0);
	}
	return (1);
}

int		bltin_setenv(t_shell *shell, char **cmd)
{
	char	*var;

	if (!cmd[1])
		ft_puttab(shell->env);
	else if (ft_is_valid_name(cmd[1]))
	{
		if (!cmd[2])
			var = ft_strjoin(cmd[1], "=");
		else if (!cmd[3])
			var = ft_strjoin3(cmd[1], "=", cmd[2]);
		else
		{
			ft_put_cmd_error(CMD_SETENV, STR_TOO_MANY);
			return (EXIT_FAILURE);
		}
		modify_variable(&shell->env, var);
		free(var);
	}
	else
	{
		ft_put_cmd_error(CMD_SETENV, STR_NAME);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	modify_variable(char ***env, char *new_var)
{
	char	*to_free;
	char	*temp_env;
	char	*temp_var;
	int		i;

	temp_var = ft_strsub(new_var, 0, ft_strchr(new_var, '=') - new_var);
	i = 0;
	while (*(*env + i))
	{
		temp_env = ft_strsub(*(*env + i), 0,\
				ft_strchr(*(*env + i), '=') - *(*env + i));
		if (ft_strequ(temp_env, temp_var))
		{
			to_free = *(*env + i);
			*(*env + i) = ft_strdup(new_var);
			free(to_free);
			free(temp_var);
			free(temp_env);
			return ;
		}
		free(temp_env);
		i++;
	}
	free(temp_var);
	*env = ft_addtotab(*env, new_var);
}
