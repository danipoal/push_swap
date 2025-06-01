/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timsort_moves_exec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 14:29:15 by danalvar          #+#    #+#             */
/*   Updated: 2025/05/31 16:30:38 by danalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
 * Instanziate a new t_moves struct
 * @param target - The node set as the target to be pushed
 */
t_moves	*ft_newmoves(t_node *target)
{
	t_moves	*new_tmoves;

	new_tmoves = (t_moves *) malloc(sizeof(t_moves));
	if (!new_tmoves)
		return (NULL);
	new_tmoves->sa = 0;
	new_tmoves->sb = 0;
	new_tmoves->ra = 0;
	new_tmoves->rb = 0;
	new_tmoves->rra = 0;
	new_tmoves->rrb = 0;
	new_tmoves->ss = 0;
	new_tmoves->rr = 0;
	new_tmoves->rrr = 0;
	new_tmoves->pa = 0;
	new_tmoves->pb = 0;
	new_tmoves->target = target;
	return (new_tmoves);
}

/*
 * Executes only one move for facilitate the execute moves global function
 * Used for ss, rr, rrr, pa, pb
 */
void	ft_exec_one_move(t_node **stack_a, t_node **stack_b,
		int *moves, void (*f)(t_node**, t_node**))
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
void	ft_exec_one_move_s(t_node **stk, int *moves, void (*f)(t_node **))
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
void	ft_execute_moves(t_node **stack_a, t_node **stack_b, t_moves *moves)
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
