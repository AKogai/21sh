
#include "shell21.h"

void	ft_remove_quoting(t_shell *shell, t_token *token)
{
	t_token *tmp;
	char	*new;

	tmp = token;
	while (tmp)
	{
		if (tmp->token_type == WORD)
		{
			new = ft_remove_quotes(tmp->str);
			free(tmp->str);
			tmp->str = new;
		}
		if (tmp->operator_type == DLESS)
		{
			ft_heredoc_expand_remove_quoting(shell, tmp);
		}
		tmp = tmp->next;
	}
}
