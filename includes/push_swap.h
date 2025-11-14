/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: homura <homura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:49:45 by homura            #+#    #+#             */
/*   Updated: 2025/11/13 19:57:40 by homura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/stdio/ft_printf/ft_printf.h"
# include <stddef.h>

# define SUCCESS 0
# define ERROR 1
# define MALLOC_ERROR 1
# define PARSE_ERROR 1
# define INVALID_INPUT 1
# define TRUE 1
# define FALSE 0

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

void				push_front(t_node **stack, int value);
int					pop_front(t_node **stack);
void				free_stack(t_node **stack);

void				sa(t_node **a);
void				sb(t_node **b);
void				ss(t_node **a, t_node **b);
void				ra(t_node **a);
void				rb(t_node **b);
void				rr(t_node **a, t_node **b);
void				rra(t_node **a);
void				rrb(t_node **b);
void				rrr(t_node **a, t_node **b);
void				pb(t_node **a, t_node **b);
void				pa(t_node **a, t_node **b);

void				sort_three(t_node **a);
void				sort_small(t_node **a, t_node **b, int size);
int					find_min_pos(t_node *a);
int					is_sorted(t_node *a);

int					get_max(t_node *a);
void				index_stack(t_node *a, int *arr, int size);
void				radix_sort(t_node **a, t_node **b, int size);

int					list_size(t_node *a);
void				free_split_array(char **arr);

void				error_exit(void);
int					check_args(int argc, char **argv);
int					check_duplicate(int *args, size_t counter);

int					parse_args(int argc, char **argv, int **arr, int *size);

void				init_stack_a(t_node **a, int *arr, int size);
void				do_sort(t_node **a, t_node **b, int size);

#endif
