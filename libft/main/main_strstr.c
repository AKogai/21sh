/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 11:26:31 by sfranc            #+#    #+#             */
/*   Updated: 2016/11/15 12:13:17 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

#define RESET "\033[0m"
#define BOLDBLUE "\033[1m\033[34m"      /* Bold Blue */
#define MAGENTA "\033[35m"      /* Magenta */

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

char	*ft_strstr(const char *big, const char *little)
{
	size_t	n;

	n = ft_strlen(little);
	if (n == 0)
		return((char*)big);		
	while (*big)
	{
		printf("%d\t",ft_strncmp(big, little, n));
		printf("%s\t %s\t", big, little);
		if (ft_strncmp(big, little, n) == 0)
		{
			printf("ICI\n");
			return ((char*)big);
		}
		else
		{
			printf("ou la\n");
			big++;
		}
	}
	printf("alors la\n");
	return (NULL);
}

int	main()
{
	char *src;
	char *dst;
	
	// printf(MAGENTA "\ntest EASY\n" RESET);
	src = ft_strdup("");
	dst = ft_strdup("little");
	printf("   big : %s\n", src);
	printf("little : %s\n", dst);
	printf(MAGENTA"     moi : %s\n", ft_strstr(src, dst));
	printf("la vraie : %s\n"RESET, strstr(src, dst));

	return (0);
}
