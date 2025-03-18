/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:36:02 by danalvar          #+#    #+#             */
/*   Updated: 2025/03/18 19:57:03 by danalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../push_swap.h"

int	main(int argc, char **argv)
{
	if (argc == 2) // Split para eliminar los espacios
		write(1, *argv, 1);
	else if (argc > 2)
	{
		write(1, "No", 2);
	}
	return (0);
}
