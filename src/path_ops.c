//
// Created by A Kosimovsky on 25.05.20.
//

#include "shell.h"
#ifdef _POSIX_PATH_MAX
static long pathmax = _POSIX_PATH_MAX;
#else
static long pathmax = 0;
#endif

static long posix_version = 0;
static long xsi_version = 0;
#define PATH_MAX_ALTER 1024

char    *alloc_path(size_t *size_ptr)
{
	char    *ptr;
	size_t  size;
	int     status;

	if (posix_version == 0)
		posix_version = sysconf(_SC_VERSION);
	if (xsi_version == 0)
		xsi_version = sysconf(_SC_XOPEN_VERSION);
	if (pathmax == 0) {
		status = NO;
		if ((pathmax = pathconf("/", _POSIX_PATH_MAX)) < 0) {
			if (status == NO)
				pathmax = PATH_MAX_ALTER;
			else {
				print_error(ERR_PATHCONF);
				ft_putchar_fd('\n', 2);
			}
		} else {
			pathmax++;
		}
	}
	if ((posix_version < 200112L) && (xsi_version < 4))
		size = pathmax + 1;
	else
		size = pathmax;
	if ((ptr = malloc(size)) == NULL)
	{
		print_error(ERR_MALLOC_FAIL);
		ft_putchar_fd('\n', 2);
	}
	if (size_ptr != NULL)
		*size_ptr = size;
	return (ptr);
}

static int	find_binary_in_dir(char *dirname, char *bin_name)
{
	DIR				*dir;
	struct dirent	*entry;

	dir = opendir(dirname);
	if (dir == NULL)
		return (-1);
	entry = readdir(dir);
	while (entry != NULL)
	{
		if (ft_strcmp(entry->d_name, bin_name) == 0)
		{
			(void)closedir(dir);
			return (0);
		}
		entry = readdir(dir);
	}
	closedir(dir);
	return (-1);
}

static int	append_paths(char **paths, t_sh *shell)
{
	size_t	index;

	index = 0;
	while (paths[index] != NULL)
	{
		shell->path = NULL;
		if (find_binary_in_dir(paths[index], shell->argv[0]) == 0)
		{
			if (paths[index][ft_strlen(paths[index]) - 1] != '/')
				ft_strappend(&(paths[index]), "/");
			shell->path = ft_strjoin(paths[index], shell->argv[0]);
			if (shell->path == NULL)
				return (ERR_MALLOC_FAIL);
			else if (access(shell->path, X_OK) == 0)
				return (0);
			else
				free(shell->path);
		}
		index++;
	}
	shell->path = NULL;
	return (-1);
}

static int		is_builtin(char *cmd)
{
	if (ft_strcmp("echo", cmd) == 0)
		return (YES);
	if (ft_strcmp("cd", cmd) == 0)
		return (YES);
	if (ft_strcmp("setenv", cmd) == 0)
		return (YES);
	if (ft_strcmp("unsetenv", cmd) == 0)
		return (YES);
	if (ft_strcmp("env", cmd) == 0)
		return (YES);
	if (ft_strcmp("exit", cmd) == 0)
		return (YES);
	return (NO);
}

int			find_binary_in_path(t_sh *shell)
{
	char	*env_path;
	char	**paths;
	int		status;

	status = 0;
	if (is_builtin(shell->argv[0]))
	{
		shell->path = ft_strdup("\0");
	}
	else if (ft_strchr(shell->argv[0], '/') != NULL)
	{
		shell->path = ft_strdup(shell->argv[0]);
	}
	else
	{
		env_path = ft_get_env_variable(shell->env, "PATH");
		if (env_path == NULL)
			return (ERR_ENV);
		paths = ft_strsplit(env_path, ':');
		if (paths == NULL)
		{
			print_error(ERR_MALLOC_FAIL);
			return (ERR_MALLOC_FAIL);
		}
		status = append_paths(paths, shell);
		ft_free_array(paths);
	}
	return (status);
}

