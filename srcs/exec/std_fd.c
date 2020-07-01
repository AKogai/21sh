/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:07:08 by cchieko           #+#    #+#             */
/*   Updated: 2020/06/21 17:11:25 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

void	ft_save_std_fd(int save[3])
{
	save[0] = dup(STDIN_FILENO);
	save[1] = dup(STDOUT_FILENO);
	save[2] = dup(STDERR_FILENO);
}

void	ft_restore_std_fd(t_ast *ast, int save[3])
{
	t_token *tmp;

	dup2(save[0], STDIN_FILENO);
	dup2(save[1], STDOUT_FILENO);
	dup2(save[2], STDERR_FILENO);
	close(save[0]);
	close(save[1]);
	close(save[2]);
	if (!ast)
		return ;
	tmp = ast->token;
	while (tmp)
	{
		if (tmp->token_type == REDIRECT)
		{
			if (tmp->fd > 0)
				close(tmp->fd);
		}
		tmp = tmp->next;
	}
}
