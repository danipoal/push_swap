#include "../push_swap.h"

void    ft_free_split(char **array)
{
    int i = 0;

    while (array[i])
    {
        free(array[i]);
        i++;
    }
    free(array);
}
