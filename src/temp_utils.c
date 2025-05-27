#include "../push_swap.h"

void    ft_test_operations(t_node **stk)
{
    t_node  **stack_b;
    stack_b = ft_init_void_stack(4);

    //ft_reverse_rotate(stk);
    ft_rra(stk);
    //ft_pa(stk, stack_b);

    ft_print_nodes(stk);
    ft_stkclear(stack_b);
}

/*
 * Printea todos los nodos de una lista para compribar su estado
 * Usamos una copia del puntero para no editar 
 *  los punteros originales
 */

void    ft_print_nodes(t_node **stk)
{
    t_node *temp = *stk;

    ft_putchar_fd('\n', 1);
    while (temp)
    {
        ft_putnbr_fd(temp->value, 1);
        ft_putstr_fd(" Index: ", 1);
        ft_putnbr_fd(temp->index, 1);
        ft_putchar_fd('\n', 1);
        temp = temp->next;
    }
    ft_putchar_fd('\n', 1);
}

void    debugger(void) 
{
    return ;
}

void    ft_debug(t_node *target, int index)
{
    if (target->index == index)
        debugger();
}
/*
    push test
void ft_test_operations(t_node **stk)
{
    t_node **new_stk;

    new_stk = ft_init_void_stack(2);

    // From stk to new stk
    ft_push(new_stk, stk);
    ft_push(new_stk, stk);
    ft_print_nodes(new_stk);
    ft_push(stk, new_stk);
    ft_push(stk, new_stk);
    ft_stkclear(new_stk);
}
*/