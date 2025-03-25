#include "../push_swap.h"

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