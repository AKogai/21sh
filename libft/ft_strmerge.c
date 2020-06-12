
#include "libft.h"

void	ft_strmerge(char **origin, char *add)
{
	char *temp;

	if (!*origin)
		*origin = ft_strdup(add);
	else
	{
		temp = *origin;
		*origin = ft_strjoin(*origin, add);
		free(temp);
	}
}
