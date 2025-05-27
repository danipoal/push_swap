#include "../push_swap.h"


/*
 *  Calculates the moves that each node needs to be positioned correctly
 * @var target - The node that has to be pushed
 * @var tmp -    The closest node
 * 
 * TODO Gets the ra in function of the position of the target (He cambiado que el target se elija desde el compare asi que hay que calcular los ra del stack_a cuando ya no es el primero)
 * 
 */
t_moves    *ft_calculate_moves(t_node **stack_a, t_node **stack_b, t_node *target)
{
    t_moves *moves;
    t_node  *tmp;
    int     count;

    count = 0;                      // First calculate moves only for one node, then try to do it for all
    moves = ft_newmoves(target);    // Check if its the new min, new max or a normal node
    if (target->value < ft_find_node(stack_b, LOW)->value || target->value > ft_find_node(stack_b, BIG)->value)
    {                               // If is the new lowest
        tmp = ft_find_node(stack_b, BIG); 
        count = ft_count_nodeposition(stack_b, tmp);
    }
    else
    {
        tmp = ft_find_nearest_node(stack_b, target->value, LOW);
        count = ft_count_nodeposition(stack_b, tmp);    // These are the rotations of b to get the closest at the TOP
    }
    moves->ra = ft_count_nodeposition(stack_a, target);
    moves->rb = count;
    moves->pb = 1;
    return (moves);
}

/*
 * Compares each calculation of moves getting only the best one
 * TODO 
 */
t_moves    *ft_compare_moves(t_node **stack_a, t_node **stack_b)
{
    t_moves *best_moves;
    t_moves *new_moves;
    t_node  *tmp_a;

    tmp_a = *stack_a;
    best_moves =  ft_calculate_moves(stack_a, stack_b, tmp_a);
    tmp_a = tmp_a->next;
    while (tmp_a)
    {
        new_moves = ft_calculate_moves(stack_a, stack_b, tmp_a);
        if (ft_get_num_moves(new_moves) < ft_get_num_moves(best_moves))
            best_moves = new_moves;
        tmp_a = tmp_a->next;
    }
    return (best_moves);
}

/*
 * Executes 1 group of movements to push 1 node from A to B
 * Calculates and compares all the posibles moves from all the nodes
 *
 */
void    ft_timsort_round(t_node **stack_a, t_node **stack_b)
{
    t_moves *moves;

    moves = ft_compare_moves(stack_a, stack_b);
    ft_debug(moves->target, 6);
    ft_execute_moves(stack_a, stack_b, moves);
    ft_print_nodes(stack_b);
}


/*
 * Turk Algorithm that moves depending on the min cost
 * Do all the moves to order de stack a
 */
void    ft_timsort(t_node **stack_a, int size)
{
    t_node  **stack_b;
    t_moves *last_moves;

    ft_indexate(stack_a, size);
    stack_b = ft_init_void_stack(size);
    
    ft_pb(stack_a, stack_b);
    ft_pb(stack_a, stack_b);
    while (/*!ft_issort(stack_b, DESC) ||*/ *stack_a)      // Por alguna razon aqui no entra
        ft_timsort_round(stack_a, stack_b);
    debugger();
    last_moves =  ft_order_sorted_stack(stack_b, DESC); // Estan ordenados pero no totalmente en orden, el index 0 no esta el ultimo ni el index maximo esta el primero...
    ft_execute_moves(stack_a, stack_b, last_moves);
   
   
    ft_putstr_fd("Stack B: \n", 1);
    ft_print_nodes(stack_b);
    
    ft_putstr_fd("Stack A: \n", 1);
    ft_print_nodes(stack_a);


}