/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_wd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 13:05:06 by cchieko           #+#    #+#             */
/*   Updated: 2019/04/27 12:39:51 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_is_tab_space(int c)
{
	if (c == ' ' || c == '\t')
	{
		return (1);
	}
	return (0);
}

static size_t	ft_wordcount_t_s(char const *string)
{
	size_t	index;
	size_t	wordcount;

	index = 0;
	wordcount = 0;
	while (string[index] != '\0')
	{
		while (ft_is_tab_space(string[index]) == 1)
		{
			index++;
		}
		if (string[index] != '\0')
		{
			wordcount++;
		}
		while (ft_is_tab_space(string[index]) == 0 && string[index] != '\0')
		{
			index++;
		}
	}
	return (wordcount);
}

static char		*ft_writeword_t_s(char const *string, size_t index)
{
	size_t	len;
	char	*ret;

	len = index;
	while (ft_is_tab_space(string[len]) == 0 && string[len] != '\0')
		len++;
	ret = (char *)ft_memalloc(sizeof(char) * len + 1);
	if (ret == NULL)
		return (NULL);
	len = 0;
	while (ft_is_tab_space(string[index]) == 0 && string[index] != '\0')
	{
		ret[len] = string[index];
		index++;
		len++;
	}
	ret[len] = '\0';
	return (ret);
}

char			**ft_strsplit_wd(char const *string)
{
	char	**ret;
	size_t	index;
	size_t	wordcount;
	size_t	wordindex;

	index = 0;
	wordcount = ft_wordcount_t_s(string);
	wordindex = 0;
	ret = (char **)ft_memalloc(sizeof(char *) * (wordcount + 1));
	if (ret == NULL)
		return (NULL);
	ret[wordcount] = NULL;
	while (string[index] != '\0' && wordindex < wordcount)
	{
		while (ft_is_tab_space(string[index]) == 1)
			index++;
		if (string[index] != '\0')
			ret[wordindex] = ft_writeword_t_s(string, index);
		wordindex++;
		while (ft_is_tab_space(string[index]) == 0 && string[index] != '\0')
			index++;
	}
	return (ret);
}
