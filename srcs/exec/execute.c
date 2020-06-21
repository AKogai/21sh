
#include "shell21.h"

int				ft_execute_pipeline(t_shell *shell, t_ast *ast)
{
	if (!ast->left)
		return (ft_launch_pipeline(shell, ast, ast->parent->right));
	else
		return (ft_execute_pipeline(shell, ast->left));
}

static int		ft_execute_semi_list(t_shell *shell, t_ast *ast)
{
	ft_execute(shell, ast->left);
	return (ft_execute(shell, ast->right));
}

static int		ft_execute_andif_list(t_shell *shell, t_ast *ast)
{
	if (ft_execute(shell, ast->left) == EXIT_SUCCESS)
		return (ft_execute(shell, ast->right));
	else
		return (EXIT_SUCCESS);
}

static int		ft_execute_orif_list(t_shell *shell, t_ast *ast)
{
	if (ft_execute(shell, ast->left) != EXIT_SUCCESS)
		return (ft_execute(shell, ast->right));
	else
		return (EXIT_SUCCESS);
}

int				ft_execute(t_shell *shell, t_ast *ast)
{

	if (!ast)
		return (EXIT_SUCCESS);
	if (ast->operator_type == SEMI)
		return (ft_execute_semi_list(shell, ast));
	else if (ast->operator_type == AND_IF)
		return (ft_execute_andif_list(shell, ast));
	else if (ast->operator_type == OR_IF)
		return (ft_execute_orif_list(shell, ast));
	else if (ast->operator_type == PIPE)
		return (ft_execute_pipeline(shell, ast));
	else if (ast->node_type != OPERATOR)
		return (ft_launch_simple_cmd(shell, ast));
	else
		return (EXIT_SUCCESS);
}
