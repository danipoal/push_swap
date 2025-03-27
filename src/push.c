
/*
 * This file functions wrap the raw operations file where these are explained
 * with more detail
 */

#include "../push_swap.h"

void   ft_pa(t_node **stack_a, t_node **stack_b)
{
    ft_push(stack_a, stack_b);
    ft_putstr_fd("pa", 1);
}

void   ft_pb(t_node **stack_a, t_node **stack_b)
{
    ft_push(stack_b, stack_a);
    ft_putstr_fd("pb", 1);
}