#include "../includes/push_swap.h"
#include "../libft/stdio/ft_printf/ft_printf.h"

// #include <stdio.h>
#include <stdlib.h>

//先頭2つの要素を入れ替える
void sa(t_node **a) {
    if (!*a || !(*a)->next) return;
    t_node *first = *a;
    t_node *second = (*a)->next;
    first->next = second->next;
    second->next = first;
    *a = second;
    ft_printf("sa\n");
}

void ra(t_node **a) {
    if (!*a || !(*a)->next) return;
    t_node *first = *a;
    t_node *cur = *a;
    while (cur->next) 
        cur = cur->next;
    *a = first->next;
    first->next = NULL;
    cur->next = first;
    ft_printf("ra\n");
}

void rra(t_node **a) {
    if (!*a || !(*a)->next) return;
    t_node *cur = *a;
    t_node *prev = NULL;
    while (cur->next) {
        prev = cur;
        cur = cur->next;
    }
    prev->next = NULL;
    cur->next = *a;
    *a = cur;
    ft_printf("rra\n");
}

void pb(t_node **a, t_node **b) {
    if (!*a) return;
    int val = pop_front(a);
    push_front(b, val);
    ft_printf("pb\n");
}

void pa(t_node **a, t_node **b) {
    if (!*b) return;
    int val = pop_front(b);
    push_front(a, val);
    ft_printf("pa\n");
}
