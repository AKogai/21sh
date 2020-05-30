#include "libft.h"

char 		*ft_strcdup(const char *src, char c)
{
	char	*str;
	int 	len;

	len = 0;
	while (src[len] && src[len] != c)
		len++;
	if (!(str = (char*)ft_memalloc(len + 1)))
		return (NULL);
	return (ft_strccpy(str, src, c));
}