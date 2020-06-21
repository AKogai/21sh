
#include "shell21.h"

static char	*ft_heredoc_remove_escape(char *str)
{
	if (*str == '\\')
	{
		if (*(str + 1) && (*(str + 1) == '\n' || *(str + 1) == '$'\
					|| *(str + 1) == '\\'))
			str++;
		if (*str == '\n')
			str++;
	}
	return (str);
}

static void	ft_heredoc_expand(t_shell *shell, t_token *dless)
{
	char *dollar;

	while ((dollar = ft_strchr(dless->heredoc, '$'))\
			&& !ft_is_quoted_no_dquotes(dless->heredoc, dollar))
	{
		if (!ft_is_valid_expand(dollar))
			break ;
		ft_var_expansion(shell, &dless->heredoc, dollar);
	}
}

static void	ft_heredoc_remove_quoting(char **heredoc)
{
	char *tmp;
	char *new;

	new = NULL;
	tmp = *heredoc;
	while (*tmp)
	{
		tmp = ft_heredoc_remove_escape(tmp);
		if (*tmp)
			new = ft_charappend(new, *tmp);
		else
			break ;
		tmp++;
	}
	if (!new)
		new = ft_strdup("");
	free(*heredoc);
	*heredoc = new;
}

void		ft_heredoc_expand_remove_quoting(t_shell *shell, t_token *dless)
{
	if (!ft_strchr(dless->next->str, '"')\
			&& !ft_strchr(dless->next->str, '\'')\
				&& !ft_strchr(dless->next->str, '\\'))
	{
		ft_heredoc_expand(shell, dless);
		ft_heredoc_remove_quoting(&dless->heredoc);
	}
}
