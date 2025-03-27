
/*
 * This file functions wrap the raw operations file where these are explained
 * with more detail
 */

#include "../push_swap.h"

void    ft_ra(t_node **stack_a)
{
    ft_rotate(stack_a);
    ft_putstr_fd("ra", 1);
}

void    ft_rb(t_node **stack_b)
{
    ft_rotate(stack_b);
    ft_putstr_fd("rb", 1);
}

void    ft_rr(t_node **stack_a, t_node **stack_b)
{
    ft_rotate(stack_a);
    ft_rotate(stack_b);
    ft_putstr_fd("rr", 1);
}