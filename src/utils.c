#include "../push_swap.h"

/*
 * Freezea un stack con los nodos por posicion de memoria
 * No busca el next en ningun momento
 */

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