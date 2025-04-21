#include "../push_swap.h"


/*
 *  Calculates the moves that each node needs to be positioned correctly
 * @var target - The node that has to be pushed
 * @var tmp -    The closest node
 */
t_moves    *ft_calculate_moves(t_node **stack_a, t_node **stack_b)
{
    t_moves *moves;
    t_node  *target;
    t_node  *tmp;
    int count;

    count = 0;


    // First calculate moves only for one node, then try to do it for all
    target = *stack_a;
    moves = ft_newmoves(target);


    // Check if its the new min, new max or a normal node
    if (target->value < ft_find_node(stack_b, LOW)->value || target->value > ft_find_node(stack_b, BIG)->value)     // If is the new lowest
    {
        ft_putstr_fd("MIN/max\n", 1);
    }
    else
    {
        tmp = ft_find_nearest_node(stack_b, target->value, LOW);        // Search its closest low node into the next stack
        count = ft_count_nodeposition(stack_b, tmp);    // These are the rotations of b to get the closest at the TOP
    }
    
    moves->rb = count;
    moves->pb = 1;
    return (moves);
}

/*
 * Executes 1 group of movements to push 1 node from A to B
 * Calculates and compares all the posibles moves from all the nodes
 *
 */
void    ft_timsort_round(t_node **stack_a, t_node **stack_b)
{
    t_moves *moves;

    moves = ft_calculate_moves(stack_a, stack_b);
    ft_execute_moves(stack_a, stack_b, moves);

    // And execute moves
}


/*
 * Turk Algorithm that moves depending on the min cost
 * Do all the moves to order de stack a
 */
void    ft_timsort(t_node **stack_a, int size)
{
    t_node  **stack_b;


    ft_indexate(stack_a, size);
    stack_b = ft_init_void_stack(size);
    
    ft_pb(stack_a, stack_b);
    ft_pb(stack_a, stack_b);
    // while (!ft_issort(stack_b, DESC) && !*stack_a)      // Por alguna razon aqui no entra
    // {
    //      AQUI DEBERIA IR EL ROUND
    // }
    
    ft_timsort_round(stack_a, stack_b);

}