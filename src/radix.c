/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 14:16:09 by danalvar          #+#    #+#             */
/*   Updated: 2025/05/31 14:16:12 by danalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
 * Inverts an stack and also if the negative numbers re on the bottom
 * rotates them to the top
 */
void	ft_invert(t_node **stack_a, t_node **stack_b, int size)
{
	int	n;

	while (*stack_a)
		ft_pb(stack_a, stack_b);
	n = 0;
	while (n < size)
	{
		ft_rb(stack_b);
		n++;
	}
	while (*stack_b)
	{
		ft_rrb(stack_b);
		ft_pa(stack_a, stack_b);
		n++;
	}
	while (ft_nodelast(*stack_a)->value < 0)
		ft_rra(stack_a);
}

/*
 * Separate the numbers for each binary digit if it has a 1
 */
void	ft_radix_round(t_node **stack_a, t_node **stack_b, int index, int size)
{
	int	n;

	n = 0;
	while (n < size)
	{
		if (((unsigned int)(*stack_a)->value >> index) & 1)
			ft_pb(stack_a, stack_b);
		else
			ft_ra(stack_a);
		n++;
	}
	while (*stack_b)
		ft_pa(stack_a, stack_b);
}

/*
 * Implments Radix sort algorithm w/ no optimization
 * 
 * Finds the bigest binary number either negative or positive
 * Implement the sort n binary digits times + sign bit
 * It orders descendent but we want asc so we invert it
 * And the negatives are in the bottom, mus be rra.
*/
void	ft_radix(t_node **stack_a, int size)
{
	t_node	**stack_b;
	int		binary_digits;
	int		n;

	stack_b = ft_init_void_stack(size);
	binary_digits = ft_find_node(stack_a, BIG)->value;
	if (binary_digits < -ft_find_node(stack_a, LOW)->value)
		binary_digits = ft_find_node(stack_a, LOW)->value;
	binary_digits = ft_count_binary_digits(binary_digits);
	n = 0;
	while (n < binary_digits)
	{
		ft_radix_round(stack_a, stack_b, n, size);
		n++;
	}
	ft_invert(stack_a, stack_b, size);
	ft_stkclear(stack_b);
	ft_print_nodes(stack_a);
}
