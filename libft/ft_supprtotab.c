
#include "libft.h"

char	**ft_supprtotab(char **tab, int suppr)
{
	char	**new;
	int		len;
	int		i;
	int		j;

	if (tab)
		len = ft_tablen(tab) - 1;
	else
		return (NULL);
	if (!(new = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	*(new + len) = 0;
	i = 0;
	j = 0;
	while (*(tab + j))
	{
		if (j != suppr)
			*(new + i++) = *(tab + j++);
		else
			free(*(tab + j++));
	}
	free(tab);
	return (new);
}
