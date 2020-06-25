#include "shell21.h"

static void	ft_run_cmd(t_shell *shell, t_lexer *lexer)
{
	t_ast	*ast;

	if (lexer->last->token_type == NEWLINE)
	{
		signal_handler(shell, 1);
		ast = ft_create_ast(&lexer->first);
		shell->return_value = ft_execute(shell, ast);
		ft_del_ast(&ast);
		signal_handler(shell, 0);
	}
}

int			main(void)
{
	char	*line;
	t_lexer	*lexer;
	t_shell	*shell;
	int		ret_cmd;

	shell = init();
	signal_handler(shell, 0);
	while (1)
	{
		shell->sigint = 0;
		read_line(shell, &line, ft_put_prompt_sigint(shell), DEFAULT);
		ft_tokenize(&lexer, line);
		ret_cmd = ft_parser(shell, lexer);
		if (ret_cmd == PARSER_SUCCESS)
			ft_run_cmd(shell, lexer);
		else
			shell->return_value = ret_cmd;
		ft_dellexer(&lexer);
		ft_strdel(&line);
	}
	return (0);
}
