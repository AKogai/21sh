#include "libft.h"

char 	*ft_strndup(const char *src, size_t len)
{
	char *str;

	if (!(str = (char*)ft_memalloc(len + 1)))
		return (NULL);
	return (ft_strncpy(str, src, len));
}