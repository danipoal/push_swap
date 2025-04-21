#include "../push_swap.h"

/*
 * Count the total number of moves indistinct
 * Used for comparing t_moves and get the best
 */
int ft_get_num_moves(t_moves *moves)    // TODO ERROR - Dont delete by reference
{
    int n;

    n = 0;
    while (moves->pa--)
        n++;
    while (moves->pb--)
        n++;
    while (moves->sa--)
        n++;
    while (moves->sb--)
        n++;
    while (moves->ss--)
        n++;
    while (moves->ra--)
        n++;
    while (moves->rb--)
        n++;
    while (moves->rr--)
        n++;
    while (moves->rra--)
        n++;
    while (moves->rrb--)
        n++;   
    while (moves->rrr--)
        n++;   
    return (n);
}

/*
 * Instanziate a new t_moves struct
 * @param target - The node set as the target to be pushed
 */
t_moves *ft_newmoves(t_node *target)
{
    t_moves *new_tmoves;

    new_tmoves = (t_moves*) malloc (sizeof(t_moves));
    if (!new_tmoves)
        return (NULL);
    new_tmoves->target = target;
    return (new_tmoves);
}

/*
 * Executes only one move for facilitate the execute moves global function
 * Used for ss, rr, rrr, pa, pb
 */
void    ft_exec_one_move(t_node **stack_a, t_node **stack_b, int *moves , void (*f)(t_node**, t_node **))
{
    while (*moves > 0)
    {
        f(stack_a, stack_b);
        (*moves)--;
    }
}

/*
 * Same as the top function but for only one parameter into the function
 * Used for sa, sb, ra, rb, rra, rrb
 */
void    ft_exec_one_move_s(t_node **stk, int *moves , void (*f)(t_node**))
{
    while (*moves > 0)
    {
        f(stk);
        (*moves)--;
    }
}

/*
 * Given a serie of moves, execute it into both stacks
 * @params moves - To execute
 * Execute in order with priority for rotates and swaps, last pushes
 * -- To revise the order if sa are implemented
 */
void    ft_execute_moves(t_node **stack_a, t_node **stack_b, t_moves *moves)
{
    ft_exec_one_move_s(stack_a, &(moves->sa), ft_sa);
    ft_exec_one_move_s(stack_b, &(moves->sb), ft_sb);
    ft_exec_one_move_s(stack_a, &(moves->ra), ft_ra);
    ft_exec_one_move_s(stack_b, &(moves->rb), ft_rb);
    ft_exec_one_move_s(stack_a, &(moves->rra), ft_rra);
    ft_exec_one_move_s(stack_b, &(moves->rrb), ft_rrb);
    ft_exec_one_move(stack_a, stack_b, &(moves->ss), ft_ss);
    ft_exec_one_move(stack_a, stack_b, &(moves->rr), ft_rr);
    ft_exec_one_move(stack_a, stack_b, &(moves->rrr), ft_rrr);
    ft_exec_one_move(stack_a, stack_b, &(moves->pa), ft_pa);
    ft_exec_one_move(stack_a, stack_b, &(moves->pb), ft_pb);
}

