
#include "shell21.h"

/*
** Copy : ctrl + K
** Cut : ctrl + X
** Paste : ctrl + I (same function as ft_insertchar)
*/

void	ft_copy(t_input *input)
{
	int		i;

	i = input->y * (input->width + 1) + input->x - input->prompt;
	ft_bzero(input->tmp, INPUTSIZE);
	input->tmp = ft_strncpy(input->tmp, input->line + i, input->len - i);
}

void	ft_cut(t_input *input)
{
	int		i;

	i = input->y * (input->width + 1) + input->x - input->prompt;
	ft_bzero(input->tmp, INPUTSIZE);
	input->tmp = ft_strncpy(input->tmp, input->line + i, input->len - i);
	ft_bzero(input->line + i, INPUTSIZE - i);
	input->len = ft_strlen(input->line);
	ft_clear(input);
	ft_putstr(input->line);
	ft_goto_lastpos(input);
}
