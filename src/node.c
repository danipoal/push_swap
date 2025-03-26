#include "../push_swap.h"

/**
 * Creates a new node that can be asigned at the top o a stack
 * 
 */

t_node  *ft_create_node(int value, t_node *next)
{
    t_node  *new_node;

    new_node = (t_node*) malloc(sizeof(t_node));
    if (!new_node)
        return (NULL);
    new_node->value = value;
    if (!next)
        new_node->next = NULL;
    else
        new_node->next = next;
    return (new_node);
}

/*
 * Gets the second last element of a stack
 * 
*/
t_node *ft_nodeprelast(t_node *node)
{
	t_node	*tmp;
	t_node	*prev;

	if (!node)
		return (NULL);
	tmp = node;
	while (tmp->next)
	{
		if (tmp->next)
			prev = tmp;
		tmp = tmp->next;
	}
	return (prev);
}

/*
 * Gets the last element of a stack
 *
*/
t_node	*ft_nodelast(t_node *node)
{
	t_node	*tmp;

	if (!node)
		return (NULL);
	tmp = node;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

/**
 * Free and delete a node
 * Solo hace falta anadir mas logica como una funcion del, si el contenido 
 * anadido estaba generado por malloc
 */

void	ft_node_delone(t_node *node)
{
	free(node);
}

void	ft_stkclear(t_node **lst)
{
	t_node	*tmp;

	tmp = *lst;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_node_delone(*lst);
		*lst = tmp;
	}
	free(lst);
}