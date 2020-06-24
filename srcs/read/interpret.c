
#include "shell21.h"

static void	ft_put_unexpected_eof(void)
{
	ft_putchar('\n');
	ft_putstr_fd(SHELL, 2);
	ft_putendl_fd(UNEXPECTED_EOF, 2);
}

static void	ft_interpret_moves(char *buff, t_input *input)
{
	if (buff[0] == 27 && buff[1] == 91 && buff[2] == 67)
		ft_move_right(input);
	else if (buff[0] == 27 && buff[1] == 91 && buff[2] == 68)
		ft_move_left(input);
	else if (buff[0] == 27 && buff[1] == 107)
		ft_move_up(input);
	else if (buff[0] == 27 && buff[1] == 108)
		ft_move_down(input);
	else if (buff[0] == 1 || (buff[0] == 27 && buff[1] == 91 && buff[2] == 72))
		ft_beginning_of_line(input);
	else if (buff[0] == 5 || (buff[0] == 27 && buff[1] == 91 && buff[2] == 70))
		ft_end_of_line(input);
	else if (buff[0] == 27 && buff[1] == 102)
		ft_jumpword_forward(input);
	else if (buff[0] == 27 && buff[1] == 98)
		ft_jumpword_backward(input);
}

static int	ft_interpret_buffer(char *buff, t_shell *shell, int mode)
{
	if (buff[0] == 27 && buff[1] == 91 && buff[2] == 65)
		ft_history_back(shell);
	else if (buff[0] == 27 && buff[1] == 91 && buff[2] == 66)
		ft_history_forth(shell);
	else if (buff[0] == 18 && !mode)
		ft_history_search(shell);
	else if (buff[0] == 11)
		ft_copy(&shell->input);
	else if (buff[0] == 24)
		ft_cut(&shell->input);
	else if (buff[0] == 9)
	{
		if (ft_insertchar(shell->input.tmp, &shell->input))
			return (1);
	}
	else if (ft_isprint(buff[0]))
	{
		if (ft_insertchar(buff, &shell->input))
			return (1);
	}
	else if (buff[0] == 127)
		ft_back_deletechar(&shell->input);
	else if (buff[0] == 27 && buff[1] == 91 && buff[2] == 51 && buff[3] == 126)
		ft_deletechar(&shell->input);
	return (0);
}

static int	ft_interpret_other_actions(char *buff, t_input *input, int mode)
{
	if (buff[0] == 3)
		return (1);
	else if (buff[0] == 12)
		ft_clear_screen(input);
	else if (buff[0] == '\n')
	{
		ft_accept_line(input);
		return (1);
	}
	else if (buff[0] == 4 && !*input->line && (mode == 0 || mode == 3))
	{
		ft_canonic_term();
		ft_exit("exit", 1);
	}
	else if (buff[0] == 4 && !*input->line && mode)
	{
		if (mode == 1)
			ft_put_unexpected_eof();
		else
			write(1, "\n", 1);
		return (1);
	}
	else if (buff[0] == 4 && *input->line)
		tputs(tgetstr("bl", NULL), 1, &ft_intputchar);
	return (0);
}

int			ft_interpret(char *buff, t_shell *shell, int mode)
{
	ft_interpret_moves(buff, &shell->input);
	if (ft_interpret_buffer(buff, shell, mode))
	{
		ft_accept_line(&shell->input);
		return (1);
	}
	if (ft_interpret_other_actions(buff, &shell->input, mode))
		return (1);
	return (0);
}
