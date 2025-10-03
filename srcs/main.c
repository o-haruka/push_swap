#include "../libft/includes/libft.h"
#include "../includes/push_swap.h"

#include <stdio.h>
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


/* -------------------------
   小さいケース用
   ------------------------- */
int list_size(t_node *a) {
    int n = 0;
    while (a) { n++; a = a->next; }
    return n;
}

void sort_three(t_node **a) {
    int x = (*a)->value;
    int y = (*a)->next->value;
    int z = (*a)->next->next->value;

    if (x > y && y < z && x < z)         // 2 1 3
        sa(a);
    else if (x > y && y > z)             // 3 2 1
    { sa(a); rra(a); }
    else if (x > y && y < z && x > z)    // 3 1 2
        ra(a);
    else if (x < y && y > z && x < z)    // 1 3 2
    { sa(a); ra(a); }
    else if (x < y && y > z && x > z)    // 2 3 1
        rra(a);
}

int find_min_pos(t_node *a) {
    int pos = 0, min_pos = 0;
    int min = a->value;
    t_node *cur = a;
    while (cur) {
        if (cur->value < min) {
            min = cur->value;
            min_pos = pos;
        }
        cur = cur->next;
        pos++;
    }
    return min_pos;
}

/* 汎用：サイズが3になるまで最小値をpbする（size<=5用） */
void sort_small(t_node **a, t_node **b) {
    while (list_size(*a) > 3) {
        int pos = find_min_pos(*a);
        int sz = list_size(*a);
        if (pos == 0) {
            pb(a, b);
        } else if (pos <= sz / 2) {
            while (pos-- > 0)
                ra(a);
            pb(a, b);
        } else {
            int steps = sz - pos;
            while (steps-- > 0)
                rra(a);
            pb(a, b);
        }
    }
    if (list_size(*a) == 2) {
        if ((*a)->value > (*a)->next->value)
            sa(a);
    } else { // size == 3
        sort_three(a);
    }
    while (*b)
        pa(a, b);
}

/* -------------------------
   Radix sort 用補助
   ------------------------- */
int get_max(t_node *a) {
    int max = a->value;
    while (a) {
        if (a->value > max)
            max = a->value;
        a = a->next;
    }
    return max;
}

/* O(n^2) だが n<=500 なので十分 */
void index_stack(t_node *a, int *arr, int size) {
    for (int i = 0; i < size; i++) {
        int rank = 0;
        for (int j = 0; j < size; j++) {
            if (arr[j] < arr[i])
                rank++;
        }
        a->value = rank;
        a = a->next;
    }
}

void radix_sort(t_node **a, t_node **b, int size) {
    int max = get_max(*a);
    int max_bits = 0;
    while ((max >> max_bits) != 0)
        max_bits++;

    for (int i = 0; i < max_bits; i++) {
        for (int j = 0; j < size; j++) {
            int num = (*a)->value;
            if (((num >> i) & 1) == 0)
                pb(a, b);
            else
                ra(a);
        }
        while (*b)
            pa(a, b);
    }
}

/* -------------------------
   main
   ------------------------- */
int main(int argc, char **argv) {
    if (argc < 2) return 0;

    t_node *a = NULL;
    t_node *b = NULL;

    int size = argc - 1;
    int *arr = malloc(sizeof(int) * size);
    if (!arr) return 1;

    // 配列に変換して保存
    int i = 0;
    while(i < size){
        arr[i] = ft_atoi(argv[i + 1]);
        i++;
    }

    // スタックAに逆順で追加
    int j = size - 1;
    while(0 <= j){
        push_front(&a, arr[j]);
        j--;
    }

    /* 値を順位（0..size-1）に変換 */
    index_stack(a, arr, size);

    if (size == 1) {
        /* nothing */
    } else if (size == 2) {
        if (a->value > a->next->value)
            sa(&a);
    } else if (size <= 5) {
        sort_small(&a, &b);
    } else {
        radix_sort(&a, &b, size);
    }

    free(arr);
    return 0;
}