/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:07:08 by cchieko           #+#    #+#             */
/*   Updated: 2020/06/21 17:11:25 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

static void	ft_sigint_handler(int sig)
{
	write(1, "\n", 1);
	ft_display_prompt();
	(void)sig;
}

static void	void_handler(int sig)
{
	(void)sig;
}

void		signal_handler(t_shell *shell, int exec)
{
	signal(SIGTERM, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGWINCH, sigwinch_handler(shell));
	if (!exec)
	{
		shell->sigint = 1;
		shell->return_value = EXIT_FAILURE;
		signal(SIGINT, sigint_handler);
	}
	else
		signal(SIGINT, void_handler);
}
