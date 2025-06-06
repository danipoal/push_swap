/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 14:26:00 by danalvar          #+#    #+#             */
/*   Updated: 2025/05/31 14:26:02 by danalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
 * Gets the size of the stack
 */

int	ft_stack_size(t_node **stk)
{
	int		i;
	t_node	*tmp;

	tmp = *stk;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

/*
 * Counts and get the position of a node into a stack
 *
 */
int	ft_count_nodeposition(t_node **stk, t_node *node_to_search)
{
	t_node	*tmp;
	int		count;

	count = 0;
	tmp = *stk;
	while (tmp != node_to_search)
	{
		tmp = tmp->next;
		count++;
		if (!tmp)
			return (-1);
	}
	return (count);
}

/*
 * Initialization for the input stack
 * Initialize the a stack as a linked list
 * The function create_node() Asigns directly the next node if is started by
 *  the end of the list
 *	Initialize the max value -1 because we start in 0
 */
t_node	**init_stack(int *nbrs, int size)
{
	t_node	**stk;

	stk = (t_node **) malloc(size * sizeof(t_node *));
	if (!stk)
		return (NULL);
	size = size - 1;
	stk[size] = ft_create_node(nbrs[size], NULL);
	if (!stk[size])
		return (NULL);
	size--;
	while (size >= 0)
	{
		stk[size] = ft_create_node(nbrs[size], stk[size + 1]);
		if (!stk[size])
			return (NULL);
		size--;
	}
	return (stk);
}

/*
 * Initialize an empty stack with NULL initialized values
 * Same size as the original imput
 */
t_node	**ft_init_void_stack(int size)
{
	t_node	**stk;
	int		i;

	stk = (t_node **) malloc(size * sizeof(t_node *));
	if (!stk)
		return (NULL);
	i = 0;
	while (i < size)
	{
		stk[i] = NULL;
		i++;
	}
	return (stk);
}
