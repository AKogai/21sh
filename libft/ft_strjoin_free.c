
#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, int choice)
{
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if ((str = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)) == NULL)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	if (choice == 1)
		ft_strdel(&s1);
	else if (choice == 2)
		ft_strdel(&s2);
	else if (choice == 3)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (str);
}
