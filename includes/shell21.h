
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
	t_input		input;
	char		**env;
	char		**history;
	int			return_value;
	int			h_ind;
	int			sigint;
}				t_shell;

t_shell			*g_shell;

t_shell			*init(char **env);
void			signal_handler(int exec);
void			exit_shell(char *str, int ret);
#endif
