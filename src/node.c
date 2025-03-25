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

/**
 * Free and delete a node
 * Solo hace falta anadir mas logica como una funcion del, si el contenido 
 * anadido estaba generado por malloc
 */

void	ft_node_delone(t_node *node)
{
	free(node);
}

