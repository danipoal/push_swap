#include "../push_swap.h"


/*
 * Sorts the stack if it has 3 elements
 * If we work with the last_node, we have to reset it again to find the new last node
 * case1 -> 321 ra-> 231 rra->123
 * Worst -> 132 rra-> 231 rra-> 123
 */
void    ft_case_three(t_node **stack_a)
{
    //t_node  *last_node;

    //last_node = ft_nodelast(*stack_a);
    while (!ft_issort(stack_a))
    {
        if ((*stack_a)->value > (*stack_a)->next->value)
            ft_sa(stack_a);
        if (!ft_issort(stack_a))
            ft_rra(stack_a);
    }
    

    //ft_issort(stack_a);
}

// void    ft_case_three(t_node **stack_a)
// {
//     t_node  *last_node;

//     last_node = ft_nodelast(*stack_a);
//     if ((*stack_a)->value > (*stack_a)->next->value)
//         ft_sa(stack_a);
//     if ((*stack_a)->next->value > last_node->value)
//     {
//         ft_rra(stack_a);
//         last_node = ft_nodelast(*stack_a);
//     }
//     if ((*stack_a)->next->value > last_node->value)
//         ft_rra(stack_a);
// }

/*
 * Sorts the stack if it has 5 elements
 */
// void    ft_case_five(t_node **stack_a)
// {
//     t_node  **stack_b;

//     stack_b = ft_init_void_stack(5);

// }


/*
 * Redirect to the exact short cases
 *
 */
void	ft_short_cases(t_node **stk, int size)
{
	if (!stk || !size)
		return ;
	if (size == 3)
        ft_case_three(stk);
	// else if (size == 4)
    //     //ft_case_four(stk);
    // else if (size == 5)
    //     //ft_case_five(stk);
}