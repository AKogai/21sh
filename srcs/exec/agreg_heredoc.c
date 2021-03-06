/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agreg_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:07:08 by cchieko           #+#    #+#             */
/*   Updated: 2020/06/21 17:11:25 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

int		ft_agreg_files(t_token *redir)
{
	int	fd_dest;
	int	fd_src;

	fd_dest = ft_atoi(redir->next->str);
	if (redir->prev && redir->prev->token_type == IO_NUMBER)
		fd_src = ft_atoi(redir->prev->str);
	else if (redir->operator_type == LESS_AND)
		fd_src = STDIN_FILENO;
	else
		fd_src = STDOUT_FILENO;
	if (ft_isnumber(redir->next->str))
		return (ft_make_dup2(redir->next->str, fd_dest, fd_src));
	else if (ft_strequ(redir->next->str, "-"))
	{
		close(fd_src);
		return (REDIR_OK);
	}
	else
	{
		ft_put_cmd_error(redir->next->str, STR_AMB_REDIR);
		return (REDIR_ERROR);
	}
}

int		ft_heredoc_pipe(t_token *redir)
{
	int fd[2];

	if (pipe(fd) == -1)
	{
		ft_put_cmd_error(redir->str, STR_PIPE_ERROR);
		return (REDIR_ERROR);
	}
	write(fd[1], redir->heredoc, ft_strlen(redir->heredoc));
	close(fd[1]);
	ft_make_dup2(redir->str, fd[0], STDIN_FILENO);
	close(fd[0]);
	return (REDIR_OK);
}
