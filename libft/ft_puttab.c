
#include "libft.h"

void	ft_puttab(char **tab)
{
	char **temp;

	temp = tab;
	while (*temp)
		ft_putendl(*temp++);
}
