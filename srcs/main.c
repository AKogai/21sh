#include "shell21.h"

static void	ft_run_cmd(t_shell *shell, char **argv, t_lexer *lexer)
{
	t_ast	*ast;

	if (lexer->last->token_type == NEWLINE)
	{
		signal_handler(shell, 1);
		ast = ft_create_ast(&lexer->first);
		if (ast && (ft_strequ(argv[1], "--ast") || ft_strequ(argv[2], "--ast")))
			ft_print_ast(ast, "root", 0);
		shell->return_value = ft_execute(shell, ast);
		ft_del_ast(&ast);
		signal_handler(shell, 0);
	}
}

int			main(int argc, char **argv, char **environ)
{
	char	*line;
	t_lexer	*lexer;
	t_shell	*shell;
	int		ret_cmd;

	lexer = NULL;
	(void)argc;
	shell = init(environ);
	signal_handler(shell, 0);
	while (1)
	{
		shell->sigint = 0;
		ft_read_line(shell, &line, ft_put_prompt_sigint(shell), DEFAULT);
		ft_tokenize(&lexer, line);
		ret_cmd = ft_parser(shell, lexer);
		if (lexer && lexer->nbr_token && ft_strequ(argv[1], "--lexer"))
			ft_printlexer(lexer->first, lexer->nbr_token);
		if (ret_cmd == PARSER_SUCCESS)
			ft_run_cmd(shell, argv, lexer);
		else
			shell->return_value = ret_cmd;
		ft_dellexer(&lexer);
		ft_strdel(&line);
	}
	return (0);
}
