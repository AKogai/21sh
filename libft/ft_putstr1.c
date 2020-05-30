
#include "libft.h"

void	ft_putstr1(char const *str)
{
	if (str)
		write(1, str, ft_strlen(str));
}
