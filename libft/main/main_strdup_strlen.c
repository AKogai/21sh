/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strdup_strlen.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:30:13 by sfranc            #+#    #+#             */
/*   Updated: 2016/11/14 16:53:32 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t		ft_strlen(const char *s)
{
	char const *temp;

	temp = s;
	while (*temp)
		temp++;
	return (temp - s);
}

char	*ft_strdup(const char *s1)
{
	char	*s1_dup;
	char	*temp;

	s1_dup = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	temp = s1_dup;
	while (*s1)
	{
		*temp++ = *s1++;
	}
	*temp = '\0';
	return (s1_dup);
}

int		main()
{
	char	s1[12] = "Test strdup";

	printf("%d\n", (int)ft_strlen(s1));
	printf("%d\n", (int)strlen(s1));
	printf("%s\n", ft_strdup(s1));
	return (0);
}

