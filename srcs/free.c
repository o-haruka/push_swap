#include "../includes/push_swap.h"
#include <stdlib.h>

void	free_split_array(char **arr)
{
    int	i;

    if (!arr)
        return;
    i = 0;
    while (arr[i])
        free(arr[i++]);
    free(arr);
}

void free_stack(t_node **stack) {
    while (*stack) {
        t_node *tmp = *stack;
        *stack = (*stack)->next;
        free(tmp);
    }
}