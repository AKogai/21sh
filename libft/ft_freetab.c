#include "libft.h"

void	ft_freetab(char ***tab)
{
	char **temp;

	if (!tab || !*tab)
		return ;
	temp = *tab;
	while (*temp)
		ft_strdel(&(*temp++));
	free(*tab);
	*tab = NULL;
}
