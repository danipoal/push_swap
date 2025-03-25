#include "../push_swap.h"

/*
 * Swap the first two nodes of a stack
 * Asigns the nexts nodes that are gonna be used, and swap
 */
void    ft_swap(t_node **stk)
{
    t_node  *tmp;
    t_node  *third_node;

    tmp = (*stk)->next;
    third_node = tmp->next;

    tmp->next = *stk;
    (*stk)->next = third_node;
    *stk = tmp;
}

