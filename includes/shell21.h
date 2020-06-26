
#ifndef SHELL21_H
# define SHELL21_H

# include <signal.h>
# include <limits.h>

# include "libft.h"
# include "lexer.h"


# define BGREEN         "\033[1;32m"
# define BWHITE         "\033[1;37m"
# define BLUE           "\033[0;34m"

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

typedef struct	s_shell
{
	t_input		input;
	char		**env;
	char		**history;
	int			return_value;
	int			h_ind;
	int			sigint;
}				t_shell;

t_shell			*init(void);
void			signal_handler(t_shell *shell, int exec);
void			*sigwinch_handler(t_shell *shell);
void			exit_shell(t_shell *shell, char *str, int ret);

/*
** Line edit part
*/

# include <term.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <pwd.h>

# define INPUTSIZE		4096
# define BUFFSIZE		6
# define DEFAULT_TERM	"xterm-256color"
# define HISTO_PROMPT	"search_history> "

enum			e_mode
{
	DEFAULT,
	QUOTES,
	LIST = 1,
	HEREDOC
};

/*
** READLINE
*/
void			read_line(t_shell *shell, char **line, int len_prompt, int mode);
/*
** TERM
** interpret mode :
** 0 == regular prompt
** 1 == parser prompt waiting for the end of input list or quote.
** 2 == heredoc
** 3 == historic search
*/
void			init_input_struct(t_input *input, int len_prompt);
void			init_raw_term(t_shell *shell);
void			init_canonic_term(void);
int				interpret(char *buff, t_shell *shell, int mode);


/*
** Cursor movement
*/
void			move_left(t_input *input);
void			move_right(t_input *input);
void			move_up(t_input *input);
void			move_down(t_input *input);

/*
** Shift the cursor
*/
void			shift_to_beginning(t_input *input);
void			shift_to_end(t_input *input);
void			shift_to_next_word(t_input *input);
void			shift_to_prev_word(t_input *input);

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
void			accept_line(t_input *input);

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
int				ft_put_prompt_sigint(t_shell *shell);
int				ft_display_prompt(void);

/*
** HISTORY
*/
void			ft_history_back(t_shell *shell);
void			ft_history_forth(t_shell *shell);
void			ft_history_search(t_shell *shell);


/*
** Parsing
*/

# define PARSER_SUCCESS 	0
# define PARSER_ERROR 		258
# define HEREDOC_EOF 		2
# define SHELL 				"21sh: "
# define SYNTAX_ERR 		"syntax error near unexpected token `"
# define UNEXPECTED_EOF 	"syntax error: unexpected end of file"
# define END_ERR 			"'"
# define SQUOTES_PROMPT 	"squote> "
# define DQUOTES_PROMPT 	"dquote> "
# define ESCAPE_PROMPT 		"escape> "
# define PIPE_PROMPT 		"pipe> "
# define AND_IF_PROMPT 		"and_if> "
# define OR_IF_PROMPT 		"or_if> "
# define HEREDOC_PROMPT 	"heredoc> "

typedef struct	s_ast
{
	struct s_ast	*parent;
	struct s_ast	*left;
	struct s_ast	*right;
	int				node_type;
	int				operator_type;
	t_token			*token;
}				t_ast;

int				parser(t_shell *shell, t_lexer *lexer);
int				check_syntax(t_lexer *lexer);

/*
** INCOMPLETE INPUT
*/
int				ft_read_again_quoting(t_shell *shell, t_lexer *lexer);
int				ft_read_again_heredoc(t_shell *shell, t_lexer *lexer, t_token *dless);
int				ft_read_again_list(t_shell *shell, t_lexer *lexer, int list_type);

/*
** QUOTES for heredoc delimiter
*/
char			*ft_remove_quotes(char *str);

/*
** AST
*/
t_ast			*ft_create_ast(t_token **token);
t_ast			*ft_create_node(t_ast *left, t_ast *node, t_ast *right);
t_ast			*ft_create_leaf(t_token **token, int delim);
int				ft_check_next_operator(t_token *token, int op);
void			ft_del_ast(t_ast **ast);


/*
** builtins
 */

# define EXIT_ERROR		255

# define CMD_CD			"cd"
# define CMD_ECHO		"echo"
# define CMD_ENV		"env"
# define CMD_HIST		"history"
# define CMD_SETENV		"setenv"
# define CMD_UNSETENV	"unsetenv"
# define CMD_EXIT		"exit"
# define STR_NUM		"numeric argument required"
# define STR_NAME		"Variable name must contain alphanumeric characters."
# define STR_TOO_MANY	"too many arguments"
# define STR_HOME		"HOME not set"
# define STR_OLDPWD		"OLDPWD not set"
# define STR_HIST_EMPTY	"21sh: history is empty"

int		is_bltin(char *cmd);
int		bltin_echo(char **cmd);
int		bltin_env(t_shell *shell, char **cmd);
int		bltin_setenv(t_shell *shell, char **cmd);
int		bltin_unsetenv(t_shell *shell, char **cmd);
int		bltin_cd(t_shell *shell, char **cmd);
void	bltin_exit(t_shell *shell, char **cmd);
int		bltin_history(t_shell *shell, char **cmd);
/*
** ENV
*/
char	*get_env(char **env, char *var);
void	modify_variable(char ***env, char *new_var);


/*
** Execute
 */
# include <sys/stat.h>
//# include <fcntl.h>
# include <errno.h>

# define PATH_OK			0
# define REDIR_OK			0
# define REDIR_ERROR		1
# define CMD_NOT_FOUND		127
# define NO_FILE 			127
# define IS_DIR 			126
# define PERM_DENIED 		126

# define STR_FORK_ERROR		"21sh: fork failed"
# define STR_EXECVE_ERROR	"21sh: execve failed"
# define STR_CMD_NOT_FOUND	"command not found"
# define STR_NO_FILE 		"No such file or directory"
# define STR_IS_DIR 		"is a directory"
# define STR_NOT_DIR 		"Not a directory"
# define STR_PERM_DENIED 	"Permission denied"
# define STR_BAD_FD 		"Bad file descriptor"
# define STR_AMB_REDIR		"ambiguous redirection"
# define STR_OPEN_ERROR		"open error"
# define STR_DUP_ERROR 		"dup error"
# define STR_PIPE_ERROR 	"pipe failed"
# define STR_SEGFAULT		"Segmentation Fault: 11"
# define STR_FLOATING		"Floating point exception: 8"
# define STR_BUS_ERROR		"Bus error: 10"
# define STR_SIGABORT		"Abort: 6"

/*
** EXECUTION
*/
int		ft_execute(t_shell *shell, t_ast *ast);
int		ft_launch_builtin(t_shell *shell, char **cmd);
int		ft_launch_simple_cmd(t_shell *shell, t_ast *ast);
int		ft_launch_pipeline(t_shell *shell, t_ast *node_left, t_ast *node_right);
int		ft_init_launch(t_shell *shell, int save[3], t_ast *ast);
char	**ft_cmd_into_tab(t_ast *ast);
int		ft_fork(t_shell *shell, char *path, char **cmd);
int		ft_exit_status(int ret);

/*
** EXPANSION AND QUOTES
*/
void	ft_expand(t_shell *shell, t_token *token);
void	ft_remove_quoting(t_shell *shell, t_token *token);
void	ft_heredoc_expand_remove_quoting(t_shell *shell, t_token *token);
int		ft_is_valid_expand(char *str);
void	ft_var_expansion(t_shell *shell, char **str, char *dollar);
/*
** REDIRECTION
*/
void	ft_save_std_fd(int save[3]);
void	ft_restore_std_fd(t_ast *ast, int save[3]);
int		ft_init_redirection(t_ast *ast);
int		ft_agreg_files(t_token *redir);
int		ft_heredoc_pipe(t_token *redir);
int		ft_make_dup2(char *dest_name, int fd_dest, int fd_src);
int		ft_open_error(int fd, int err, char *file_name);
int		ft_open_file(t_token *file);

/*
** PATH
*/
int		ft_get_path(t_shell *shell, char *cmd, char **path);
void	ft_put_cmd_error(char *cmd, char *error);


#endif
