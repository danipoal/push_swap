#include "../push_swap.h"

int *ft_atoi_ptr(char **av, int ac)
{
    int *numbers;
    int i;

    numbers = (int *) malloc(ac * sizeof(int));
	if (!numbers)
		return (NULL);
    i = 0;
    while (av[i])
    {
        numbers[i] = ft_atoi(av[i]);
        i++;
    }
    return (numbers);
}