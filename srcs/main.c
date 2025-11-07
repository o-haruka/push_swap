#include "../libft/includes/libft.h"
#include "../libft/stdio/ft_printf/ft_printf.h"
#include "../includes/push_swap.h"
#include <stdlib.h>



/* -------------------------
   小さいケース用
   ------------------------- */
int list_size(t_node *a) {
    int n = 0;
    while (a) {
        n++;
        a = a->next;
    }
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
    int pos;
    int min_pos;
    int min;

    t_node *cur;
    pos = 0;
    min_pos = 0;
    min = a->value;
    cur = a;
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
    int i = 0;
    while (i < size) {
        int rank = 0;
        int j = 0;
        while (j < size) {
            if (arr[j] < arr[i])
                rank++;
            j++;
        }
        a->value = rank;
        a = a->next;
        i++;
    }
}

void radix_sort(t_node **a, t_node **b, int size) {
    int max = get_max(*a);
    int max_bits = 0;
    while ((max >> max_bits) != 0)
        max_bits++;

    int i = 0;
    while (i < max_bits) {
        int j = 0;
        while (j < size) {
            int num = (*a)->value;
            if (((num >> i) & 1) == 0)
                pb(a, b);
            else
                ra(a);
            j++;
        }
        while (*b)
            pa(a, b);
        i++;
    }
}

/* -------------------------
   main整頓用関数
   ------------------------- */
// int配列からスタックAを逆順で初期化
void init_stack_a(t_node **a, int *arr, int size) {
    int j;
    j = size - 1;
    while(0 <= j){
        push_front(a, arr[j]);
        j--;
    }
}

// ソート処理を分岐して実行
void do_sort(t_node **a, t_node **b, int size) {
    if (size == 1) {
        /* nothing */
    } else if (size == 2) {
        if ((*a)->value > (*a)->next->value)
            sa(a);
    } else if (size <= 5) {
        sort_small(a, b);
    } else {
        radix_sort(a, b, size);
    }
}

static int parse_args_split(char *arg, int **arr, int *size) {
    char **split = ft_split(arg, ' ');
    if (!split)
        return 1;
    *size = 0;
    while (split[*size])
        (*size)++;
    if (*size == 0) {
        free(split);
        return 1;
    }
    *arr = malloc(sizeof(int) * (*size));
    if (!*arr) {
        free_split_array(split);
        return 1;
    }
    int i = 0;
    while (i < *size) {
        (*arr)[i] = ft_atoi(split[i]);
        i++;
    }
    free_split_array(split);
    return 0;
}

int parse_args(int argc, char **argv, int **arr, int *size) {
    if (argc == 2)
        return parse_args_split(argv[1], arr, size);
    *size = argc - 1;
    *arr = malloc(sizeof(int) * (*size));
    if (!*arr) return 1;
    int i = 0;
    while (i < *size) {
        (*arr)[i] = ft_atoi(argv[i + 1]);
        i++;
    }
    return 0;
}

/* -------------------------
   main
   ------------------------- */
int main(int argc, char **argv) {
    if (argc < 2)
        return 0;
    if (check_args(argc, argv) == 1)
        error_exit();
    t_node *a = NULL;
    t_node *b = NULL;
    int *arr;
    int size;
    if (parse_args(argc, argv, &arr, &size) == 1)
        return 1;
    if (check_duplicate(arr, size) == 1)
        error_exit();
    init_stack_a(&a, arr, size);
    index_stack(a, arr, size);
    do_sort(&a, &b, size);
    free(arr);
    free_stack(&a);
    free_stack(&b);
    return 0;
}
