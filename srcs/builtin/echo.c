
#include "shell21.h"

int		bltin_echo(char **cmd)
{
	int i;

	i = 1;
	if (ft_strequ(cmd[i], "-n"))
		++i;
	while (cmd[i])
	{
		ft_putstr(cmd[i]);
		if (cmd[++i])
			write(1, " ", 1);
	}
	if (!ft_strequ(cmd[1], "-n"))
		write(1, "\n", 1);
	return (EXIT_SUCCESS);
}
