#include "../push_swap.h"

void    ft_free_moves(t_moves *moves)
{
    if (moves)
        free(moves);
}

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

/*
 * Checks if  stack is sorted
 * @returns 1 if sorted, 0 Not sorted
 */
int ft_issort(t_node **stk, int sort_type)
{
    t_node  *tmp;

    if (!stk || !*stk)
        return (1);

    tmp = *stk;
    while (tmp->next)
    {
        if (sort_type == ASC){
            if (tmp->value > tmp->next->value)
                return (0);
        }
        else if (sort_type == DESC)
        {
            if (tmp->value < tmp->next->value)
                return (0);
        }
        tmp = tmp->next; 
    }
    return (1);
}
/*
 * Finds the lowest/biggest number in a stack
 * Target is the current low/big number
 * @param type -> LOWEST/BIGGEST
 */
t_node  *ft_find_node(t_node **stk, int type)
{
    t_node  *tmp;
    t_node  *target;
    
    tmp = *stk;
    target = tmp;
    while (tmp->next)
    {
        if (type == LOW)
        {
            if (target->value > tmp->next->value)
                target = tmp->next;
        }
        else if (type == BIG)
        {
            if (target->value < tmp->next->value)
                target = tmp->next;            
        }
        tmp = tmp->next;
    }
    return (target);
}