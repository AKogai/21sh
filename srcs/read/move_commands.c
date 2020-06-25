
#include "shell21.h"

/*
** Shift + <-- shift the cursor to the beginning of line.
** Shift + --> shift the cursor to the end of line.
** Option(alt) + --> shift the cursor to the next word.
** Option(alt) + <-- shift the cursor to the previous word.
*/

void	shift_to_beginning(t_input *input)
{
	ft_goto_prompt(input);
	input->x = input->prompt;
	input->y = 0;
}

void	shift_to_end(t_input *input)
{
	while ((input->y * (input->width + 1) + input->x)\
			< (input->prompt + input->len))
		move_right(input);
}

void	shift_to_next_word(t_input *input)
{
	int	i;

	i = input->y * (input->width + 1) + input->x - input->prompt;
	while (input->line[i] && input->line[i] != ' ')
	{
		move_right(input);
		++i;
	}
	while (input->line[i] && input->line[i] == ' ')
	{
		move_right(input);
		++i;
	}
}

void	shift_to_prev_word(t_input *input)
{
	int	i;

	i = input->y * (input->width + 1) + input->x - input->prompt;
	if ((i > 0 && input->line[i] != ' ' && input->line[i - 1] == ' ') \
			|| (i > 0 && input->line[i] == '\0'))
	{
		move_left(input);
		--i;
	}
	while ((i > 0) && input->line[i] == ' ')
	{
		move_left(input);
		--i;
	}
	while ((i > 0) && input->line[i] != ' ')
	{
		move_left(input);
		--i;
	}
	if (i > 0)
		move_right(input);
}
