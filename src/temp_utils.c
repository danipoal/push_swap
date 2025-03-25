#include "../push_swap.h"


void    ft_test_operations(t_node **stk)
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

void    ft_print_nodes(t_node **stk)
{
    t_node *temp = *stk;  // Usamos una copia del puntero

    while (temp)
    {
        ft_putchar_fd('\n', 1);
        ft_putnbr_fd(temp->value, 1);
        ft_putchar_fd('\n', 1);
        temp = temp->next;
    }
}