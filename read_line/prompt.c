
#include "shell.h"

static char	*ft_get_user(void)
{
	struct passwd *ret_pwd;

	if (!(ret_pwd = getpwuid(getuid())))
		return (NULL);
	return (ft_strdup(ret_pwd->pw_name));
}

static void	ft_prompt_ret_cmd(void)
{
	if (g_sh->ret_cmd == EXIT_SUCCESS)
		ft_putstr1(BGREEN" $> "RESET);
	else
		ft_putstr1(BRED" $> "RESET);
}

int			ft_put_prompt_sigint(void)
{
	int len;

	ft_raw_term();
	tputs(tgetstr("cr", NULL), 1, &ft_intputchar);
	tputs(tgetstr("ce", NULL), 1, &ft_intputchar);
	len = ft_display_prompt();
	ft_canonic_term();
	return (len);
}

int			ft_display_prompt(void)
{
	char	*user;
	char	*cwd;
	int		len;
	char    *ptr;
	size_t  size;

	ptr = alloc_path(&size);
	len = 6;
	ft_putstr(BWHITE);
	if ((user = ft_get_user()))
	{
		ft_putstr1(user);
		ft_putstr1(": "BLUE);
		len += ft_strlen(user);
	}
	else
	{
		ft_putstr1("21sh: "BLUE);
		len += 4;
	}
	free(user);
	if ((cwd = getcwd(ptr, size)))
	{
		ft_putstr1(cwd);
		len += ft_strlen(cwd);
	}
	free(cwd);
	ft_prompt_ret_cmd();
	return (len);
}
