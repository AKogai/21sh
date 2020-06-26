/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:07:08 by cchieko           #+#    #+#             */
/*   Updated: 2020/06/21 17:11:25 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

static char		*ft_get_user(void)
{
	struct passwd *ret_pwd;

	if (!(ret_pwd = getpwuid(getuid())))
		return (NULL);
	return (ft_strdup(ret_pwd->pw_name));
}

static void		ft_prompt_ret_cmd(void)
{
	ft_putstr(BGREEN" $> "RESET);
}

int				ft_put_prompt_sigint(t_shell *shell)
{
	int len;

	init_raw_term(shell);
	tputs(tgetstr("cr", NULL), 1, &ft_intputchar);
	tputs(tgetstr("ce", NULL), 1, &ft_intputchar);
	len = ft_display_prompt();
	init_canonic_term();
	return (len);
}

int				ft_display_prompt(void)
{
	char	*user;
	char	*cwd;
	int		len;

	len = 6;
	if ((user = ft_get_user()))
	{
		ft_putstr(user);
		ft_putstr(": "BLUE);
		len += ft_strlen(user);
	}
	else
	{
		ft_putstr("21sh: "BLUE);
		len += 4;
	}
	free(user);
	if ((cwd = getcwd(NULL, 0)))
	{
		ft_putstr(cwd);
		len += ft_strlen(cwd);
	}
	free(cwd);
	ft_prompt_ret_cmd();
	return (len);
}
