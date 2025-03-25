#include "../push_swap.h"

/*
 * Swap the first two nodes of a stack
 * Asigns the nexts nodes that are gonna be used, and swap
 */
void    ft_swap(t_node **stk)
{
    t_node  *tmp;
    t_node  *third_node;

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
 */
void    ft_push(t_node **stk_pushed, t_node **stk_get)
{
    t_node  *tmp;

    tmp = *stk_get;
    *stk_get = (*stk_get)->next;  
    tmp->next = *stk_pushed;
    *stk_pushed = tmp;
}
//TODO No se si es correcto pero de momento si se queda vacio el stack, se pone en NULL que es ell next