
#include "libft.h"

char 	*ft_strccpy(char *dst, const char *src, char c)
{
	int i;

	if (!dst || !src)
		return (NULL);
	i = -1;
	while (src[++i] && (src[i] != c))
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}