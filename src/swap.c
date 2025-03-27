
/*
 * This file functions wrap the raw operations file where these are explained
 * with more detail
 */

#include "../push_swap.h"

void    ft_sa(t_node **stack_a)
{
    ft_swap(stack_a);
    ft_putstr_fd("sa", 1);
}

void    ft_sb(t_node **stack_b)
{
    ft_swap(stack_b);
    ft_putstr_fd("sb", 1);
}

void    ft_ss(t_node **stack_a, t_node **stack_b)
{
    ft_swap(stack_a);
    ft_swap(stack_b);
    ft_putstr_fd("ss", 1);
}