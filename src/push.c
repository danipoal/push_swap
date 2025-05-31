/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:07:25 by danalvar          #+#    #+#             */
/*   Updated: 2025/05/31 13:10:57 by danalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * This file functions wrap the raw operations file where these are explained
 * with more detail
 */

#include "../push_swap.h"

void	ft_pa(t_node **stack_a, t_node **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_putstr_fd("pa\n", 1);
}

void	ft_pb(t_node **stack_a, t_node **stack_b)
{
	ft_push(stack_b, stack_a);
	ft_putstr_fd("pb\n", 1);
}
