#include "../push_swap.h"


void    ft_calculate_moves()
{

}

/*
 * Executes 1 group of movements to push 1 node from A to B
 * Calculates and compares all the posibles moves from all the nodes
 *
 */
void    ft_timsort_round(t_node **stack_a, t_node **stack_b)
{
    ft_calculate_moves();
}


/*
 * Turk Algorithm that moves depending on the min cost
 * Do all the moves to order de stack a
 */
void    ft_timsort(t_node **stack_a, int size)
{
    t_node  **stack_b;


    ft_indexate(stack_a, size);
    ft_init_void_stack(size);
    
    ft_pb(stack_a, stack_b);
    ft_pb(stack_a, stack_b);
    while (!ft_issort(stack_b, DESC) && !*stack_a)
    {
        ft_timsort_round(stack_a, stack_b);
    }
    

}