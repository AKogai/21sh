/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strsplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 11:24:34 by sfranc            #+#    #+#             */
/*   Updated: 2016/11/18 16:30:38 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_words(char const *s, char c)
{
	int	nb_words;

	nb_words = 0;
	if (*s != c)
		nb_words++;
	while (*s++)
	{
		if (*(s - 1) == c && *s != c && *s != '\0')
			nb_words++;
	}
	return (nb_words);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	len;
	int		n;
	int		i;

	n = ft_nb_words(s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * (n + 1))))
		return (NULL);
	i = 0;
	while (i++ < n)
	{
		len = 0;
		while (*s == c)
			s++;
		while (*s != c)
		{
			s++;
			len++;
		}
		*tab++ = ft_strsub(s - len, 0, len);
	}
	*tab = 0;
	return (tab - n);
}

int			main(void)
{
	char 	*s;
	char 	**tab;
	char 	c;
	int 	i;

	s = ft_strdup("***************");
	c = '*',
	ft_putnbr(ft_nb_words(s, c));
	ft_putchar('\n');
	tab = ft_strsplit(s, c);
	i = 0;
	ft_putendl("OK");
	while (i++ < ft_nb_words(s, c))
	{
		ft_putendl(*tab);
		tab++;
	}
	ft_putendl("OK");
	return (0);
}
