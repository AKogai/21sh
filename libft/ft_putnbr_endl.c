
#include "libft.h"

void	ft_putnbr_endl(int n)
{
	long int	nb;
	int			len;
	char		s[10];

	nb = (long int)n;
	if (nb == 0)
		ft_putchar('0');
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	len = 0;
	while (nb > 0)
	{
		s[len++] = nb % 10 + 48;
		nb = nb / 10;
	}
	while (len-- > 0)
		ft_putchar(s[len]);
	ft_putchar('\n');
}
