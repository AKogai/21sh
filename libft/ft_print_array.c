//
// Created by A Kosimovsky on 28.05.20.
//

#include "libft.h"

int		ft_print_array(char **array)
{
	size_t i;

	i = 0;
	if (array == NULL || array[0] == NULL)
		return (-1);
	while (array[i] != NULL)
	{
		ft_putendl(array[i]);
		i++;
	}
	return (0);
}
