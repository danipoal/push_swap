#include "../push_swap.h"

/*
 * Swap the first two nodes of a stack
 * Asigns the nexts nodes that are gonna be used, and swap
 */
void	ft_swap(t_node **stk)
{
	t_node	*tmp;
	t_node	*third_node;

	tmp = (*stk)->next;
	third_node = tmp->next;
	tmp->next = *stk;
	(*stk)->next = third_node;
	*stk = tmp;
}

/*
 * Pushes the first element of a stack into the top of another stack
 * pa -> First of B to A
 * pb -> First of A to B
 * @param stk_pushed -> the stack which is going to be pushed
 * @param stk_get -> the stack that pops the node
 * 
 * We get the node moved in tmp, and asign the new top its next
 * We move it assigning its new next to the top of new list
 * And finally asign the node as the new top
 * TODO No se si es correcto pero de momento si se queda vacio el stack, se pone en NULL que es ell next
 */
void	ft_push(t_node **stk_pushed, t_node **stk_get)
{
	t_node	*tmp;

	tmp = *stk_get;
	*stk_get = (*stk_get)->next;
	tmp->next = *stk_pushed;
	*stk_pushed = tmp;
}

/*
 * Rotate the first node to the last
 *
 * Assign lastnode next the fist old node
 * Asign the top of the stack, the nexts old first node
 * Asig the new last node (old first) the next as NULL
 */
void	ft_rotate(t_node **stk)
{
	t_node	*last_node;
	t_node	*first_node;

	if (!stk || !(*stk) || !((*stk)->next))
		return ;
	last_node = ft_nodelast(*stk);
	last_node->next = *stk;
	first_node = *stk;
	*stk = (*stk)->next;
	first_node->next = NULL;
}

/*
 * Rotate the last node to the first
 *
 * Asign the last node next the current first node
 * Asig the prev last node as a NULL nexts
 * Move the last node to 1st asigning it to the stk pointer
 */
void	ft_reverse_rotate(t_node **stk)
{
	t_node	*last_node;
	t_node	*prelast_node;

	if (!stk || !(*stk) || !((*stk)->next))
		return ;
	prelast_node = ft_nodeprelast(*stk);
	last_node = prelast_node->next;
	last_node->next = *stk;
	prelast_node->next = NULL;
	*stk = last_node;
}
