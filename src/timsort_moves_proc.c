/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timsort_moves_proc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 14:29:15 by danalvar          #+#    #+#             */
/*   Updated: 2025/05/31 16:17:44 by danalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	*ft_get_moves_pushswaps(t_moves *temp_moves, int *n)
{
	while (temp_moves->pa-- > 0)
		(*n)++;
	while (temp_moves->pb-- > 0)
		(*n)++;
	while (temp_moves->sa-- > 0)
		(*n)++;
	while (temp_moves->sb-- > 0)
		(*n)++;
	while (temp_moves->ss-- > 0)
		(*n)++;
	return (n);
}

static int	*ft_get_moves_rotates(t_moves *temp_moves, int *n)
{
	while (temp_moves->ra-- > 0)
		(*n)++;
	while (temp_moves->rb-- > 0)
		(*n)++;
	while (temp_moves->rr-- > 0)
		(*n)++;
	while (temp_moves->rra-- > 0)
		(*n)++;
	while (temp_moves->rrb-- > 0)
		(*n)++;
	while (temp_moves->rrr-- > 0)
		(*n)++;
	return (n);
}

/*
 * Count the total number of moves indistinct
 * Used for comparing t_moves and get the best
 */
int	ft_get_num_moves(t_moves *moves)
{
	t_moves	temp_moves;

	temp_moves = *moves;
	n = 0;
	ft_get_moves_pushswaps(&temp_moves, &n);
	ft_get_moves_rotates(&temp_moves, &n);
	return (n);
}
