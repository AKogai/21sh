
#include "libft.h"

char	*ft_strnjoin(char *s1, int n, ...)
{
	char	*s;
	char	*tmp;
	va_list ap;

	s = NULL;
	tmp = NULL;
	va_start(ap, n);
	while (n--)
	{
		if (s == NULL)
			s = ft_strjoin(s1, va_arg(ap, char *));
		else
		{
			tmp = s;
			s = ft_strjoin(s, va_arg(ap, char *));
			ft_strdel(&tmp);
		}
	}
	va_end(ap);
	return (s);
}
