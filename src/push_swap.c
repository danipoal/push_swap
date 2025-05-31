/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:36:02 by danalvar          #+#    #+#             */
/*   Updated: 2025/05/31 14:32:12 by danalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Handle errors (suplicates, string, syntaxis, maximums....)
 *
 */
void	ft_check_input(int *numbers, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] == numbers[j])
				ft_error();
			j++;
		}
		i++;
	}
}

int	*ft_handle_args(int	argc, char **argv, int *size)
{
	char	**split_numbers;
	int		*n;

	n = NULL;
	if (argc == 2)
	{
		*size = count_words(argv[1], ' ');
		split_numbers = ft_split(argv[1], ' ');
		n = ft_atoi_array(split_numbers, *size, 0);
		ft_free_split(split_numbers);
		return (n);
	}
	else if (argc > 2)
	{
		*size = argc - 1;
		n = ft_atoi_array(argv, *size, 1);
		if (!n)
			return (NULL);
		return (n);
	}
	return (NULL);
}
/*
 * Function to handle the inputs
 * 
 */
t_node	**ft_handle_input(int argc, char **argv, int *size)
{
	int		*n;
	t_node	**stack_a;

	if (argc <= 1)
		return (NULL);
	else
		n = ft_handle_args(argc, argv, size);
	ft_check_input(n, *size);
	stack_a = init_stack(n, *size);
	if (!stack_a)
		return (NULL);
	free(n);
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_node	**stack_a;
	int		size;

	stack_a = ft_handle_input(argc, argv, &size);
	if (!stack_a)
		return (1);
	if (size >= 3 && size <= 5)
	{
		ft_short_cases(stack_a, size);
		ft_stkclear(stack_a);
		return (0);
	}
	ft_timsort(stack_a, size);
	if (!ft_issort(stack_a, ASC))
	{
		ft_putstr_fd("ERROR SORT", 1);
		ft_stkclear(stack_a);
		return (1);
	}
	ft_stkclear(stack_a);
	return (0);
}
