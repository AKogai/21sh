/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:07:08 by cchieko           #+#    #+#             */
/*   Updated: 2020/06/21 17:11:25 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

void	ft_clear(t_input *input)
{
	ft_goto_prompt(input);
	tputs(tgetstr("cd", NULL), 1, &ft_intputchar);
}

void	ft_clear_screen(t_input *input)
{
	ft_clear(input);
	ft_bzero(input->line, INPUTSIZE);
	input->x = input->prompt;
	input->y = 0;
	input->len = 0;
}
