/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 08:09:05 by cchieko           #+#    #+#             */
/*   Updated: 2019/04/27 13:58:47 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int		word;
	int		flag;

	word = 0;
	flag = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (flag == 1 && *s == c)
			flag = 0;
		if (flag == 0 && *s != c)
		{
			flag = 1;
			word++;
		}
		s++;
	}
	return (word);
}

int 		ft_wordlen(char const *str, char const c)
{
	int 	i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		words;
	int		i;
	int		word_len;

	words = count_words(s, c);
	if (!(arr = (char **)ft_memalloc(sizeof(char *) * (words + 1))))
		return (NULL);
	i = 0;
	while (words--)
	{
		while (*s && *s == c)
			s++;
		word_len = ft_wordlen(s, c);
		if (!(arr[i] = ft_strsub(s, 0, word_len)))
			return (NULL);
		s +=word_len;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
