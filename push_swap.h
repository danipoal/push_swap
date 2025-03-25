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
void	ft_stkclear(t_node **lst);
void    ft_free_split(char **array);
t_node	*ft_nodelast(t_node *node);
void    ft_test_operations(t_node **stk);

//Operations
void    ft_swap(t_node **stk);

# endif