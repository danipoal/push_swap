#include "../push_swap.h"

void    ft_invert(t_node **stack_a, t_node **stack_b, int size)
{
    int n;

    while (*stack_a)
        ft_pb(stack_a, stack_b);
    n = 0;
    while (n < size)
    {
        ft_rb(stack_b);
        n++;
    }

    while (*stack_b) // Esto quizas se odria hacer antes
    {
        ft_rrb(stack_b);
        ft_pa(stack_a, stack_b);
        n++;
    }
    
    

}

static void    ft_radix_round(t_node **stack_a, t_node **stack_b, int index, int size)
{
    int n;

    n = 0;
    while (n < size)
    {
        if (((*stack_a)->value >> index) & 1)
            ft_pb(stack_a, stack_b);
        else
            ft_ra(stack_a);
        n++;
    }
    //ft_print_nodes(stack_b);
    while (*stack_b)
        ft_pa(stack_a, stack_b);
}

void    ft_radix(t_node **stack_a, int size)
{
    t_node  **stack_b;
    int binary_digits;
    int n;
    
    stack_b = ft_init_void_stack(size);
    if (size > 0)
    {
        binary_digits = ft_find_node(stack_a, BIG)->value;
        ft_putnbr_base(binary_digits, "01");
        ft_putstr_fd("\n", 1);
        binary_digits = ft_count_binary_digits(binary_digits);
        ft_putnbr_fd(binary_digits, 1);  
    }
    n = 0;
    while (n < binary_digits)
    {
        ft_radix_round(stack_a, stack_b, n, size);
        n++;
    }
    //ft_invert(stack_a, stack_b, size);
    ft_stkclear(stack_b);

    ft_print_nodes(stack_a);
}