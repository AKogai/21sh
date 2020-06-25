
#include "shell21.h"

/*
** Basic cursor moves :
** Same as bash = right (key: ->) and left (key: <-)
** Bonus = up (key: page up) and down (key: page down)
*/

void	move_right(t_input *input)
{
	if ((input->y * (input->width + 1) + input->x)\
			< (input->prompt + input->len))
	{
		if (input->x < input->width)
		{
			tputs(tgetstr("nd", NULL), 1, &ft_intputchar);
			input->x++;
		}
		else
		{
			tputs(tgetstr("cr", NULL), 1, &ft_intputchar);
			tputs(tgetstr("sf", NULL), 1, &ft_intputchar);
			input->x = 0;
			input->y++;
		}
	}
	else
		tputs(tgetstr("bl", NULL), 1, &ft_intputchar);
}

void	move_left(t_input *input)
{
	int i;

	if ((input->y == 0 && input->x > input->prompt)\
			|| (input->y > 0 && input->x > 0))
	{
		tputs(tgetstr("le", NULL), 1, &ft_intputchar);
		input->x--;
	}
	else if (input->y > 0 && input->x == 0)
	{
		i = input->width;
		while (i--)
			tputs(tgetstr("nd", NULL), 1, &ft_intputchar);
		tputs(tgetstr("up", NULL), 1, &ft_intputchar);
		input->x = input->width;
		input->y--;
	}
	else
		tputs(tgetstr("bl", NULL), 1, &ft_intputchar);
}

void	move_up(t_input *input)
{
	if (input->y > 1 || (input->y == 1 && input->x >= input->prompt))
	{
		tputs(tgetstr("up", NULL), 1, &ft_intputchar);
		input->y--;
	}
	else if (input->y == 1 && input->x < input->prompt)
		shift_to_beginning(input);
	else
		tputs(tgetstr("bl", NULL), 1, &ft_intputchar);
}

void	move_down(t_input *input)
{
	if (((input->y + 1) * (input->width + 1) + input->x)\
			< (input->prompt + input->len))
	{
		input->y++;
		ft_goto_newpos(input, input->y - 1);
	}
	else if (((input->y + 1) * (input->width + 1))\
			<= (input->prompt + input->len))
		shift_to_end(input);
	else
		tputs(tgetstr("bl", NULL), 1, &ft_intputchar);
}
