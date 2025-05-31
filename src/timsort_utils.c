/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timsort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:54:56 by danalvar          #+#    #+#             */
/*   Updated: 2025/05/31 13:57:28 by danalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
 * Orders a sorted stack that have not the lowest/biggest 
 *  node in its correct place
 * Example: 8 9 1 2 3 4 5 6 7 (Is sorted as a circle but not in its position)
 * 
 * @param stk - Sorted Stack to correct and order
 * @param type - Order ASC or DESCENDING
 * Note that the function finds the correct option to ra or rb searching index 0
 ********** NOTES*********
 *Finds the index 0 and the size of the stack
 *Hardcoded for desc... (Desc index->0 has to be in the last place, 
 *	in ASC index->0 in the first)
 *
 *
 * if (type == DESC)	(eliminado este desc y lo pongo abajo para que no pete)
 * Calculo para ver si es mejor hacer el rotate hacie un lado o hacia el otro
 *
 * if (type == ASC)			 TODO if necesary, pero de momento no.
 * TODO Cambiar esto en funcion a parte, para ver si ya se ordena en el stack A
 * ft_execute_moves(NULL, stk, moves);   // Harcoded only for stack B
*/
t_moves	*ft_order_sorted_stack(t_node **stk, int type)
{
	t_moves	*moves;
	t_node	*tmp;
	int		count;
	int		zero_index_position;

	count = 0;
	moves = ft_newmoves(NULL);
	tmp = *stk;
	while (tmp)
	{
		if (tmp->index == 0)
			zero_index_position = count;
		tmp = tmp->next;
		count++;
	}
	if (count - zero_index_position < count / 2 && type == DESC)
		moves->rrb = count - zero_index_position - 1;
	else
		moves->rb = zero_index_position + 1;
	moves->pa = count;
	return (moves);
}

/*
 * Finds nearest node given a value. 
 * Can find the nearest big or low.
 * 
 * value - current_closest->value == Descendente (LOW)
 * current_closest->value - value == Ascendente (BIG)
 * 2 comprobaciones, 1 que el diff sea menor, pero que el value 
 *	siga siendo mayor (ASC-BIG)
 */
t_node	*ft_find_nearest_node(t_node **stk, int value, int type)
{
	t_node	*tmp;
	t_node	*current_closest;
	int		current_diff;

	tmp = *stk;
	current_diff = INT_MAX;
	while (tmp)
	{
		if (type == BIG && current_diff > tmp->value - value
			&& value < tmp->value)
		{
			current_closest = tmp;
			current_diff = tmp->value - value;
		}
		else if (type == LOW && current_diff > value - tmp->value
			&& value > tmp->value)
		{
			current_closest = tmp;
			current_diff = value - tmp->value;
		}
		tmp = tmp->next;
	}
	return (current_closest);
}

/*
 * Inserts the index of the nodes, its real 
 */
void	ft_indexate(t_node **stack_a, int size)
{
	int		n;
	t_node	*lowest_unasigned;

	lowest_unasigned = ft_find_node(stack_a, LOW);
	n = 0;
	while (n < size)
	{
		lowest_unasigned->index = n;
		lowest_unasigned = ft_find_nearest_node(stack_a,
				lowest_unasigned->value, BIG);
		n++;
	}
}
