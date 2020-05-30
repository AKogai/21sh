//
// Created by A Kosimovsky on 25.05.20.
//

#include "shell.h"

static size_t	path_env_length(const char *str)
{
	size_t	index;

	index = 0;
	while (str[index] == '_' ||
	       (str[index] >= 'A' && str[index] <= 'Z') ||
	       (str[index] >= 'a' && str[index] <= 'z') ||
	       (str[index] >= '0' && str[index] <= '9'))
		index++;
	return (index);
}

static void		str_append(char **source, char *add1, char *add2)
{
	ft_strappend(source, add1);
	if (*source == NULL)
		return ;
	ft_strappend(source, add2);
}

static int		expand_dollar(char **envp, char **string, char **start)
{
	char	*name;
	char	*tmp;
	char	*value;
	size_t	len;

	tmp = ft_strndup(*string, (*start - *string));
	len = path_env_length((*start) + 1);
	name = ft_strndup((*start) + 1, len);
	if (tmp == NULL || name == NULL || len == 0)
	{
		free(tmp);
		free(name);
		if (len == 0)
			(*start)++;
		return (len == 0 ? 0 : ERR_MALLOC_FAIL);
	}
	value = ft_get_env_variable(envp, name);
	free(name);
	str_append(&tmp, value, (*start) + len + 1);
	if (tmp == NULL)
		return (ERR_MALLOC_FAIL);
	*start = tmp + (*start - *string) + (ft_strlen(value));
	free(*string);
	*string = tmp;
	return (0);
}

static int		expand_tilde(char **envp, char **string)
{
	char	*temp;
	char	*value;
	int		status;

	status = 0;
	temp = *string;
	if (temp[0] == '~' && (temp[1] == '\0' || temp[1] == '/'))
	{
		value = ft_get_env_variable(envp, "HOME");
		if (value != NULL)
		{
			temp = ft_strjoin(value, (temp + 1));
			if (temp == NULL)
				return (ERR_MALLOC_FAIL);
			free(*string);
			*string = temp;
		}
	}
	return (status);
}

int				expand_var(char **envp, char **string)
{
	int		status;
	char	*offset;

	status = 0;
	if ((*string)[0] == '~' && ((*string)[1] == '\0' || (*string)[1] == '/'))
	{
		status = expand_tilde(envp, string);
	}
	offset = ft_strchr(*string, '$');
	while (offset != NULL && offset != &(*string)[ft_strlen(*string) - 1])
	{
		status = expand_dollar(envp, string, &offset);
		if (status != 0)
			break ;
		offset = ft_strchr(offset, '$');
	}
	return (status);
}

int		expand_it(char **envp, char **argv)
{
	int		index;
	int		tmp;
	int		status;
	char	*var;

	index = 0;
	status = 0;
	while (argv[index] != NULL)
	{
		var = ft_strchr(argv[index], '$');
		if (var != NULL || argv[index][0] == '~')
		{
			tmp = expand_var(envp, &(argv[index]));
			if (tmp != 0)
			{
				status = tmp;
			}
		}
		index++;
	}
	return (status);
}