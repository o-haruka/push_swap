#include "../includes/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void sa(t_node **a) {
    if (!*a || !(*a)->next) return;
    t_node *first = *a;
    t_node *second = (*a)->next;
    first->next = second->next;
    second->next = first;
    *a = second;
    printf("sa\n");
}

void ra(t_node **a) {
    if (!*a || !(*a)->next) return;
    t_node *first = *a;
    t_node *cur = *a;
    while (cur->next) cur = cur->next;
    *a = first->next;
    first->next = NULL;
    cur->next = first;
    printf("ra\n");
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
    printf("rra\n");
}

void pb(t_node **a, t_node **b) {
    if (!*a) return;
    int val = pop_front(a);
    push_front(b, val);
    printf("pb\n");
}

void pa(t_node **a, t_node **b) {
    if (!*b) return;
    int val = pop_front(b);
    push_front(a, val);
    printf("pa\n");
}