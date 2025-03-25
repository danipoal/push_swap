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

int	main(int argc, char **argv)
{
	int	*n;
	t_node	**stack_a;
	int	size;

	stack_a = NULL;
	// Handle input
	if (argc == 2) // Split para eliminar los espacios
	{
		size = count_words(argv[1], ' ');
		n = ft_atoi_array(ft_split(argv[1], ' '), size, 0); //TODO De momento no prestar atencion
		stack_a = init_stack(n, size);
		ft_putnbr_fd((*stack_a)->value, 1);
		ft_putchar_fd('\n', 1);
	}
	else if (argc > 2)
	{
		n = ft_atoi_array(argv, argc - 1, 1);
		if (!n)
		{
			write(1, "Error", 5);
			return (1);
		}
		stack_a = init_stack(n, argc - 1);
		if (!stack_a)
			ft_putstr_fd("\nError al iniciar stack\n", 1);
		ft_putnbr_fd((*stack_a)->value, 1);
		ft_putchar_fd('\n', 1);
	}
	else
		return (1);
	ft_print_nodes(stack_a);
	// Handle errors (suplicates, string, syntaxis, maximums....)

	// Initialize stack a puting the argv and b
	// Check if is sorted, if not implement algorythm
	return (0);
}
