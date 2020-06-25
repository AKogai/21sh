
#include "shell21.h"

int		ft_isinenv(t_shell *shell, char *var)
{
	char	*temp;
	int		i;
	int		ret;

	i = 0;
	ret = -1;
	if (!shell->env)
		return (ret);
	while (*(shell->env + i))
	{
		temp = ft_strsub(*(shell->env + i), 0,\
				ft_strchr(*(shell->env + i), '=') - *(shell->env + i));
		if (ft_strequ(temp, var))
			ret = i;
		i++;
		free(temp);
	}
	return (ret);
}

int		bltin_unsetenv(t_shell *shell, char **cmd)
{
	int suppr;
	int i;

	i = 1;
	while (cmd[i])
	{
		if ((suppr = ft_isinenv(shell, cmd[i])) != -1)
			shell->env = ft_supprtotab(shell->env, suppr);
		i++;
	}
	return (EXIT_SUCCESS);
}
