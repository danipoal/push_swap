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


int	*parsing(int ac, char **av)
{
	int	*numbers;

	numbers = (int *) malloc(ac * sizeof(int));
	if (!numbers)
		return (NULL);
	ac = 2;
	numbers[0] = ft_atoi(av[ac]);
	return (numbers);
}

void	init_stack(t_node **stk, int *nbrs, int size)
{
	if (size > 0)
		*stk = ft_create_node(nbrs[0], NULL);
	if (!*stk)
		return ;
}

int	main(int argc, char **argv)
{
	int	*n;
	t_node	*stack_a;

	// Handle input
	if (argc == 2) // Split para eliminar los espacios
	{
		n = ft_atoi_ptr(ft_split(argv[1], ' '), argc - 1);
		init_stack(&stack_a, n, argc);
		ft_putnbr_fd(stack_a->value, 1);
		ft_putchar_fd('\n', 1);
	}
	else if (argc > 2)
	{
		write(1, "No", 2);
		n = parsing(argc, argv);
		if (!n)
		{
			write(1, "Error", 5);
			return (1);
		}
		init_stack(&stack_a, n, argc);
		ft_putnbr_fd(stack_a->value, 1);
		ft_putchar_fd('\n', 1);
	}

	// Handle errors (suplicates, string, syntaxis, maximums....)

	// Initialize stack a puting the argv and b
	// Check if is sorted, if not implement algorythm
	return (0);
}
