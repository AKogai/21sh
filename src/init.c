
#include "shell.h"

char		*ft_get_env_variable(char **env, char *var)
{
	char	*temp;
	char	*stop;
	int		i;

	if (!env)
		return (NULL);
	i = 0;
	while (env[i])
	{
		temp = ft_strsub(env[i], 0,\
				ft_strchr(env[i], '=') - env[i]);
		if (ft_strequ(temp, var))
		{
			stop = ft_strchr(env[i], '=');
			free(temp);
			return (ft_strsub(env[i], stop - env[i] + 1,\
						ft_strlen(stop)));
		}
		i++;
		free(temp);
	}
	return (NULL);
}

void	ft_modify_variable(char ***env, char *new_var)
{
	char	*to_free;
	char	*temp_env;
	char	*temp_var;
	int		i;

	temp_var = ft_strsub(new_var, 0, ft_strchr(new_var, '=') - new_var);
	i = 0;
	while (*(*env + i))
	{
		temp_env = ft_strsub(*(*env + i), 0,\
				ft_strchr(*(*env + i), '=') - *(*env + i));
		if (ft_strequ(temp_env, temp_var))
		{
			to_free = *(*env + i);
			*(*env + i) = ft_strdup(new_var);
			free(to_free);
			free(temp_var);
			free(temp_env);
			return ;
		}
		free(temp_env);
		i++;
	}
	free(temp_var);
	ft_addtotab(*env, new_var);
}

 static void	ft_increase_shlvl(char ***env)
 {
 	char	*shlvl;
 	char	*temp;
 	char	*newlvl;
 	int		lvl;

 	if ((shlvl = ft_get_env_variable(*env, "SHLVL")))
 	{
 		lvl = ft_atoi(shlvl) + 1;
 		newlvl = ft_itoa(lvl);
 		temp = shlvl;
 		shlvl = ft_strjoin("SHLVL=", newlvl);
 		free(temp);
 		free(newlvl);
 		ft_modify_variable(env, shlvl);
 		free(shlvl);
 	}
 	else
 		ft_addtotab(*env, "SHLVL=1");
 }

 static void	ft_update_pwd(char ***env)
 {
 	char	*cwd;
 	char	*pwd;
 	char	*temp;
 	size_t  size;

 	cwd = alloc_path(&size);
 	if (!(cwd = getcwd(cwd, size)))
 		return ;
 	if ((pwd = ft_get_env_variable(*env, "PWD")))
 	{
 		temp = cwd;
 		cwd = ft_strjoin("PWD=", cwd);
 		free(temp);
 		ft_modify_variable(env, cwd);
 		free(pwd);
 		free(cwd);
 	}
 	else
 	{
 		pwd = ft_strjoin("PWD=", cwd);
 		ft_addtotab(*env, pwd);
 		free(pwd);
 		free(cwd);
 	}
 }

t_sh    *init_sh(char **envp)
{
	t_sh *shell;
	t_input *input;

	if (!(shell = (t_sh *)malloc(sizeof(t_sh))))
	{
		print_error(ERR_MALLOC_FAIL);
		return (NULL);
	}
	if (!(input = (t_input *)malloc(sizeof(t_input))))
	{
		print_error(ERR_MALLOC_FAIL);
		return (NULL);
	}
	shell->string = NULL;
	shell->argc = 0;
	shell->argv = NULL;
	shell->path = NULL;
	shell->env = NULL;
	shell->history = NULL;
	shell->histo_index = 0;
	shell->ret_cmd = 0;
	shell->sigint = 0;
	shell->env = ft_tabdup(envp);
	ft_increase_shlvl(&(shell->env));
	ft_update_pwd(&shell->env);
	return (shell);
}
