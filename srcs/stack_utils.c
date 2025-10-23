#include "../includes/push_swap.h"
#include <stdlib.h>
/* -------------------------
   基本スタック操作
   ------------------------- */
void push_front(t_node **stack, int value) {
    t_node *new = malloc(sizeof(t_node));
    if (!new) exit(1);
    new->value = value;
    new->next = *stack;
    *stack = new;
}

int pop_front(t_node **stack) {
    if (!*stack) return 0;
    t_node *tmp = *stack;
    int val = tmp->value;
    *stack = tmp->next;
    free(tmp);
    return val;
}

