/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strlcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:39:54 by sfranc            #+#    #+#             */
/*   Updated: 2016/11/14 17:39:55 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

#define RESET "\033[0m"
#define BOLDBLUE "\033[1m\033[34m"      /* Bold Blue */
#define MAGENTA "\033[35m"      /* Magenta */

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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;
	size_t	j;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);

	if (size > len_dst)
	{
		printf("if\n");
		i = len_dst;
		printf("i :%zu\n", i);
		j = 0;
		while (i < size - 1)
		{
			dst[i] = src[j];
			printf("dst %c\n", dst[i]);
			i++;
			j++;
		}
		dst[i]= '\0';
		return (len_dst + len_src);
	}
	else
	{
		// printf("else\n");
		// printf("len_src :%zu\n", len_src);
		return (len_src + size);
	}
}

int main()
{
	char	dst[100] = "Hello";
	char	src[100] = "World !!!";
	char	dst2[100] = "Hello";
	char	src2[100] = "World !!!";
	size_t	len;

	len = 15;
		printf("dst : %s\n", dst);
		printf("dst2 : %s\n", dst2);
		printf(BOLDBLUE "size : %zu\n" RESET, len);
		printf(MAGENTA"la vraie : %zu\tdst : %s\n"RESET, strlcat(dst, src, len), dst);
		printf("     moi : %zu\t", ft_strlcat(dst2, src2, len));
		printf("dst : %s\n", dst2);
	return (0); 
}