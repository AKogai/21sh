//
// Created by kosimovsky on 28.04.2020.
//

#ifndef MINISHELL_SHELL_H
#define MINISHELL_SHELL_H
#include "libft.h"
#include <stdlib.h>
#include <stdint.h>
#include <signal.h>
#include <dirent.h>
#include <pwd.h>
#include <limits.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <term.h>
#include <termcap.h>
#include <termios.h>
#include <curses.h>
#include <uuid/uuid.h>

# define PROMPT "shell > "
# define ERR_COUNT 10
# define INPUTSIZE		4096
# define BUFFSIZE		6
# define DEFAULT_TERM	"xterm-256color"
# define HISTO_PROMPT	"search_history> "
# define SHELL 				"21sh: "
# define UNEXPECTED_EOF 	"syntax error: unexpected end of file"
# define BGREEN		"\033[1;32m"
# define BRED		"\033[1;31m"
# define BWHITE		"\033[1;37m"
# define BLUE		"\033[0;34m"

/*
 * Global
 */

typedef struct	s_input
{
	char	*line;
	char	*tmp;
	int		width;
	int		len;
	int		x;
	int		y;
	int		prompt;
	int		origin_prompt;
}				t_input;

enum			e_mode
{
	DEFAULT,
	QUOTES,
	LIST = 1,
	HEREDOC,
	HISTORY
};

//t_shell			*ft_init(char **env);
void			ft_catch_signals(int exec);
//void			ft_modify_variable(char ***env, char *new_var);
char			*ft_get_env_variable(char **env, char *var);

/*
 * Typedefs
 */


/*
 * структура s_shell с необходимыми элементами для запуска команд
 */
typedef struct      s_shell
{
    int     	argc;
    char    	**argv;
    char    	*string;
    char    	*path;
    char    	**env;
    t_input		input;
    char		**history;
	int			histo_index;
	int			ret_cmd;
	int			sigint;
}                   t_sh;

t_sh           *g_sh;

/*
 * структура, которая содержит имя, значение переменной
 * окружения и ссылку на следующую переменную
 */
typedef struct              s_env
{
    char            *name;
    char            *value;
    struct s_env    *next;
}                           t_env;

typedef enum e_err
{
	ERR_ACCESS,
	ERR_FORK,
	ERR_MALLOC_FAIL,
	ERR_CMD_NTFND,
	ERR_ENV,
	ERR_NO_ENV,
	ERR_READ,
	ERR_CMD_MNPL,
	ERR_PATH,
	ERR_EXECVE,
	ERR_WAIT,
	ERR_GET_CWD,
	ERR_CD,
	ERR_ENV_OVERWRITE,
	ERR_PATHCONF,
	ERR_SETENV
}           t_error;

enum boolean    { NO, YES };

/*
 * указатель на массив структур с названием ошибок и их
 * значением
 */
typedef struct s_errors *err_ptr;

/*
 * массив структур, которые содержат значение
 * ошибки и её номер
 */
struct          s_errors
{
	t_error       err_id;
	char        *error_str;
};


/*
 * Functions
 */

/*
 * Вывод ошибки в стандартный поток вывода ошибок
 */
char    *print_error(t_error error);
t_sh    *init_sh(char **envp);
t_env   *init_env(void);
char    *sh_getenv(t_env *env, const char *name);
int		sh_setenv(t_sh *shell, const char *n_name,
                     const char *n_value, enum boolean);
void    free_env(t_env *env);
int     split_cmd(t_sh *);
char    *alloc_path(size_t *);
int		exec_cmd_ops(t_sh *);
int		expand_it(char **, char **);
int		find_binary_in_path(t_sh *);
int		expand_var(char **, char **);
int		free_cmd(t_sh *shell);
char	**convert_env(t_env *env);
int		sh_unsetenv(t_env *env, const char *name);

/*
 * readline
 */

void			ft_read_line(char **line, int len_prompt, int mode);

/*
** TERM
** ft_interpret mode :
** 0 == regular prompt
** 1 == parser prompt waiting for the end of input list or quote.
** 2 == heredoc
** 3 == historic search
*/
void			ft_init_input_struct(t_input *input, int len_prompt);
void			ft_raw_term(void);
void			ft_canonic_term(void);
int				ft_interpret(char *buff, t_input *input, int mode);
int				ft_intputchar(int c);

/*
** CURSOR MOVES
*/
void			ft_move_left(t_input *input);
void			ft_move_right(t_input *input);
void			ft_move_up(t_input *input);
void			ft_move_down(t_input *input);

/*
** MOVE COMMANDS
*/
void			ft_beginning_of_line(t_input *input);
void			ft_end_of_line(t_input *input);
void			ft_jumpword_forward(t_input *input);
void			ft_jumpword_backward(t_input *input);

/*
** MOVES NOT LINKED TO USER COMMANDS
*/
void			ft_goto_begin(t_input *input);
void			ft_goto_prompt(t_input *input);
void			ft_goto_newpos(t_input *input, int cur_y);
void			ft_goto_lastpos(t_input *input);

/*
** BUFFER
*/
int				ft_insertchar(char *buff, t_input *input);
void			ft_back_deletechar(t_input *input);
void			ft_deletechar(t_input *input);
void			ft_accept_line(t_input *input);

/*
** COPY N CUT
*/
void			ft_copy(t_input *input);
void			ft_cut(t_input *input);

/*
** SCREEN
*/
void			ft_clear(t_input *input);
void			ft_clear_screen(t_input *input);

/*
** PROMPT
*/
int				ft_put_prompt_sigint(void);
int				ft_display_prompt(void);

/*
** HISTORY
*/
void			ft_history_back(t_input *input);
void			ft_history_forth(t_input *input);
void			ft_history_search(t_input *input);

/*
 * Built-in functions
 */

int		bltn_cd(t_sh *);
int     bltn_env(t_sh *);
void    bltn_exit(t_sh *);
int		bltn_setenv(t_sh *);
int		bltn_unsetenv(t_sh *);
int		bltn_echo(t_sh *);
#endif //MINISHELL_SHELL_H
