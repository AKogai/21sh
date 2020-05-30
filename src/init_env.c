//
// Created by A Kosimovsky on 22.05.20.
//
#include "shell.h"

static size_t ft_strlenc(const char *str, int c, size_t size)
{
	size_t length;

	length = 0;
	while (str[length] != c && length < size)
		length++;
	return (length);
}

static t_env *new_env_var(char *env_var)
{
	t_env *new;

	if (!(new = (t_env *)ft_memalloc(sizeof(t_env))))
	{
		print_error(ERR_MALLOC_FAIL);
		return (NULL);
	} else {
		new->name = ft_strcdup(env_var, '=');
		new->value = ft_strdup(&(env_var[ft_strlenc(env_var, '=',
		                                            ft_strlen(env_var)) + 1]));
		if (new->name == NULL || new->value == NULL) {
			print_error(ERR_MALLOC_FAIL);
			free(new->name);
			free(new->value);
			return (NULL);
		}
	}
	new->next = NULL;
	return (new);
}

t_env           *init_env(void)
{
	extern char **environ;
	t_env       *first_env;
	t_env       *sh_env;
	int         i;

	i = 0;
	sh_env = new_env_var(environ[i]);
	if (sh_env == NULL)
	{
		print_error(ERR_ENV);
		return (NULL);
	}
	first_env = sh_env;
	i++;
	while (environ[i] != NULL)
	{
		sh_env->next = new_env_var(environ[i]);
		sh_env = sh_env->next;
		if (sh_env == NULL)
			return (NULL);
		i++;
	}
	return (first_env);
}