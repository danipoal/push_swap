#include "../push_swap.h"


void    ft_test_operations(t_node **stk)
{
    ft_swap(stk);
    ft_print_nodes(stk);
}

void    ft_print_nodes(t_node **stk)
{
    t_node *temp = *stk;  // Usamos una copia del puntero

    while (temp)
    {
        ft_putnbr_fd(temp->value, 1);
        ft_putchar_fd('\n', 1);
        temp = temp->next;
    }
}