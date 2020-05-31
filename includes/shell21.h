/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell21.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 12:35:19 by sfranc            #+#    #+#             */
/*   Updated: 2017/09/27 17:41:57 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL21_H
# define SHELL21_H

# include <signal.h>

# include "libft.h"
# include "builtin.h"
# include "line_editing.h"
# include "lexer.h"
# include "parser.h"
# include "execute.h"

# define BBLUE          "\033[1;34m"
# define BMAGENTA       "\033[1;35m"
# define BGREEN         "\033[1;32m"
# define BRED           "\033[1;31m"
# define BWHITE         "\033[1;37m"
# define BLUE           "\033[0;34m"

typedef struct	s_shell
{
	char		**env;
	t_input		input;
	int			ret_cmd;
	char		**history;
	int			histo_index;
	int			sigint;
}				t_shell;

t_shell			*g_shell;

t_shell			*ft_init(char **env);
void			ft_catch_signals(int exec);
void			ft_exit_shell(char *str, int ret);
#endif
