/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 14:04:55 by danalvar          #+#    #+#             */
/*   Updated: 2025/05/31 14:04:58 by danalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * This file functions wrap the raw operations file where these are explained
 * with more detail
 */

#include "../push_swap.h"

void	ft_rra(t_node **stack_a)
{
	ft_reverse_rotate(stack_a);
	ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_node **stack_b)
{
	ft_reverse_rotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_node **stack_a, t_node **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
}
