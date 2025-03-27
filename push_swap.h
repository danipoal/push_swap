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

// Input handleing
int	*ft_atoi_array(char **av, int ac, int type);
void    ft_free_split(char **array);

// Node managing
t_node  *ft_create_node(int value, t_node *next);

t_node *ft_nodeprelast(t_node *node);
t_node	*ft_nodelast(t_node *node);
void    ft_print_nodes(t_node **stk);


// Stack
t_node	**init_stack(int *nbrs, int size);
t_node  **ft_init_void_stack(int size);
void	ft_stkclear(t_node **lst);

// Operations plain
void    ft_swap(t_node **stk);
void    ft_push(t_node **stk_pushed, t_node **stk_get);
void    ft_rotate(t_node **stk);
void    ft_reverse_rotate(t_node **stk);

// Wraper opperations
void    ft_sa(t_node **stack_a);
void    ft_sb(t_node **stack_b);
void    ft_ss(t_node **stack_a, t_node **stack_b);
void   ft_pa(t_node **stack_a, t_node **stack_b);
void   ft_pb(t_node **stack_a, t_node **stack_b);
void    ft_ra(t_node **stack_a);
void    ft_rb(t_node **stack_b);
void    ft_rr(t_node **stack_a, t_node **stack_b);
void    ft_rra(t_node **stack_a);
void    ft_rrb(t_node **stack_b);
void    ft_rrr(t_node **stack_a, t_node **stack_b);

void    ft_test_operations(t_node **stk);

# endif