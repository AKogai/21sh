#include "libft.h"

void	ft_exit(char *error, int status)
{
	ft_putendl_fd(error, 2);
	exit(status);
}
