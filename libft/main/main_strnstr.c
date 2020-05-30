/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strnstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 13:44:26 by sfranc            #+#    #+#             */
/*   Updated: 2016/11/15 15:57:45 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> 
#include <stdio.h>
#include <string.h>

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

// char	*ft_strstr(const char *big, const char *little)
// {
// 	size_t	n;

// 	n = ft_strlen(little);
// 	if (n == 0)
// 		return((char*)big);		
// 	while (*big)
// 	{
// 		if (ft_strncmp(big, little, n) == 0)
// 			return ((char*)big);
// 		else
// 			big++;
// 	}
// 	return (NULL);
// }

// char	*ft_strncpy(char *dst, const char *src, size_t len)
// {
// 	char *temp;

// 	temp = dst;
// 	while (len > 0 && *src)
// 	{
// 		*temp++ = *src++;
// 		len--;
// 	}
// 	while (len > 0)
// 	{
// 		*temp++ = '\0';
// 		len--;
// 	}
// 	return (dst);
// }

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	n;
	int	i;

	n = ft_strlen(little);
	printf("len little %zu\n", n);
	if (n == 0)
		return ((char*)big);
	i = 0;
	while (i <= (int)(len - n))
	{
		if (ft_strncmp(big, little, n) == 0)
		{
			printf("ICI%d\n", i);
			return ((char*)big);
		}
		else
		{
			printf("LA%d\n", i);
			big++;
			i++;
		}
	}
	return (NULL);
}

int	main()
{
	char 	*src;
	char 	*dst;
	size_t	len;
	
	src = ft_strdup("Je cherche aiguille dans cette chaine");
	dst = ft_strdup("aiguille");
	printf("   big : %s\n", src);
	printf("little : %s\n", dst);
	len = 5;
	printf(MAGENTA"     moi : %s\n", ft_strnstr(src, dst, len));
	printf("la vraie : %s\n"RESET, strnstr(src, dst, len));

	return (0);
}
