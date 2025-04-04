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
 * Function to handle the inputs
 * 
 */
t_node  **ft_handle_input(int argc, char **argv, int *size)
{
	int	*n;
	t_node	**stack_a;
	char	**split_numbers;

	if (argc <= 1)
		return (NULL);
	else if (argc == 2) // Split para eliminar los espacios
	{
		*size = count_words(argv[1], ' ');
		split_numbers = ft_split(argv[1], ' ');
		n = ft_atoi_array(split_numbers, *size, 0);
		ft_free_split(split_numbers); // Hay qye hacer free de todo el split por dentro
	}
	else if (argc > 2)
	{
		*size = argc - 1;
		n = ft_atoi_array(argv, *size, 1);
		if (!n)
			return (NULL);
	}
	stack_a = init_stack(n, *size);
	if (!stack_a)
	{
		ft_putstr_fd("\nError al iniciar stack\n", 1);	// Delete this lines to fit 25 lines
		return (NULL);
	}
	free(n);
	return (stack_a);
}

// Handle errors (suplicates, string, syntaxis, maximums....)

// Initialize stack a puting the argv and b
// Check if is sorted, if not implement algorythm
int	main(int argc, char **argv)
{
	t_node	**stack_a;
	int	size;

	// Handle input
	stack_a = ft_handle_input(argc, argv, &size);
	if (!stack_a)
		return (1);
	if (size >= 3 && size <= 5)
	{
		ft_short_cases(stack_a, size);
		ft_print_nodes(stack_a);
		ft_stkclear(stack_a);
		return (0);
	}
	//ft_print_nodes(stack_a);

	
	//ft_test_operations(stack_a);
	//ft_radix(stack_a, size);

	ft_timsort(stack_a, size);
	ft_stkclear(stack_a);
	return (0);
}