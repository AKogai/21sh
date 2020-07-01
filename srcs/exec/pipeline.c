/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:07:08 by cchieko           #+#    #+#             */
/*   Updated: 2020/06/21 17:11:25 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

static int	ft_launch_one_side(t_shell *shell, t_ast *side)
{
	int		save[3];
	char	**cmd;
	char	*path;
	int		status;

	if ((status = ft_init_launch(shell, save, side)) == REDIR_ERROR)
		return (status);
	if ((cmd = ft_cmd_into_tab(side)))
	{
		if (is_bltin(cmd[0]))
			status = ft_launch_builtin(shell, cmd);
		else if ((status = ft_get_path(shell, cmd[0], &path)) == PATH_OK)
		{
			if ((status = execve(path, cmd, shell->env)) == -1)
				ft_exit(STR_EXECVE_ERROR, 1);
			free(path);
		}
		else
			return (status);
		ft_freetab(&cmd);
	}
	else
		return (EXIT_SUCCESS);
	ft_restore_std_fd(side, save);
	return (status);
}

static int	ft_pipe_to_right(t_shell *shell, int fd[2], t_ast *node_right)
{
	pid_t	pid_right;
	int		status_right;

	if ((pid_right = fork()) == -1)
		ft_exit(STR_FORK_ERROR, 1);
	if (pid_right == 0)
	{
		close(fd[1]);
		ft_make_dup2(node_right->token->str, fd[0], STDIN_FILENO);
		if (node_right->parent->parent\
				&& node_right->parent->parent->operator_type == PIPE)
			exit(ft_launch_pipeline(shell, node_right,\
						node_right->parent->parent->right));
		else
			exit(ft_launch_one_side(shell, node_right));
	}
	else
	{
		close(fd[1]);
		waitpid(pid_right, &status_right, 0);
	}
	return (ft_exit_status(status_right));
}

int			ft_launch_pipeline(t_shell *shell, t_ast *node_left,
	t_ast *node_right)
{
	int		fd[2];
	pid_t	pid_left;
	int		status_right;

	if (pipe(fd) == -1)
	{
		ft_put_cmd_error(node_left->left->token->str, STR_PIPE_ERROR);
		return (EXIT_FAILURE);
	}
	if ((pid_left = fork()) == -1)
		ft_exit(STR_FORK_ERROR, 1);
	if (pid_left == 0)
	{
		close(fd[0]);
		ft_make_dup2(node_left->token->str, fd[1], STDOUT_FILENO);
		exit(ft_launch_one_side(shell, node_left));
	}
	else
	{
		status_right = ft_pipe_to_right(shell, fd, node_right);
		close(fd[0]);
		waitpid(pid_left, NULL, 0);
	}
	return (status_right);
}
