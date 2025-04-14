#include "../push_swap.h"

t_moves *ft_newmoves(t_node *target)
{
    t_moves *new_tmoves;

    new_tmoves = (t_moves*) malloc (sizeof(t_moves));
    if (!new_tmoves)
        return (NULL);
    new_tmoves->target = target;
    return (new_tmoves);
}