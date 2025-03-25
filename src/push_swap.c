/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:36:02 by danalvar          #+#    #+#             */
/*   Updated: 2025/03/19 17:15:03 by danalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
 * Initialize the a stack, Malloc stack, init last node and the others pointing
 */
t_node	**init_stack(int *nbrs, int size)
{
	t_node	**stk;

	stk = (t_node**) malloc(size * sizeof(t_node*));  
	if (!stk)
		return (NULL);
	size = size - 1;	//Initialize the max value -1 because we start in 0
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
 * Function to handle the inputs
 * 
 */
t_node  **ft_handle_input(int argc, char **argv)
{
	int	*n;
	t_node	**stack_a;
	char	**split_numbers;
	int	size;

	if (argc <= 1)
		return (NULL);
	else if (argc == 2) // Split para eliminar los espacios
	{
		size = count_words(argv[1], ' ');
		split_numbers = ft_split(argv[1], ' ');
		n = ft_atoi_array(split_numbers, size, 0);
		ft_free_split(split_numbers); // Hay qye hacer free de todo el split por dentro
	}
	else if (argc > 2)
	{
		size = argc - 1;
		n = ft_atoi_array(argv, size, 1);
		if (!n)
			return (NULL);
	}
	stack_a = init_stack(n, size);
	if (!stack_a)
	{
		ft_putstr_fd("\nError al iniciar stack\n", 1);	// Delete this lines to fit 25 lines
		return (NULL);
	}
	free(n);
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_node	**stack_a;

	// Handle input
	stack_a = ft_handle_input(argc, argv);
	if (!stack_a)
		return (1);
	ft_print_nodes(stack_a);
	// Handle errors (suplicates, string, syntaxis, maximums....)

	// Initialize stack a puting the argv and b
	// Check if is sorted, if not implement algorythm
	
	ft_test_operations(stack_a);

	ft_stkclear(stack_a);
	return (0);
}