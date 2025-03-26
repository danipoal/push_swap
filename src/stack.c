#include "../push_swap.h"

/*
 * Initialization for the input stack
 * Initialize the a stack as a linked list
 * The function create_node() Asigns directly the next node if is started by
 *  the end of the list
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

/*
 * Initialize an empty stack with NULL initialized values
 * Same size as the original imput
 */
t_node  **ft_init_void_stack(int size)
{
	t_node	**stk;
    int i;

	stk = (t_node**) malloc(size * sizeof(t_node*));  
	if (!stk)
		return (NULL);
    i = 0;
    while (i < size)
    {
        stk[i] = NULL;
        i++;
    }
	return (stk);
}