/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strnstr2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 13:44:26 by sfranc            #+#    #+#             */
/*   Updated: 2016/11/15 15:51:29 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlen(const char *s)
{
	char const *temp;

	temp = s;
	while (*temp)
		temp++;
	return (temp - s);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n-- > 0 && (*s1 || *s2))
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		else
		{
			s1++;
			s2++;
		}
	}
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	n;
	int	i;

	n = ft_strlen(little);
	if (n == 0)
		return ((char*)big);
	i = 0;
	while (i <= (int)(len - n))
	{
		if (ft_strncmp(big, little, n) == 0)
			return ((char*)big);
		else
		{
			big++;
			i++;
		}
	}
	return (NULL);
}
