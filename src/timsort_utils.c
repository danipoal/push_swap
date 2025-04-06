#include "../push_swap.h"


/*
 * Finds nearest node given a value. 
 * Can find the nearest big or low.
 * 
 * value - current_closest->value == Descendente (LOW)
 * current_closest->value - value == Ascendente (BIG)
 */
t_node  *ft_find_nearest_node(t_node **stk, int value, int type)
{
    t_node  *tmp;
    t_node  *current_closest;
    int     current_diff;

    tmp = *stk;
    current_diff = INT_MAX;         // Quizas no funciona para la diff entre INT_MIN y INT_MAX
    while (tmp)      // Type quitar aqui
    {
        if (type == BIG && current_diff > tmp->value - value && value < tmp->value) // 2 comprobaciones, 1 que el diff sea menor, pero que el value siga siendo mayor (ASC-BIG)
        {
            current_closest = tmp;
            current_diff = tmp->value - value;
        }
        else if (type == LOW && current_diff > value - tmp->value && value > tmp->value)
        {
            current_closest = tmp;
            current_diff = value - tmp->value;
        }
        tmp = tmp->next;
    }
    return (current_closest);
}

/*
 * Inserts the index of the nodes, its real 
 */
void    ft_indexate(t_node **stack_a, int size)
{
    int n;
    t_node  *lowest_unasigned;

    lowest_unasigned = ft_find_node(stack_a, LOW);
    n = 0;
    while (n < size)
    {
        lowest_unasigned->index = n;
        lowest_unasigned = ft_find_nearest_node(stack_a, lowest_unasigned->value, BIG);
        n++;
    }
    // TODO Make a function that orders the index of all nodes
    ft_print_nodes(stack_a);

}