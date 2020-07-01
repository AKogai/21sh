/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:07:08 by cchieko           #+#    #+#             */
/*   Updated: 2020/06/21 17:11:25 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

char	**ft_cmd_into_tab(t_ast *ast)
{
	char	**cmd;
	t_token	*tmp;

	cmd = NULL;
	tmp = ast->token;
	while (tmp)
	{
		if (tmp->token_type == IO_NUMBER)
			tmp = tmp->next;
		else if (tmp->token_type == REDIRECT)
			tmp = tmp->next->next;
		else
		{
			cmd = ft_addtotab(cmd, tmp->str);
			tmp = tmp->next;
		}
	}
	return (cmd);
}

int		ft_fork(t_shell *shell, char *path, char **cmd)
{
	pid_t	pid;
	int		status;

	if ((pid = fork()) == -1)
		ft_exit(STR_FORK_ERROR, 1);
	if (pid == 0)
	{
		if ((status = execve(path, cmd, shell->env)) == -1)
			ft_exit(STR_EXECVE_ERROR, 1);
	}
	else
		waitpid(pid, &status, 0);
	return (ft_exit_status(status));
}

int		ft_init_launch(t_shell *shell, int save[3], t_ast *ast)
{
	ft_save_std_fd(save);
	ft_expand(shell, ast->token);
	ft_remove_quoting(shell, ast->token);
	if (ft_init_redirection(ast) != REDIR_OK)
	{
		ft_restore_std_fd(ast, save);
		return (REDIR_ERROR);
	}
	return (EXIT_SUCCESS);
}

int		ft_launch_simple_cmd(t_shell *shell, t_ast *ast)
{
	char	*path;
	char	**cmd;
	int		ret_cmd;
	int		save[3];

	if ((ret_cmd = ft_init_launch(shell, save, ast)) == REDIR_ERROR)
		return (ret_cmd);
	if ((cmd = ft_cmd_into_tab(ast)))
	{
		if (is_bltin(cmd[0]))
			ret_cmd = ft_launch_builtin(shell, cmd);
		else if ((ret_cmd = ft_get_path(shell, cmd[0], &path)) == PATH_OK)
		{
			ret_cmd = ft_fork(shell, path, cmd);
			free(path);
		}
		ft_freetab(&cmd);
	}
	ft_restore_std_fd(ast, save);
	return (ret_cmd);
}
