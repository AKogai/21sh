/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:07:08 by cchieko           #+#    #+#             */
/*   Updated: 2020/06/21 17:11:25 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

void	exit_shell(t_shell *shell, char *str, int ret)
{
	int i;

	if (str)
		ft_putendl_fd(str, 2);
	shell->env ? ft_freetab(&shell->env) : 0;
	shell->history ? ft_freetab(&shell->history) : 0;
	free(shell);
	i = 0;
	while (i < 32)
		signal(i++, SIG_DFL);
	exit(ret);
}
