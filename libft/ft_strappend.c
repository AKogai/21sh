//
// Created by A Kosimovsky on 25.05.20.
//

#include "libft.h"

void	ft_strappend(char **source, const char *addition)
{
	void *temp;

	temp = *source;
	if (*source == NULL)
	{
		*source = ft_strdup(addition);
	}
	else if (addition != NULL)
	{
		*source = ft_strjoin(*source, addition);
		free(temp);
	}
}