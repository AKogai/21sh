
#include "libft.h"

void	ft_dlstadd(t_dlst **alst, t_dlst *new)
{
	if (alst != NULL && *alst == NULL)
		*alst = new;
	else if (alst != NULL && *alst != NULL && new != NULL)
	{
		new->next = *alst;
		new->prev = NULL;
		(*alst)->prev = new;
		*alst = new;
	}
}
