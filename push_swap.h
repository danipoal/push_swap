/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:38:04 by danalvar          #+#    #+#             */
/*   Updated: 2025/03/18 21:49:24 by danalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_node 
{
	int	value;
	struct	s_node	*next;
} t_node;

int	*ft_atoi_array(char **av, int ac, int type);
t_node  *ft_create_node(int value, t_node *next);
void    ft_print_nodes(t_node **stk);

# endif