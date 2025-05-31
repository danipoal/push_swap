/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:34:24 by danalvar          #+#    #+#             */
/*   Updated: 2025/05/31 13:35:57 by danalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
 * Sorts the stack if it has 3 elements
 * If we work with the last_node, we have to reset it again to find 
 *  the new last node
 * case1 -> 321 ra-> 231 rra->123
 * Worst -> 132 rra-> 231 rra-> 123
 */
void	ft_sort_three(t_node **stack_a, int sort_type)
{
	while (!ft_issort(stack_a, sort_type))
	{
		if (sort_type == ASC)
		{
			if ((*stack_a)->value > (*stack_a)->next->value)
				ft_sa(stack_a);
		}
		else if (sort_type == DESC)
		{
			if ((*stack_a)->value > (*stack_a)->next->value)
				ft_sa(stack_a);
		}
		if (!ft_issort(stack_a, sort_type))
			ft_rra(stack_a);
	}
}

/*
 * Sorts the stack if it has 4 elements
 * Finds the lowest, and then move it to B, then sort the rest
 * Rotate until the 1st element is the lowest, then push to b, sort and return
 */
static void	ft_case_four(t_node **stack_a)
{
	t_node	**stack_b;
	t_node	*lowest;

	stack_b = ft_init_void_stack(1);
	lowest = ft_find_node(stack_a, LOW);
	while ((*stack_a)->value != lowest->value)
		ft_ra(stack_a);
	ft_pb(stack_a, stack_b);
	ft_sort_three(stack_a, ASC);
	ft_pa(stack_a, stack_b);
	ft_stkclear(stack_b);
}

/*
 * Sorts the stack if it has 5 elements
 * Duplicated code push the lowest
 */
static void	ft_case_five(t_node **stack_a)
{
	t_node	**stack_b;
	t_node	*lowest;

	stack_b = ft_init_void_stack(2);
	lowest = ft_find_node(stack_a, LOW);
	while ((*stack_a)->value != lowest->value)
		ft_ra(stack_a);
	ft_pb(stack_a, stack_b);
	lowest = ft_find_node(stack_a, LOW);
	while ((*stack_a)->value != lowest->value)
		ft_ra(stack_a);
	ft_pb(stack_a, stack_b);
	ft_sort_three(stack_a, ASC);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
	ft_stkclear(stack_b);
}

/*
 * Redirect to the exact short cases
 *
 */
void	ft_short_cases(t_node **stk, int size)
{
	if (!stk || !size)
		return ;
	if (size == 3)
		ft_sort_three(stk, ASC);
	else if (size == 4)
		ft_case_four(stk);
	else if (size == 5)
		ft_case_five(stk);
}
