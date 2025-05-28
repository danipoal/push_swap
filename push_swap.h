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
# define ASC 1
# define DESC 2
# define LOW 1
# define BIG 2

typedef struct s_node 
{
	int	value;
	int index;
	struct	s_node	*next;
} t_node;

/*
 * Has the moves to be done and the node target to be moved
 */
typedef struct s_moves
{
	int	pa;
	int	pb;
	int	sa;
	int	sb;
	int	ss;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	t_node	*target;
} t_moves;


// Input handleing
int		*ft_atoi_array(char **av, int ac, int type);
void    ft_free_split(char **array);

// Utils
int 	ft_issort(t_node **stk, int sort_type);
t_node  *ft_find_node(t_node **stk, int type);
void    ft_free_moves(t_moves *moves);
void    ft_error(void);

// Node managing
t_node  *ft_create_node(int value, t_node *next);

t_node *ft_nodeprelast(t_node *node);
t_node	*ft_nodelast(t_node *node);
void    ft_print_nodes(t_node **stk);
void    debugger(void);
void    ft_debug(t_node *target, int index);


// Stack
t_node	**init_stack(int *nbrs, int size);
t_node  **ft_init_void_stack(int size);
void	ft_stkclear(t_node **lst);
int	ft_count_nodeposition(t_node **stk, t_node *node_to_search);
// int	ft_stack_size(t_node **stk);

// Operations plain
void    ft_swap(t_node **stk);
void    ft_push(t_node **stk_pushed, t_node **stk_get);
void    ft_rotate(t_node **stk);
void    ft_reverse_rotate(t_node **stk);

// Wraper opperations
void    ft_sa(t_node **stack_a);
void    ft_sb(t_node **stack_b);
void    ft_ss(t_node **stack_a, t_node **stack_b);
void	ft_pa(t_node **stack_a, t_node **stack_b);
void	ft_pb(t_node **stack_a, t_node **stack_b);
void    ft_ra(t_node **stack_a);
void    ft_rb(t_node **stack_b);
void    ft_rr(t_node **stack_a, t_node **stack_b);
void    ft_rra(t_node **stack_a);
void    ft_rrb(t_node **stack_b);
void    ft_rrr(t_node **stack_a, t_node **stack_b);

void    ft_test_operations(t_node **stk);

// Short cases
void	ft_short_cases(t_node **stk, int size);

// Radix
void    ft_radix(t_node **stack_a, int size);
int		ft_count_binary_digits(int n);
void	ft_putnbr_base(long nb, char *base);

// Timsort & utils
void    ft_timsort(t_node **stack_a, int size);
void    ft_indexate(t_node **stack_a, int size);
t_moves    *ft_order_sorted_stack(t_node **stk, int type);
t_node  *ft_find_nearest_node(t_node **stk, int value, int type);
t_moves *ft_newmoves(t_node *target);
t_moves    *ft_calculate_moves(t_node **stack_a, t_node **stack_b, t_node *target);
void    ft_execute_moves(t_node **stack_a, t_node **stack_b, t_moves *moves);
int ft_get_num_moves(t_moves *moves);

# endif