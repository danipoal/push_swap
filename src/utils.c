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

int ft_issort(t_node **stk)
{
    t_node  *tmp;

    if (!stk || !*stk)
        return (1);

    tmp = *stk;
    while (tmp->next)
    {
        if (tmp->value > tmp->next->value)
        {
            //ft_putstr_fd("NO Sort", 1);
            return (0);
        }
        tmp = tmp->next; 
    }
    return (1);
}