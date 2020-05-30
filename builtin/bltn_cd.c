//
// Created by A Kosimovsky on 26.05.20.
//
#include "shell.h"

static void 	get_home(char *ptr, t_sh *shell)
{
	int 		i;
	size_t      size;

	i = -1;
	ptr = alloc_path(&size);
	while (shell->env[++i])
	{
		if (ft_strnequ(shell->env[i], "HOME=", 5))
		{
			ft_strcpy(ptr, &shell->env[i][5]);
			break ;
		}
	}
}

static void		get_old_pwd(char *ptr, t_sh *shell)
{
	int     i;
	size_t  size;

	i = -1;
	ptr = alloc_path(&size);
	while (shell->env[++i])
	{
		if (ft_strnequ(shell->env[i], "OLDPWD=", 7))
			ft_strcpy(ptr, &shell->env[i][7]);
		break ;
	}
}

static void 	get_absolute_path(char *ptr, char *path)
{
	size_t size;

	ptr = alloc_path(&size);
	ft_strcpy(ptr, path);
}

static void		update_path(char *ptr, t_sh *shell)
{
	int 		old_pwd;
	int 		current_pwd;
	char 		*tmp;
	int 		i;
	size_t      size;

	i = -1;
	old_pwd = 0;
	current_pwd = 0;
	while (shell->env[++i])
	{
		if (ft_strnequ(shell->env[i], "OLDPWD=", 7))
			old_pwd = i;
		else if (ft_strnequ(shell->env[i], "PWD=", 4))
			current_pwd = i;
	}
	tmp = shell->env[old_pwd];
	shell->env[old_pwd] = ft_strjoin("OLDPWD=", &shell->env[current_pwd][4]);
	free(tmp);
	tmp = shell->env[current_pwd];
	ptr = alloc_path(&size);
	getcwd(ptr, size);
	if (ft_strnequ(ptr, "/private", 8))
		shell->env[current_pwd] = ft_strjoin("PWD=", &ptr[8]);
	else
		shell->env[current_pwd] = ft_strjoin("PWD=", ptr);
	free(tmp);
}

int 			bltn_cd(t_sh *shell)
{
	char    *ptr;
	size_t  size;
	int     status;

	status = 0;
	ptr = alloc_path(&size);
	if (shell->argc > 2)
	{
		ft_putendl("minishell: cd: too many arguments");
		return (-1);
	}
	if ((getcwd(ptr, size)) == NULL)
	{
		print_error(ERR_GET_CWD);
		ft_putchar_fd('\n', 2);
		return (ERR_GET_CWD);
	}
	if (shell->argc == 1)
		get_home(ptr, shell);
	else if (ft_strequ(shell->argv[1] , "-"))
		get_old_pwd(ptr, shell);
	else if (shell->argv[1][0] == '/')
		get_absolute_path(ptr, shell->argv[1]);
	else
	{
		ft_strcat(ptr, "/");
		ft_strcat(ptr, shell->argv[1]);
	}
	if ((status = chdir(ptr)) < 0)
	{
		ft_putstr("minishell: cd: ");
		ft_putstr("no such file or directory: ");
		ft_putendl(shell->argv[1]);
	}
	else
		update_path(ptr, shell);
	status ^= 1;
	return (status);
}
