/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 21:41:35 by sfranc            #+#    #+#             */
/*   Updated: 2017/05/26 16:45:42 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>
#include <ctype.h>
#include <fcntl.h>

#define RESET "\033[0m"
#define BOLDBLUE "\033[1m\033[34m"      /* Bold Blue */
// #define MAGENTA "\033[35m"      /* Magenta */

void	ft_toupper2(char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

void	ft_toupper3(unsigned int i, char *c)
{
	if (i % 2 == 0)
	{
		if (*c >= 'a' && *c <= 'z')
			*c = *c - 32;
	}
}

char	ft_toupper4(char c)
{
	if (c == 'T')
		c = 't';
	return(c);
}

char	ft_toupper5(unsigned int i, char c)
{
	if (i % 2 == 0)
	{
		if (c == 'T')
			c = 't';
	}
	return (c);
}

t_list	*ft_lstmap_test(t_list *list)
{
	list->content = ft_strjoin(list->content, "PASSAGE");
	return (list);
}

int		main(void)
{
	char	*src;
	char	*dst;
	void	*str;
	char 	**tab;
	int		*tab_int1;
	int		*tab_int2;
 	int		c;
	int 	i;
	int 	n;
	int 	base;
 	size_t	len;
 	t_list	**list;
 	t_list	*list2;
 	t_list	*elem1;
 	t_list	*elem2;
 	t_list	*elem3;
 	t_list 	*elem4;

 	src = NULL;
	dst = NULL;
	str = NULL;
	tab = NULL;
	tab_int1 = ft_range(1, 5);
	tab_int2 = ft_range(1, 5);
 	c = 'a';
 	i = 0;
	n = 1;
	len = 1;
	list = NULL;
	list2 = NULL;
	elem1 = NULL;
	elem2 = NULL;
	elem3 = NULL;
	elem4 = NULL;

// // FT MEMSET ===================================================================
 // 	printf(BOLDBLUE "======== ft_memset ===========================================\n" RESET);
	// src = ft_strdup("AaaaaAaaaaAaaaa");
	// c = 'b';
	// printf(MAGENTA "\nTest char + len inf ou =\n" RESET);
	// printf("%s\n", src);
	// len = 5;
	// printf("     moi : %s\n", ft_memset(src, c, len));
	// src = ft_strdup("AaaaaAaaaaAaaaa");
	// printf("la vraie : %s\n", memset(src, c, len));
	// src = ft_strdup("AaaaaAaaaaAaaaa");

	// printf(MAGENTA "\nTest char + len sup\n"RESET);
	// len = 15;
	
	// printf("%s\n", src);
	// printf("     moi : %s\n", ft_memset(src, c, len));
	// src = ft_strdup("AaaaaAaaaaAaaaa");
	// printf("la vraie : %s\n", memset(src, c, len));
	// src = ft_strdup("AaaaaAaaaaAaaaa");	

	// printf(MAGENTA "\nTest char + c vide\n" RESET);
	// c = 0;
	// printf("%s\n", src);
	// printf("     moi : %s\n", ft_memset(src, c, len));
	// src = ft_strdup("AaaaaAaaaaAaaaa");
	// printf("la vraie : %s\n", memset(src, c, len));
	// src = ft_strdup("AaaaaAaaaaAaaaa");

	// printf(MAGENTA "\nTest int\n" RESET);
	// c = 0;
	// len = 16;
	// i = 0;
	// tab_int1 = ft_range(1, 5);
	// while (i < 4)
	// {
	// 	printf("%d", tab_int1[i]);
	// 	i++;
	// }
	// printf("\n     moi :\n");
	// ft_memset(tab_int1, c, len);
	// i = 0;
	// while (i < 4)
	// {
	// 	printf("%d\n", tab_int1[i]);
	// 	i++;
	// }
	// printf("\nla vraie :\n");
	// tab_int2 = ft_range(1, 5);
	// memset(tab_int2, c, len);
	// i = 0;
	// while (i < 4)
	// {
	// 	printf("%d\n", tab_int2[i]);
	// 	i++;
	// }
	
// // FT BZERO ====================================================================
// 	printf(BOLDBLUE "======== ft_bzero ============================================\n" RESET);

// 	src = ft_strdup("AaaaaAaaaaAaaaa");
// 	n = 19;
// 	printf(MAGENTA "\nTest char\n" RESET);
// 	printf("%s\n", src);
// 	ft_bzero(src, n);
// 	printf("     moi : %s\n", src);
// 	src = ft_strdup("AaaaaAaaaaAaaaa");
// 	bzero(src, n);
// 	printf("la vraie : %s\n", src);
// 	src = ft_strdup("AaaaaAaaaaAaaaa");

// 	src = ft_strdup("");
// 	n = 1;
// 	printf(MAGENTA "\nTest char chaine vide\n" RESET);
// 	printf("%s\n", src);
// 	ft_bzero(src, n);
// 	printf("     moi : %s\n", src);
// 	src = ft_strdup("");
// 	bzero(src, n);
// 	printf("la vraie : %s\n", src);
// 	src = ft_strdup("");

// 	printf(MAGENTA "\nTest tableau d'int\n" RESET);
// 	n = 16;
// 	tab_int1 = ft_range(1, 5);
// 	i = 0;
// 	while (i < 4)
// 	{
// 		printf("%d", tab_int1[i]);
// 		i++;
// 	}
// 	printf("\n     moi :\n");
// 	ft_bzero(tab_int1, n);
// 	i = 0;
// 	while (i < 4)
// 	{
// 		printf("%d\n", tab_int1[i]);
// 		i++;
// 	}
// 	printf("\nla vraie :\n");
// 	tab_int2 = ft_range(1, 5);
// 	bzero(tab_int2, n);
// 	i = 0;
// 	while (i < 4)
// 	{
// 		printf("%d\n", tab_int2[i]);
// 		i++;
// 	}

// // FT MEMCPY ===================================================================
// 	printf(BOLDBLUE "======== ft_memcpy ===========================================\n" RESET);

// 	printf(MAGENTA "\nTest char EASY\n" RESET);
// 	src = ft_strdup("Hello World !");
// 	dst = ft_strdup("");
// 	printf("src = %s\n", src);
// 	n = ft_strlen(src);
// 	printf("dst = %s\n", dst);
// 	printf("la vraie : %s\n", memcpy(dst, src, n));
// 	dst = ft_strdup("");
// 	printf("     moi : %s\n", ft_memcpy(dst, src, n));

// 	printf(MAGENTA "\nTest char dst < src\n" RESET);
// 	src = ft_strdup("");
// 	dst = ft_strdup("Chaine dest non vide");
// 	printf("src = %s\n", src);
// 	n = ft_strlen(src);
// 	printf("dst = %s\n", dst);
// 	printf("la vraie : %s\n", memcpy(dst, src, n));
// 	dst = ft_strdup("Chaine dest non vide");
// 	printf("     moi : %s\n", ft_memcpy(dst, src, n));
	
// 	// printf(MAGENTA "\nTest char OVERLAP\n" RESET);
// 	// src = ft_strdup("Hello World !");
// 	// dst = src + 4;
// 	// n = ft_strlen(src);
// 	// printf("src = %s\n", src);
// 	// printf("dst = %s\n", dst);
// 	// printf("la vraie : %s\n", memcpy(dst, src, n));
// 	// src = ft_strdup("Hello World !");
// 	// dst = src + 4;
// 	// n = ft_strlen(src);
// 	// printf("     moi : %s\n", ft_memcpy(dst, src, n));


// // FT MEMCCPY ==================================================================
// 	printf(BOLDBLUE "======== ft_memccpy ==========================================\n" RESET);

// 	printf(MAGENTA "\nTest char EASY avec W\n" RESET);
// 	src = ft_strdup("Hello World !");
// 	printf("src = %s\n", src);
// 	dst = ft_strdup("1233456789101");
// 	printf("dst = %s\n", dst);
// 	c ='W';
// 	len = ft_strlen(src);
// 	printf("la vraie : %s\n", memccpy(dst, src, c, len));
// 	dst = ft_strdup("1233456789101");
// 	printf("     moi : %s\n", ft_memccpy(dst, src, c, len));

// 	printf(MAGENTA "\nTest char EASY avec A\n" RESET);
// 	src = ft_strdup("Hello World !");
// 	printf("src = %s\n", src);
// 	dst = ft_strdup("1233456789101");
// 	printf("dst = %s\n", dst);
// 	c ='A';
// 	len = ft_strlen(src);
// 	printf("la vraie : %s\n", memccpy(dst, src, c, len));
// 	dst = ft_strdup("1233456789101");
// 	printf("     moi : %s\n", ft_memccpy(dst, src, c, len));

// 	printf(MAGENTA "\nTest char src vide\n" RESET);
// 	src = ft_strdup("");
// 	printf("src = %s\n", src);
// 	dst = ft_strdup("1233456789101");
// 	printf("dst = %s\n", dst);
// 	c ='W';
// 	len = ft_strlen(src);
// 	printf("la vraie : %s\n", memccpy(dst, src, c, len));
// 	dst = ft_strdup("1233456789101");
// 	printf("     moi : %s\n", ft_memccpy(dst, src, c, len));

// 	printf(MAGENTA "\nTest char dst vide CHECK adresses\n" RESET);
// 	src = ft_strdup("Hello World !");
// 	printf("src = %s\n", src);
// 	dst = ft_strdup("");
// 	printf(" add dst = %p\n", &dst);
// 	c ='W';
// 	len = ft_strlen(src);
// 	memccpy(dst, src, c, len);
// 	printf("la vraie : add dst = %p\n", &dst);
// 	dst = ft_strdup("");
// 	ft_memccpy(dst, src, c, len);
// 	printf("     moi : add dst = %p\n", &dst);

// 	printf(MAGENTA "\nTest char dst & src vide\n" RESET);
// 	src = ft_strdup("");
// 	printf("src = %s\n", src);
// 	dst = ft_strdup("");
// 	printf("dst = %s\n", dst);
// 	c ='W';
// 	len = ft_strlen(src);
// 	printf("la vraie : %s\n", memccpy(dst, src, c, len));
// 	dst = ft_strdup("");
// 	printf("     moi : %s\n", ft_memccpy(dst, src, c, len));

// 	printf(MAGENTA "\nTest char len >\n" RESET);
// 	src = ft_strdup("Hello World !");
// 	printf("src = %s\n", src);
// 	dst = ft_strdup("1233456789101");
// 	printf("dst = %s\n", dst);
// 	c ='W';
// 	len = 0;
// 	while (len++ < 30)
// 	{
// 		dst = ft_strdup("1233456789101");
// 		printf("la vraie : %s\n", memccpy(dst, src, c, len));
// 		free(dst);
// 		dst = ft_strdup("1233456789101");
// 		printf("     moi : %s\n", ft_memccpy(dst, src, c, len));
// 		free(dst);
// 	}

// 	printf(MAGENTA "\nTest char 42FC\n" RESET);
// 	src = ft_strdup("string with\200inside !");
// 	printf("src = %s\n", src);
// 	dst = ft_strdup("abcdefghijklmnopqrstuvwxyz");
// 	printf("dst = %s\n", dst);
// 	c = 200;
// 	len = 21;
// 	printf("la vraie : %s\n", memccpy(dst, src, c, len));
// 	dst = ft_strdup("1233456789101");
// 	printf("     moi : %s\n", ft_memccpy(dst, src, c, len));

// // FT MEMMOVE ==================================================================
// 	printf(BOLDBLUE "======== ft_memmove ==========================================\n" RESET);

// 	printf(MAGENTA "\nTest char EASY\n" RESET);
// 	src = ft_strdup("Hello World !");
// 	printf("src = %s\n", src);
// 	len = ft_strlen(src);
// 	dst = ft_strdup("1233456789101");
// 	printf("dst = %s\n", dst);
// 	dst = memmove(dst, src, len);
// 	printf("la vraie : %s\n", dst);
// 	dst = ft_strdup("1233456789101");
// 	dst = ft_memmove(dst, src, len);
// 	printf("     moi : %s\n", dst);
	
// 	printf(MAGENTA "\nTest char dst plus longue\n" RESET);
// 	src = ft_strdup("Hello World !");
// 	printf("src = %s\n", src);
// 	len = ft_strlen(src);
// 	dst = ft_strdup("chaine non vide chaine non vide");
// 	printf("dst = %s\n", dst);
// 	dst = memmove(dst, src, len);
// 	printf("la vraie : %s\n", dst);
// 	dst = ft_strdup("chaine non vide chaine non vide");
// 	dst = ft_memmove(dst, src, len);
// 	printf("     moi : %s\n", dst);

// 	printf(MAGENTA "\nTest char src vide mais pas dst\n" RESET);
// 	src = ft_strdup("");
// 	printf("src = %s\n", src);
// 	len = ft_strlen(src);
// 	dst = ft_strdup("chaine non vide chaine non vide");
// 	printf("dst = %s\n", dst);
// 	dst = memmove(dst, src, len);
// 	printf("la vraie : %s\n", dst);
// 	dst = ft_strdup("chaine non vide chaine non vide");
// 	dst = ft_memmove(dst, src, len);
// 	printf("     moi : %s\n", dst);

// 	printf(MAGENTA "\nTest char len >\n" RESET);
// 	src = ft_strdup("Hello World !");
// 	printf("src = %s\n", src);
// 	len = ft_strlen(src) + 10;
// 	dst = ft_strdup("1233456789101");
// 	printf("dst = %s\n", dst);
// 	dst = memmove(dst, src, len);
// 	printf("la vraie : %s\n", dst);
// 	dst = ft_strdup("1233456789101");
// 	dst = ft_memmove(dst, src, len);
// 	printf("     moi : %s\n", dst);

// 	printf(MAGENTA "\nTest char OVERLAP\n" RESET);
// 	src = ft_strdup("Hello World !");
// 	printf("src = %s\n", src);
// 	len = ft_strlen(src) + 10;
// 	dst = src + 3;
// 	printf("dst = %s\n", dst);

// 	dst = memmove(dst, src, len);
// 	printf("la vraie : %s\n", dst);

// 	src = ft_strdup("Hello World !");
// 	dst = src + 3;
// 	dst = ft_memmove(dst, src, len);
// 	printf("     moi : %s\n", dst);

// 	printf(MAGENTA "\nTest char OVERLAP\n" RESET);
// 	src = ft_strdup("Hello World !");
// 	printf("src = %s\n", src);
// 	len = ft_strlen(src) + 10;
// 	dst = src - 3;
// 	printf("dst = %s\n", dst);

// 	dst = memmove(dst, src, len);
// 	printf("la vraie : %s\n", dst);

// 	src = ft_strdup("Hello World !");
// 	dst = src - 3;
// 	dst = ft_memmove(dst, src, len);
// 	printf("     moi : %s\n", dst);

// // FT MEMCHR ===================================================================
// 	printf(BOLDBLUE "======== ft_memchr ===========================================\n" RESET);

// 	printf(MAGENTA "\nTest char EASY\n" RESET);
// 	src = ft_strdup("Hello World !");
// 	c = 'W';
// 	len = ft_strlen(src);
// 	printf("src = %s\n", src);
// 	printf("add src = %p\n", &src);
// 	printf("la vraie : %s\n", memchr(src, c , len));
// 	printf("add src = %p\n", &src);
// 	src = ft_strdup("Hello World !");
// 	printf("     moi : %s\n", ft_memchr(src, c , len));
// 	printf("add src = %p\n", &src);

// 	printf(MAGENTA "\nTest char pas de chr dans src\n" RESET);
// 	src = ft_strdup("Hello World !");
// 	c = 'A';
// 	len = ft_strlen(src);
// 	printf("src = %s\n", src);
// 	printf("add src = %p\n", &src);
// 	printf("la vraie : %s\n", memchr(src, c , len));
// 	src = ft_strdup("Hello World !");
// 	printf("     moi : %s\n", ft_memchr(src, c , len));

// 	printf(MAGENTA "\nTest char len < au chr cherché\n" RESET);
// 	src = ft_strdup("Hello World !");
// 	c = 'W';
// 	len = ft_strlen(src) - 12;
// 	printf("src = %s\n", src);
// 	printf("add src = %p\n", &src);
// 	printf("la vraie : %s\n", memchr(src, c , len));
// 	printf("add src = %p\n", &src);
// 	src = ft_strdup("Hello World !");
// 	printf("     moi : %s\n", ft_memchr(src, c , len));
// 	printf("add src = %p\n", &src);

// // FT MEMCMP ===================================================================
// 	printf(BOLDBLUE "======== ft_memcmp ===========================================\n" RESET);

// 	printf(MAGENTA "\nTest char EASY\n" RESET);
// 	src = ft_strdup("");
// 	dst = ft_strdup("");
// 	len = ft_strlen(src);
// 	printf("src = %s\n", src);
// 	printf("dst = %s\n", dst);
// 	printf("la vraie : %d\n", memcmp(src, dst, len));
// 	printf("     moi : %d\n", ft_memcmp(src, dst, len));


// // FT ISALPHA ===================================================================
// 	printf(BOLDBLUE "======== ft_isalpha ===========================================\n" RESET);

// 	printf(MAGENTA "\nTest ASCII 0 - 127\n" RESET);
// 	c = 0;
// 	while (c++ < 128)
// 	{
// 		printf(BOLDBLUE "%c" RESET, c);
// 		printf(" | la vraie : %d", isalpha(c));
// 		printf("    | moi : %d\n", ft_isalpha(c));
// 	}

// // FT ISDIGIT ===================================================================
// 	printf(BOLDBLUE "======== ft_isdigit ===========================================\n" RESET);

// 	printf(MAGENTA "\nTest ASCII 0 - 127\n" RESET);
// 	c = 0;
// 	while (c++ < 128)
// 	{
// 		printf(BOLDBLUE "%c" RESET, c);
// 		printf(" | la vraie : %d", isdigit(c));
// 		printf("    | moi : %d\n", ft_isdigit(c));
// 	}

// // FT ISALNUM ===================================================================
// 	printf(BOLDBLUE "======== ft_isalnum ===========================================\n" RESET);

// 	printf(MAGENTA "\nTest ASCII 0 - 127\n" RESET);
// 	c = 0;
// 	while (c++ < 128)
// 	{
// 		printf(BOLDBLUE "%c" RESET, c);
// 		printf(" | la vraie : %d", isalnum(c));
// 		printf("    | moi : %d\n", ft_isalnum(c));
// 	}

// // FT ISASCII ===================================================================
// 	printf(BOLDBLUE "======== ft_isascii ===========================================\n" RESET);

// 	printf(MAGENTA "\nTest avec random\n" RESET);
// 	i = 0;
// 	while (i++ < 10)
// 	{
// 		c = rand() % 300;
// 		printf(BOLDBLUE "%d" RESET, c);
// 		printf(" | la vraie : %d", isascii(c));
// 		printf("    | moi : %d\n", ft_isascii(c));
// 	}

// // FT ISPRINT ===================================================================
// 	printf(BOLDBLUE "======== ft_isprint ===========================================\n" RESET);

// 	printf(MAGENTA "\nTest ASCII 0 - 127\n" RESET);
// 	c = 0;
// 	while (c++ < 127)
// 	{
// 		printf(BOLDBLUE "%d" RESET, c);
// 		printf(BOLDBLUE " %c" RESET, c);
// 		printf(" | la vraie : %d", isprint(c));
// 		printf("    | moi : %d\n", ft_isprint(c));
// 	}

// // FT TOUPPER ===================================================================
// 	printf(BOLDBLUE "======== ft_toupper ===========================================\n" RESET);

// 	printf(MAGENTA "\nTest ASCII 0 - 127\n" RESET);
// 	c = 0;
// 	while (c++ < 127)
// 	{
// 		printf(BOLDBLUE "%d" RESET, c);
// 		printf(BOLDBLUE " %c" RESET, c);
// 		printf(" | la vraie : %d", toupper(c));
// 		printf("    | moi : %d\n", ft_toupper(c));
// 	}

// // FT TOLOWER ===================================================================
// 	printf(BOLDBLUE "======== ft_tolower ===========================================\n" RESET);

// 	printf(MAGENTA "\nTest ASCII 0 - 127\n" RESET);
// 	c = 0;
// 	while (c++ < 127)
// 	{
// 		printf(BOLDBLUE "%d" RESET, c);
// 		printf(BOLDBLUE " %c" RESET, c);
// 		printf(" | la vraie : %d", tolower(c));
// 		printf("    | moi : %d\n", ft_tolower(c));
// 	}

// FT ATOI ===================================================================
	// printf(BOLDBLUE "======== ft_atoi ===========================================\n" RESET);

	// src = ft_strdup(" 123NHOK");
	// i = 0;
	// while (i <= 32)
	// {
	// 	src[0] = i;
	// 	printf("%d", i);
	// 	printf("  |  la vraie : %d", atoi(src));
	// 	printf("  | moi : %d\n", ft_atoi(src));
	// 	i++;
	// }
	// src[0] = 128;
	// printf("%d", i);
	// printf("  |  la vraie : %d", atoi(src));
	// printf("  | moi : %d\n", ft_atoi(src));

	// printf(MAGENTA "\nTest vide\n" RESET);
	// printf("la vraie : %d\n", atoi(""));
	// printf("     moi : %d\n", ft_atoi(""));

	// printf(MAGENTA "\nTest 078\n" RESET);
	// printf("la vraie : %d\n", atoi("078"));
	// printf("     moi : %d\n", ft_atoi("078"));

	// printf(MAGENTA "\nTest aecd123\n" RESET);
	// printf("la vraie : %d\n", atoi("aecd123"));
	// printf("     moi : %d\n", ft_atoi("aecd123"));

	// printf(MAGENTA "\nTest \t\n 123\n" RESET);
	// printf("la vraie : %d\n", atoi("\t\n 123"));
	// printf("     moi : %d\n", ft_atoi("\t\n 123"));

	// printf(MAGENTA "\nTest \t\n +123\n" RESET);
	// printf("la vraie : %d\n", atoi("\t\n +123"));
	// printf("     moi : %d\n", ft_atoi("\t\n +123"));

	// printf(MAGENTA "\nTest \t\n +     123\n" RESET);
	// printf("la vraie : %d\n", atoi("\t\n +     123"));
	// printf("     moi : %d\n", ft_atoi("\t\n +     123"));

	// printf(MAGENTA "Test 25 \t\n\25 -123\n" RESET);
	// printf("0 : %s\n", "\48");
	// printf("la vraie : %d\n", atoi("\t\n\25 -123"));
	// printf("     moi : %d\n", ft_atoi("\t\n\25 -123"));

	// printf(MAGENTA "\nTest \t\n -   123\n" RESET);
	// printf("la vraie : %d\n", atoi("\t\n -   123"));
	// printf("     moi : %d\n", ft_atoi("\t\n -   123"));

	// printf(MAGENTA "\nTest qwertyui\n" RESET);
	// printf("la vraie : %d\n", atoi("qwertyui"));
	// printf("     moi : %d\n", ft_atoi("qwertyui"));

	// printf(MAGENTA "\nTest +-156\n" RESET);
	// printf("la vraie : %d\n", atoi("+-156"));
	// printf("     moi : %d\n", ft_atoi("+-156"));

	// printf(MAGENTA "\nTest -+156\n" RESET);
	// printf("la vraie : %d\n", atoi("-+156"));
	// printf("     moi : %d\n", ft_atoi("-+156"));

	// printf(MAGENTA "\nTest ++156\n" RESET);
	// printf("la vraie : %d\n", atoi("++156"));
	// printf("     moi : %d\n", ft_atoi("++156"));

	// printf(MAGENTA "\nTest -ert156\n" RESET);
	// printf("la vraie : %d\n", atoi("-ert156"));
	// printf("     moi : %d\n", ft_atoi("-ert156"));

	// printf(MAGENTA "\nTest 156ert\n" RESET);
	// printf("la vraie : %d\n", atoi("156ert"));
	// printf("     moi : %d\n", ft_atoi("156ert"));

	// printf(MAGENTA "\nTest 156ert 156ert\n" RESET);
	// printf("la vraie : %d\n", atoi("156ert 156ert"));
	// printf("     moi : %d\n", ft_atoi("156ert 156ert"));

	// printf(MAGENTA "\nTest -156ert\n" RESET);
	// printf("la vraie : %d\n", atoi("-156ert"));
	// printf("     moi : %d\n", ft_atoi("-156ert"));

	// printf(MAGENTA "\nTest --156ert\n" RESET);
	// printf("la vraie : %d\n", atoi("--156ert"));
	// printf("     moi : %d\n", ft_atoi("--156ert"));

	// printf(MAGENTA "\nTest int min -2147483648\n" RESET);
	// printf("la vraie : %d\n", atoi("-2147483648"));
	// printf("     moi : %d\n", ft_atoi("-2147483648"));

	// printf(MAGENTA "\nTest int max 2147483647\n" RESET);
	// printf("la vraie : %d\n", atoi("2147483647"));
	// printf("     moi : %d\n", ft_atoi("2147483647"));

	// printf(MAGENTA "\nTest 0\n" RESET);
	// printf("la vraie : %d\n", atoi("0"));
	// printf("     moi : %d\n", ft_atoi("0"));

	// printf(MAGENTA "\nTest overflow 21474836470\n" RESET);
	// printf("la vraie : %d\n", atoi("21474836470"));
	// printf("     moi : %d\n", ft_atoi("21474836470"));


// // FT STRCPY ===================================================================
// 	printf(BOLDBLUE "======== ft_strcpy ===========================================\n" RESET);

// 	printf(MAGENTA "\nTest char EASY\n" RESET);
// 	src = ft_strdup("Hello World !");
// 	dst = ft_strdup("                ");
// 	printf("src = %s\n", src);
// 	printf("la vraie : %s\n", strcpy(dst, src));
// 	free(dst);
// 	dst = ft_strdup("                ");
// 	printf("     moi : %s\n", ft_strcpy(dst, src));

// // FT STRNCPY ===================================================================
// 	printf(BOLDBLUE "======== ft_strncpy ===========================================\n" RESET);

// 	printf(MAGENTA "\nTest char EASY\n" RESET);
// 	src = ft_strdup("Hello World !");
// 	dst = ft_strdup("                ");
// 	len = 5;
// 	printf("src = %s\n", src);
// 	printf("la vraie : %s\n", strncpy(dst, src, len));
// 	free(dst);
// 	dst = ft_strdup("                ");
// 	printf("     moi : %s\n", ft_strncpy(dst, src, len));

// // FT STRCAT ===================================================================
// 	printf(BOLDBLUE "======== ft_strcat ===========================================\n" RESET);
	
// 	char	s1[100] = "Hello World !";
// 	char	s2[100] = "Hello World !";
// 	char	s3[100] = "How are you ?";
	
// 	printf(MAGENTA "\nTest char EASY\n" RESET);
// 	printf("s1 = %s\n", s1);
// 	printf("s2 = %s\n", s3);
// 	printf("la vraie : %s\n", strcat(s1, s3));
//  	printf("     moi : %s\n", ft_strcat(s2, s3));

// // FT STRNCAT ===================================================================
// 	printf(BOLDBLUE "======== ft_strncat ===========================================\n" RESET);
	
// 	char	s1[100] = "Hello World !";
// 	char	s2[100] = "Hello World !";
// 	char	s3[100] = "How are you ?";
	
// 	len = 1;
// 	printf(MAGENTA "\nTest char EASY\n" RESET);
// 	printf("s1 = %s\n", s1);
// 	printf("s2 = %s\n", s3);
// 	printf("la vraie : %s\n", strncat(s1, s3, len));
//  	printf("     moi : %s\n", ft_strncat(s2, s3, len));

// FT STRLCAT ===================================================================
	// printf(BOLDBLUE "======== ft_strlcat ===========================================\n" RESET);
	
	// printf(MAGENTA "\nTest char EASY\n" RESET);
	// len = 0;
	// while (len < 17)
	// {
	// 	dst = ft_strdup("");
	// 	src = ft_strdup("World !!");
	// 	printf(BOLDBLUE "size : %zu\n" RESET, len);
	// 	printf("la vraie : %zu\tdst : %s\n", strlcat(dst, src, len), dst);
	// 	free(dst);
	// 	free(src);
	// 	dst = ft_strdup("");
	// 	src = ft_strdup("World !!");
	// 	printf("     moi : %zu\tdst : %s\n", ft_strlcat(dst, src, len), dst);
	// 	free(dst);
	// 	free(src);
	// 	len++;
	// }

// FT STRCHR ===================================================================
	// printf(BOLDBLUE "======== ft_strchr ===========================================\n" RESET);
	
	// printf(MAGENTA "\ntest on cherche ici un : u\n" RESET);
	// src = ft_strdup("test on cherche ici un : u");
	// c = 'u';
	// printf("la vraie : %s\n", strchr(src, c));
	// printf("     moi : %s\n", ft_strchr(src, c));

	// printf(MAGENTA "\ntest on cherche ici un : a\n" RESET);
	// src = ft_strdup("test on cherche ici un...");
	// c = 'a';
	// printf("la vraie : %s\n", strchr(src, c));
	// printf("     moi : %s\n", ft_strchr(src, c));

	// printf(MAGENTA "\ntest 0 \n" RESET);
	// src = ft_strdup("\0");
	// c = '\0';
	// printf("la vraie : %s\n", strchr(src, c));
	// printf("     moi : %s\n", ft_strchr(src, c));

	// printf(MAGENTA "\ntest boucle acsii\n" RESET);
	// src = ft_strdup("1");
	// i = 0;
	// while (i < 32)
	// {
	// 		src[0] = 0;
	// 		c = i;
	// 		printf("la vraie : %s\t", strchr(src, c));
	// 		printf("| moi : %s\n", ft_strchr(src, c));
	// 		i++;
	// }

// FT STRRCHR ===================================================================
	// printf(BOLDBLUE "======== ft_strrchr ===========================================\n" RESET);
	
	// printf(MAGENTA "\ntest on cherche ici un le dernier e\n" RESET);
	// src = ft_strdup("test on cherche ici un le dernier e");
	// c = 'o';
	// printf("la vraie : %s\n", strrchr(src, c));
	// printf("     moi : %s\n", ft_strrchr(src, c));

	// printf(MAGENTA "\ntest on cherche ici un : a\n" RESET);
	// src = ft_strdup("test on cherche ici un...");
	// c = 'a';
	// printf("la vraie : %s\n", strrchr(src, c));
	// printf("     moi : %s\n", ft_strrchr(src, c));

	// printf(MAGENTA "\ntest 0 \n" RESET);
	// src = ft_strdup("\0");
	// c = '\0';
	// printf("la vraie : %s\n", strrchr(src, c));
	// printf("     moi : %s\n", ft_strrchr(src, c));

	// printf(MAGENTA "\ntest on cherche ici zero\n" RESET);
	// src = ft_strdup("test on cherche ici zero");
	// c = 0;
	// printf("la vraie : %s\n", strrchr(src, c));
	// printf("     moi : %s\n", ft_strrchr(src, c));

// FT STRCMP ===================================================================
	// printf(BOLDBLUE "======== ft_strcmp ===========================================\n" RESET);
	
	// printf(MAGENTA "\ntest easy b vs a\n" RESET);
	// src = ft_strdup("aaaab");
	// dst = ft_strdup("aaaaa");
	// printf("la vraie : %d\n", strcmp(dst, src));
	// printf("     moi : %d\n", ft_strcmp(dst, src));

	// printf(MAGENTA "\ntest easy =\n" RESET);
	// src = ft_strdup("aaaaa");
	// dst = ft_strdup("aaaaa");
	// printf("la vraie : %d\n", strcmp(dst, src));
	// printf("     moi : %d\n", ft_strcmp(dst, src));

	// printf(MAGENTA "\ntest easy vides\n" RESET);
	// src = ft_strdup("qwe");
	// dst = ft_strdup("");
	// printf("la vraie : %d\n", strcmp(dst, src));
	// printf("     moi : %d\n", ft_strcmp(dst, src));

	// printf(MAGENTA "\ntest easy aiguille dans cette chaine\n" RESET);
	// src = ft_strdup("aiguille dans cette chaine");
	// dst = ft_strdup("aiguille");
	// printf("la vraie : %d\n", strcmp(dst, src));
	// printf("     moi : %d\n", ft_strcmp(dst, src));

// FT STRNCMP ===================================================================
	// printf(BOLDBLUE "======== ft_strncmp ===========================================\n" RESET);
	
	// printf(MAGENTA "\ntest easy boucle\n" RESET);
	// len = 0;
	// while (len < 50)
	// {
	// 	printf(BOLDBLUE"len = %zu\n"RESET, len);
	// 	src = ft_strdup("Hey Jude, don't make it eafdzbzgf");
	// 	dst = ft_strdup("Hey Jude, don't make it bad");
	// 	printf("la vraie : %d\n", strncmp(dst, src, len));
	// 	printf("     moi : %d\n", ft_strncmp(dst, src, len));
	// 	free(src);
	// 	free(dst);
	// 	len = len + 10;
	// }

	// printf(MAGENTA "\ntest chaine vide\n" RESET);
	// len = 5;
	// printf(BOLDBLUE"len = %zu\n"RESET, len);
	// src = ft_strdup("\0");
	// dst = ft_strdup("\0");
	// printf("la vraie : %d\n", strncmp(dst, src, len));
	// printf("     moi : %d\n", ft_strncmp(dst, src, len));

// FT STRSTR ===================================================================
	// printf(BOLDBLUE "======== ft_strstr ===========================================\n" RESET);
	
	// printf(MAGENTA "\ntest premiere occurence\n" RESET);
	// src = ft_strdup("Je cherche lit littl little little dans big");
	// dst = ft_strdup("little");
	// printf("   big : %s\n", src);
	// printf("little : %s\n", dst);
	// printf("\n     moi : %s\n", ft_strstr(src, dst));
	// printf("la vraie : %s\n", strstr(src, dst));
	// free(src);
	// free(dst);

	// printf(MAGENTA "\ntest little vide\n" RESET);
	// src = ft_strdup("Je cherche lit littl little little dans big");
	// dst = ft_strdup("");
	// printf("   big : %s\n", src);
	// printf("little : %s\n", dst);
	// printf("\n     moi : %s\n", ft_strstr(src, dst));
	// printf("la vraie : %s\n", strstr(src, dst));
	// free(src);
	// free(dst);

	// printf(MAGENTA "\ntest big vide\n" RESET);
	// src = ft_strdup("");
	// dst = ft_strdup("little");
	// printf("   big : %s\n", src);
	// printf("little : %s\n", dst);
	// printf("\n     moi : %s\n", ft_strstr(src, dst));
	// printf("la vraie : %s\n", strstr(src, dst));
	// free(src);
	// free(dst);

	// printf(MAGENTA "\ntest little plus grande\n" RESET);
	// src = ft_strdup("little");
	// dst = ft_strdup("little little dans big");
	// printf("   big : %s\n", src);
	// printf("little : %s\n", dst);
	// printf("\n     moi : %s\n", ft_strstr(src, dst));
	// printf("la vraie : %s\n", strstr(src, dst));
	// free(src);
	// free(dst);

// FT STRNSTR ===================================================================
	
	// char buf[10];

	// ft_bzero(buf, 10);
	// ft_strcpy(buf, "un deux 9");
	// buf[9] = '6';
	// buf[1] = 0;
	// printf("     moi : %s\n", ft_strnstr(buf, "deux", 10));
	// printf("la vraie : %s\n", strnstr(buf, "deux", 10));

	// printf(BOLDBLUE "======== ft_strnstr ===========================================\n" RESET);
	
	// printf(MAGENTA "\ntest premiere occurence\n" RESET);
	// len = 0;
	// while (len <= 10)
	// {
	// 	printf(BOLDBLUE"%zu\n"RESET, len);
	// 	src = ft_strdup("little little dans big");
	// 	dst = ft_strdup("little");
	// 	printf("     moi : %s\n", ft_strnstr(src, dst, len));
	// 	printf("la vraie : %s\n", strnstr(src, dst, len));
	// 	free(src);
	// 	free(dst);
	// 	len++;
	// }
	
	// printf(MAGENTA "\ntest premiere occurence\n" RESET);
	// len = 0;
	// while (len <= 50)
	// {
	// 	printf(BOLDBLUE"%zu\n"RESET, len);
	// 	src = ft_strdup("");
	// 	dst = ft_strdup("little_little");
	// 	printf("     moi : %s\n", ft_strnstr(src, dst, len));
	// 	printf("la vraie : %s\n", strnstr(src, dst, len));
	// 	free(src);
	// 	free(dst);
	// 	len++;
	// }

	// printf(MAGENTA "\ntest empty\n" RESET);
	// src = ft_strdup("");
	// dst = ft_strdup("");
	// printf("     moi : %s\n", ft_strnstr(src, dst, len));
	// printf("la vraie : %s\n", strnstr(src, dst, len));
	// free(src);
	// free(dst);

// FT MEMALLOC ===================================================================
	// printf(BOLDBLUE "======== ft_memalloc ===========================================\n" RESET);
	
	// printf(MAGENTA "\ntest\n" RESET);
	// len = 5;
	// src = ft_memalloc(len);
	// while (i <= 4)
	// {
	// 	printf("%c\n", src[i]);
	// 	i++;
	// }
	// printf("end.\n");	

// FT MEMDEL ===================================================================
	// printf(BOLDBLUE "======== ft_memdel ===========================================\n" RESET);
	
	// printf(MAGENTA "\ntest\n" RESET);
	// str = ft_strdup("Test");
	// printf("str avant : %s\n", str);
	// ft_memdel(&str);
	// printf("str après : %s\n", str);
	// free(str);

	// printf(MAGENTA "\ntest pointeur NULL\n" RESET);
	// str = NULL;
	// printf("str avant : %s\n", str);
	// ft_memdel(&str);
	// printf("str après : %s\n", str);
	// free(str);

// FT STRNEW ===================================================================
	// printf(BOLDBLUE "======== ft_strnew ===========================================\n" RESET);
	
	// printf(MAGENTA "\ntest\n" RESET);
	// len = 1;
	// src = ft_strdup("\0");
	// printf("%s\n", src);
	// src = ft_strnew(len);
	// i = 0;
	// while (*src)
	// {
	// 	printf("%d\n", (int)(src[i]));
	// 	i++;
	// }
	// printf("end.\n");

// FT STRDEL ===================================================================
	// printf(BOLDBLUE "======== ft_strdel ===========================================\n" RESET);
	
	// printf(MAGENTA "\ntest\n" RESET);
	// src = ft_strdup("Test");
	// printf("src avant : %s\n", src);
	// ft_strdel(&src);
	// printf("src après : %s\n", src);
	// free(src);

	// printf(MAGENTA "\ntest pointeur NULL\n" RESET);
	// src = NULL;
	// printf("src avant : %s\n", src);
	// ft_strdel(&src);
	// printf("src après : %s\n", src);
	// free(src);	

// FT STRCLR ===================================================================
	// printf(BOLDBLUE "======== ft_strclr ===========================================\n" RESET);
	
	// printf(MAGENTA "\ntest\n" RESET);
	// src = ft_strdup("Test test test");
	// c = (int)ft_strlen(src);
	// printf("len src %d\n", c);
	// printf("src avant : %s\n", src);
	// ft_strclr(src);
	// printf("src après :\n");
	// i = 0;
	// while (i < c)
	// {
	// 	printf("%d\t %d\n", i, (int)(src[i]));
	// 	i++;
	// }	

	// printf(MAGENTA "\ntest pointeur NULL\n" RESET);
	// src = NULL;
	// printf("src avant : %s\n", src);
	// printf("src avant : %p\n", src);
	// ft_strclr(src);
	// printf("src après : %s\n", src);
	// printf("src après : %p\n", src);

// LES PUT ===================================================================
	// printf(BOLDBLUE "======== ft_putnbr & ft_putchar ===========================================\n" RESET);

	// printf("\nft_putnbr & ft_putchar\n");
	// n = 2147483647;
	// ft_putnbr(n);
	// ft_putchar('\n');
	// n = 15;
	// while (n-- > 0)
	// {
	// 	ft_putnbr(n);
	// 	ft_putchar('\n');
	// }
	// n = -2147483648;
	// ft_putnbr(n);
	// ft_putchar('\n');

	// printf(BOLDBLUE "======== ft_putnbr_fd & ft_putchar_fd ===========================================\n" RESET);
	// n = 2147483647;
	// c = open("coucou.txt", O_RDWR, O_APPEND);
	// ft_putnbr_fd(n, c);
	// ft_putchar_fd('\n', c);
	// n = 15;
	// while (n-- > 0)
	// {
	// 	ft_putnbr_fd(n, c);
	// 	ft_putchar_fd('\n', c);
	// }
	// n = -2147483648;
	// ft_putnbr_fd(n, c);
	// ft_putchar_fd('\n', c);

	// printf(BOLDBLUE "======== ft_putstr & ft_putendl ===========================================\n" RESET);
	// src = ft_strdup("Une chaine passée via un pointeur");
	// ft_putstr(src);
	// ft_putchar('\n');
	// ft_putstr("Une chaine passée directement en argument");
	// ft_putchar('\n');
	// ft_putchar('\n');
	// ft_putendl(src);
	// ft_putendl("Une chaine passée directement en argument");

	// printf(BOLDBLUE "======== ft_putstr_fd & ft_putendl_fd ===========================================\n" RESET);
	// src = ft_strdup("Une chaine passée via un pointeur");
	// ft_putstr_fd(src, c);
	// ft_putchar_fd('\n', c);
	// ft_putstr_fd("Une chaine passée directement en argument", c);
	// ft_putchar_fd('\n', c);
	// ft_putchar_fd('\n', c);
	// ft_putendl_fd(src, c);
	// ft_putendl_fd("Une chaine passée directement en argument", c);

// FT ITOA ===================================================================
	// printf("======== ft_itoa ===========================================\n");

	// ft_putendl("test int size");
	// ft_putstr("n = ");
	// n = 123;
	// ft_putnbr(n);
	// ft_putchar('\n');
	// ft_putnbr(ft_intsize(n));
	// ft_putchar('\n');

	// ft_putstr("n = ");
	// n = -123;
	// ft_putnbr(n);
	// ft_putchar('\n');
	// ft_putnbr(ft_intsize(n));
	// ft_putchar('\n');

	// ft_putstr("n = ");
	// n = 0;
	// ft_putnbr(n);
	// ft_putchar('\n');
	// ft_putnbr(ft_intsize(n));
	// ft_putchar('\n');

	// ft_putstr("n = ");
	// n = 2147483647;
	// ft_putnbr(n);
	// ft_putchar('\n');
	// ft_putnbr(ft_intsize(n));
	// ft_putchar('\n');

	// ft_putstr("n = ");
	// n = -2147483648;
	// ft_putnbr(n);
	// ft_putchar('\n');
	// ft_putnbr(ft_intsize(n));
	// ft_putchar('\n');

	// ft_putendl("Test itoa");
	// n = 2147483647;
	// ft_putendl(ft_itoa(n));
	// n = -2147483648;
	// ft_putendl(ft_itoa(n));
	// n = 0;
	// ft_putendl(ft_itoa(n));
	// n = 123;
	// ft_putendl(ft_itoa(n));
	// n = -123;
	// ft_putendl(ft_itoa(n));

// FT STRITER ===================================================================
	// printf("======== ft_striter ===========================================\n");

	// ft_putendl("Test striter");
	// src = ft_strdup("Test striter");
	// ft_striter(src, &ft_toupper2);
	// ft_putendl(src);

// FT STRITERI ===================================================================
	// printf("======== ft_striteri ===========================================\n");

	// ft_putendl("Test striteri");
	// src = ft_strdup("Test striteri");
	// ft_striteri(src, &ft_toupper3);
	// ft_putendl(src);

// FT STRMAP ===================================================================
	// printf("======== ft_strmap ===========================================\n");

	// ft_putchar(ft_toupper4('T'));
	// ft_putendl("Test strmap");
	// src = ft_strdup("TTTTfdsvgfabdfTTTTTTTT");
	// ft_putendl(src);
	// dst = ft_strmap(src, &ft_toupper4);
	// ft_putendl(dst);

	// src = NULL;
	// ft_putendl(src);
	// dst = ft_strmap(src, &ft_toupper4);
	// ft_putendl(dst);

// FT STRMAPI ===================================================================
	// printf("======== ft_strmapi ===========================================\n");

	// ft_putendl("Test strmapi");
	// src = ft_strdup("TTTTfdsvgfabdfTTTTTTTT");
	// ft_putendl(src);
	// dst = ft_strmapi(src, &ft_toupper5);
	// ft_putendl(dst);

	// src = NULL;
	// ft_putendl(src);
	// dst = ft_strmapi(src, &ft_toupper5);
	// ft_putendl(dst);

// FT STREQU ===================================================================
	// printf(BOLDBLUE "======== ft_strequ ===========================================\n" RESET);
	
	// ft_putendl("Test strequ");
	// src = ft_strdup("aaaab");
	// ft_putendl(src);
	// dst = ft_strdup("aaaaa");
	// ft_putendl(dst);
	// ft_putnbr(ft_strequ(src, dst));
	// ft_putchar('\n');

	// src = ft_strdup("aaaa");
	// ft_putendl(src);
	// dst = ft_strdup("aaaaa");
	// ft_putendl(dst);
	// ft_putnbr(ft_strequ(src, dst));
	// ft_putchar('\n');

	// src = ft_strdup("");
	// ft_putendl(src);
	// dst = ft_strdup("");
	// ft_putendl(dst);
	// ft_putnbr(ft_strequ(src, dst));
	// ft_putchar('\n');

	// src = NULL;
	// ft_putendl(src);
	// dst = ft_strdup("");
	// ft_putendl(dst);
	// ft_putnbr(ft_strequ(src, dst));
	// ft_putchar('\n');

// FT STRNEQU ===================================================================
	// printf(BOLDBLUE "======== ft_strnequ ===========================================\n" RESET);

	// ft_putendl("Test strequ");
	// src = ft_strdup("aaaab");
	// ft_putendl(src);
	// dst = ft_strdup("aaaaa");
	// ft_putendl(dst);
	// len = 5;
	// ft_putnbr(ft_strnequ(src, dst, len));
	// ft_putchar('\n');

	// src = ft_strdup("aaaa");
	// ft_putendl(src);
	// dst = ft_strdup("aaaaa");
	// ft_putendl(dst);
	// len = 0;
	// while (len < 6)
	// {
	// 	ft_putnbr(ft_strnequ(src, dst, len));
	// 	ft_putchar('\n');
	// 	len++;
	// }

	// src = ft_strdup("");
	// ft_putendl(src);
	// dst = ft_strdup("");
	// ft_putendl(dst);
	// len = 5;
	// ft_putnbr(ft_strnequ(src, dst, len));
	// ft_putchar('\n');

	// src = NULL;
	// ft_putendl(src);
	// dst = ft_strdup("");
	// ft_putendl(dst);
	// len = 6;
	// ft_putnbr(ft_strnequ(src, dst, len));
	// ft_putchar('\n');

// FT STRSUB ===================================================================
	// printf(BOLDBLUE "======== ft_strsub ===========================================\n" RESET);

	// ft_putendl("Test strsub");
	// src = ft_strdup("abcdefghijklmnopqrstuvwxyz");
	// ft_putendl(src);
	// i = 12;
	// len = 3;
	// dst = ft_strsub(src, i, len);
	// ft_putendl(dst);

// FT STRJOIN ===================================================================
	// printf(BOLDBLUE "======== ft_strjoin ===========================================\n" RESET);

	// ft_putendl("Test strjoin");
	// src = ft_strdup("abcdefghijkl");
	// dst = ft_strdup("mnopqrstuvwxyz");
	// ft_putendl(src);
	// ft_putendl(dst);
	// ft_putendl(ft_strjoin(src, dst));

// FT STRTRIM ===================================================================
	// printf(BOLDBLUE "======== ft_strtrim ===========================================\n" RESET);

	// ft_putendl("Test ft_strtrim");
	// src = ft_strdup("   \t  \n\n \t\t  \n\n\n\n   \n \n \t\t\n  ");
	// ft_putendl(ft_strtrim((char const*)src));

// FT STRSPLIT ===================================================================
	// printf(BOLDBLUE "======== ft_strsplit ===========================================\n" RESET);
	
	// c = ' ';
	// ft_putendl(src);
	// ft_putendl("OK");
	// ft_putnbr(ft_nb_words(src, ' '));
	// ft_putendl("OK");
	// tab = ft_strsplit(src, ' ');
	// ft_putendl("OK");
	// i = 0;
	// while (i++ < ft_nb_words(src, ' '))
	// {
	// 	ft_putendl(*tab);
	// 	tab++;
	// }

// FT LSTNEW ===================================================================
	// ft_putendl("======= Test ft_lstnew =======================================");

	// ft_putendl("------- test content char");
	// src = ft_strdup("Un peu de contenu !");
	// len = ft_strlen(src) + 1;
	// elem1 = ft_lstnew(src, len);
	// list = &elem1;
	// free(src);
	// ft_lstprint(list);
	
	// ft_putendl("------- test content NULL");
	// src = NULL;
	// len = 1;
	// elem1 = ft_lstnew(src, len);
	// list = &elem1;
	// free(src);
	// ft_lstprint(list);

// FT LSTDELONE ===================================================================
	// ft_putendl("======= Test ft_lstdelone =======================================");

	// src = ft_strdup("Un peu de contenu !");
	// len = ft_strlen(src) + 1;
	// elem1 = ft_lstnew(src, len);
	// printf("%p\n", elem1);
	// list = &elem1;
	// free(src);
	// ft_lstprint(*list);

	// ft_putendl("------- test ft_lstdelone");
	// printf("&elem1 %p\n", &elem1);
	// printf("elem1 %p\n", elem1);
	// ft_lstdelone(&elem1, &ft_del);
	// ft_lstprint(*list);

// FT LSTADD ===================================================================
	// ft_putendl("======= Test ft_lstadd =======================================");
	
	// src = ft_strdup("ELEM 1 : Un peu de contenu !");
	// len = ft_strlen(src) + 1;
	// elem1 = ft_lstnew(src, len);
	// list = &elem1;
	// free(src);
	// ft_lstprint(*list);
	// ft_putendl(" ");
	
	// src = ft_strdup("ELEM 2 : Un peu de contenu !");
	// len = ft_strlen(src) + 1;
	// elem2 = ft_lstnew(src, len);
	// free(src);
	// ft_lstadd(list, elem2);
	// ft_lstprint(*list);
	// ft_putendl(" ");

	// src = ft_strdup("ELEM 3 : Un peu de contenu !");
	// len = ft_strlen(src) + 1;
	// elem3 = ft_lstnew(src, len);
	// free(src);
	// ft_lstadd(list, elem3);
	// ft_lstprint(*list);
	// ft_putendl(" ");

// FT LSTDEL ===================================================================
	// ft_putendl("======= Test ft_lstdel =======================================");

	// ft_lstdel(list, &ft_del);
	// ft_lstprint(*list);

// FT LSTADD_LAST ===================================================================
// 	ft_putendl("======= Test ft_lstadd_last =======================================");

// 	src = ft_strdup("ELEM 1 ");
// 	len = ft_strlen(src) + 1;
// 	elem1 = ft_lstnew(src, len);
// 	list = &elem1;
// 	free(src);
// //	ft_lstprint(*list);
// //	ft_putendl(" ");
	
// 	src = ft_strdup("ELEM 2 ");
// 	len = ft_strlen(src) + 1;
// 	elem2 = ft_lstnew(src, len);
// 	free(src);
// 	ft_lstadd_last(list, elem2);
// //	ft_lstprint(*list);
// //	ft_putendl(" ");

// 	src = ft_strdup("ELEM 3 ");
// 	len = ft_strlen(src) + 1;
// 	elem3 = ft_lstnew(src, len);
// 	free(src);
// 	ft_lstadd_last(list, elem3);

// 	src = ft_strdup("ELEM 4 ");
// 	len = ft_strlen(src) + 1;
// 	elem4 = ft_lstnew(src, len);
// 	free(src);
// 	ft_lstadd_last(list, elem4);
	
// 	ft_lstprint(*list);
// 	ft_putendl(" ");

// FT LSTLEN ===================================================================
	// ft_putendl("======= Test ft_lstlen =======================================");

	// ft_putnbr_endl(ft_lstlen(*list));	

// FT LSTITER ===================================================================
	// ft_putendl("======= Test ft_lstiter =======================================");

	// ft_lstiter(*list, &ft_lstprint);

// FT LSTMAP ===================================================================
	// ft_putendl("======= Test ft_lstmap =======================================");

	// list2 = ft_lstmap(*list, &ft_lstmap_test);
	// ft_lstprint(list2);


// FT_UPCASE ===================================================================

	// src = ft_strdup("789456qwertyuiopasdfghjklzxcvbnm12345678!@#$^&");
	// ft_upcase(src);
	// ft_putendl(src);
	// src = ft_strdup("789456QWERTYUIOPASDFGHJKLZXCVBNM12345678!@#$^&");
	// ft_upcase(src);
	// ft_putendl(src);

// FT_ATOI_BASE ===================================================================

	base = 16;
	src = ft_strdup(" 123NHOK");
	i = 0;
	while (i <= 32)
	{
		src[0] = i;
		printf("%d", i);
		printf("  |  la vraie : %d", atoi(src));
		printf("  | moi : %d\n", ft_atoi(src));
		i++;
	}
	src[0] = 128;
	printf("%d", i);
	printf("  |  la vraie : %d", atoi(src));
	printf("  | moi : %d\n", ft_atoi_base(src, base));

	printf(MAGENTA "\nTest vide\n" RESET);
	printf("la vraie : %d\n", atoi(""));
	printf("     moi : %d\n", ft_atoi_base("", base));

	printf(MAGENTA "\nTest 810202\n" RESET);
	printf("la vraie : %d\n", 8455468);
	printf("     moi : %d\n", ft_atoi_base("810202", base));

	printf(MAGENTA "\nTest 830707\n" RESET);
	printf("la vraie : %d\n", 8587015);
	printf("     moi : %d\n", ft_atoi_base("830707", base));

	printf(MAGENTA "\nTest ac5959\n" RESET);
	printf("la vraie : %d\n", 11295065);
	printf("     moi : %d\n", ft_atoi_base("ac5959", base));

	printf(MAGENTA "\nTest ddbaba\n" RESET);
	printf("la vraie : %d\n", 14531258);
	printf("     moi : %d\n", ft_atoi_base("ddbaba", base));

	printf(MAGENTA "\nTest ca9393\n" RESET);
	printf("la vraie : %d\n", 13276051);
	printf("     moi : %d\n", ft_atoi_base("ca9393", base));

	printf(MAGENTA "\nTest a24444\n" RESET);
	printf("la vraie : %d\n", 10634308);
	printf("     moi : %d\n", ft_atoi_base("a24444", base));

	printf(MAGENTA "\nTest abcfed\n" RESET);
	printf("la vraie : %d\n", atoi("abcfed"));
	printf("     moi : %d\n", ft_atoi_base("abcfed", base));

	printf(MAGENTA "\nTest ABCDEF\n" RESET);
	printf("la vraie : %d\n", atoi("ABCDEF"));
	printf("     moi : %d\n", ft_atoi_base("ABCDEF", base));

	printf(MAGENTA "\nTest 1\n" RESET);
	printf("la vraie : %d\n", atoi("1"));
	printf("     moi : %d\n", ft_atoi_base("1", base));

	printf(MAGENTA "\nTest abcfed\n" RESET);
	printf("la vraie : %d\n", atoi("abcfed"));
	printf("     moi : %d\n", ft_atoi_base("abcfed", base));

	printf(MAGENTA "\nTest 078\n" RESET);
	printf("la vraie : %d\n", atoi("078"));
	printf("     moi : %d\n", ft_atoi_base("078", base));

	printf(MAGENTA "\nTest aecd123\n" RESET);
	printf("la vraie : %d\n", atoi("aecd123"));
	printf("     moi : %d\n", ft_atoi_base("aecd123", base));

	printf(MAGENTA "\nTest \t\n 123\n" RESET);
	printf("la vraie : %d\n", atoi("\t\n 123"));
	printf("     moi : %d\n", ft_atoi_base("\t\n 123", base));

	printf(MAGENTA "\nTest \t\n +123\n" RESET);
	printf("la vraie : %d\n", atoi("\t\n +123"));
	printf("     moi : %d\n", ft_atoi_base("\t\n +123", base));

	printf(MAGENTA "\nTest \t\n +     123\n" RESET);
	printf("la vraie : %d\n", atoi("\t\n +     123"));
	printf("     moi : %d\n", ft_atoi_base("\t\n +     123", base));

	printf(MAGENTA "Test 25 \t\n\25 -123\n" RESET);
	printf("0 : %s\n", "\48");
	printf("la vraie : %d\n", atoi("\t\n\25 -123"));
	printf("     moi : %d\n", ft_atoi_base("\t\n\25 -123", base));

	printf(MAGENTA "\nTest \t\n -   123\n" RESET);
	printf("la vraie : %d\n", atoi("\t\n -   123"));
	printf("     moi : %d\n", ft_atoi_base("\t\n -   123", base));

	printf(MAGENTA "\nTest qwertyui\n" RESET);
	printf("la vraie : %d\n", atoi("qwertyui"));
	printf("     moi : %d\n", ft_atoi_base("qwertyui", base));

	printf(MAGENTA "\nTest +-156\n" RESET);
	printf("la vraie : %d\n", atoi("+-156"));
	printf("     moi : %d\n", ft_atoi_base("+-156", base));

	printf(MAGENTA "\nTest -+156\n" RESET);
	printf("la vraie : %d\n", atoi("-+156"));
	printf("     moi : %d\n", ft_atoi_base("-+156", base));

	printf(MAGENTA "\nTest ++156\n" RESET);
	printf("la vraie : %d\n", atoi("++156"));
	printf("     moi : %d\n", ft_atoi_base("++156", base));

	printf(MAGENTA "\nTest -ert156\n" RESET);
	printf("la vraie : %d\n", atoi("-ert156"));
	printf("     moi : %d\n", ft_atoi_base("-ert156", base));

	printf(MAGENTA "\nTest 156ert\n" RESET);
	printf("la vraie : %d\n", atoi("156ert"));
	printf("     moi : %d\n", ft_atoi_base("156ert", base));

	printf(MAGENTA "\nTest 156ert 156ert\n" RESET);
	printf("la vraie : %d\n", atoi("156ert 156ert"));
	printf("     moi : %d\n", ft_atoi_base("156ert 156ert", base));

	printf(MAGENTA "\nTest -156ert\n" RESET);
	printf("la vraie : %d\n", atoi("-156ert"));
	printf("     moi : %d\n", ft_atoi_base("-156ert", base));

	printf(MAGENTA "\nTest --156ert\n" RESET);
	printf("la vraie : %d\n", atoi("--156ert"));
	printf("     moi : %d\n", ft_atoi_base("--156ert", base));

	printf(MAGENTA "\nTest int min -2147483648\n" RESET);
	printf("la vraie : %d\n", atoi("-2147483648"));
	printf("     moi : %d\n", ft_atoi_base("-2147483648", base));

	printf(MAGENTA "\nTest int max 2147483647\n" RESET);
	printf("la vraie : %d\n", atoi("2147483647"));
	printf("     moi : %d\n", ft_atoi_base("2147483647", base));

	printf(MAGENTA "\nTest 0\n" RESET);
	printf("la vraie : %d\n", atoi("0"));
	printf("     moi : %d\n", ft_atoi_base("0", base));

	printf(MAGENTA "\nTest overflow 21474836470\n" RESET);
	printf("la vraie : %d\n", atoi("21474836470"));
	printf("     moi : %d\n", ft_atoi_base("21474836470", base));


	return (0); 
}	
