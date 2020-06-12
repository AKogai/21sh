#include "shell21.h"

static void	ft_run_cmd(char **argv, t_lexer *lexer)
{
	t_ast	*ast;

	if (lexer->last->token_type == NEWLINE)
	{
		signal_handler(1);
		ast = ft_create_ast(&lexer->first);
		if (ast && (ft_strequ(argv[1], "--ast") || ft_strequ(argv[2], "--ast")))
			ft_print_ast(ast, "root", 0);
		g_shell->return_value = ft_execute(ast);
		ft_del_ast(&ast);
		signal_handler(0);
	}
}

int			main(int argc, char **argv, char **environ)
{
	char	*line;
	t_lexer	*lexer;
	int		ret_cmd;

	(void)argc;
	signal_handler(0);
	g_shell = init(environ);
	while (1)
	{
		g_shell->sigint = 0;
		ft_read_line(&line, ft_put_prompt_sigint(), DEFAULT);
		ft_tokenize(&lexer, line);
		ret_cmd = ft_parser(lexer);
		if (lexer && lexer->nbr_token && ft_strequ(argv[1], "--lexer"))
			ft_printlexer(lexer->first, lexer->nbr_token);
		if (ret_cmd == PARSER_SUCCESS)
			ft_run_cmd(argv, lexer);
		else
			g_shell->return_value = ret_cmd;
		ft_dellexer(&lexer);
		ft_strdel(&line);
		write(1, "\n", 1);
	}
	return (0);
}
