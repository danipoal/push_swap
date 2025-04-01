#include "../push_swap.h"

int ft_count_binary_digits(int n)
{
    int count;

    if (n == 0)
        return (1);
    count = 0;
    while (n > 0)
    {
        count++;
        n >>= 1; // Desplaza bits a la derecha (divide entre 2)
    }
    return (count);
}

void	ft_putnbr_base(long nb, char *base)
{
	int	base_len;
	int	index;

	base_len = ft_strlen(base);
	if (nb < 0)
	{
		ft_putchar_fd('-', 1);
		nb = -nb;
	}
	if (nb >= base_len)
	{
		ft_putnbr_base(nb / base_len, base);
		index = nb % base_len;
		ft_putchar_fd(base[index], 1);
	}
	if (nb < base_len)
		ft_putchar_fd(base[nb], 1);
}