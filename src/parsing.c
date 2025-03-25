#include "../push_swap.h"

/*
 * Partse from array of strings to array of ints
 * @param ac - is arg count - 1 because avoid program name
 * @param type - 0 av has no program name in pos 0, 1 has program name
 */
int	*ft_atoi_array(char **av, int ac, int type)
{
	int	*numbers;
	int	i;
	
	i = 0;
	numbers = (int *) malloc(ac * sizeof(int));
	if (!numbers)
		return (NULL);
	while (i < ac)
	{
		numbers[i] = ft_atoi(av[i + type]);
		i++;
	}
	return (numbers);
}