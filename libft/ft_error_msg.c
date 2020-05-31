
#include "libft.h"

void	ft_error_msg(char *error)
{
	ft_putendl_fd(error, STDERR);
	exit(-1);
}
