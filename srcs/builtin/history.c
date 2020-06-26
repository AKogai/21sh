/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:07:08 by cchieko           #+#    #+#             */
/*   Updated: 2020/06/21 17:11:25 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

int		bltin_history(t_shell *shell, char **cmd)
{
	int len;
	int	i;

	if (!cmd[1])
	{
		if (!shell->history)
			ft_putendl(STR_HIST_EMPTY);
		else
		{
			len = ft_tablen(shell->history);
			i = 0;
			while (i < len)
			{
				ft_putnbr(i + 1);
				ft_putstr("\t");
				ft_putendl(shell->history[i]);
				i++;
			}
		}
	}
	else if (ft_strequ(cmd[1], "-c"))
		ft_freetab(&shell->history);
	return (EXIT_SUCCESS);
}
