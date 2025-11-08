/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: homura <homura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:49:45 by homura            #+#    #+#             */
/*   Updated: 2025/11/08 18:48:54 by homura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

// 基本操作
void	push_front(t_node **stack, int value);
int		pop_front(t_node **stack);
void	free_stack(t_node **stack);

// 命令
void	sa(t_node **a);
void	ra(t_node **a);
void	rra(t_node **a);
void	pb(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);

// 小さいケース
void	sort_three(t_node **a);
void	sort_five(t_node **a, t_node **b);
void	sort_small(t_node **a, t_node **b);
int		find_min_pos(t_node *a);

// Radix sort
int		get_max(t_node *a);
void	index_stack(t_node *a, int *arr, int size);
void	radix_sort(t_node **a, t_node **b, int size);

// その他
int		list_size(t_node *a);
void	free_split_array(char **arr);

// エラー処理
void	error_exit(void);
int		check_args(int argc, char **argv);
int		check_duplicate(int *args, size_t counter);

// 引数解析
int		parse_args(int argc, char **argv, int **arr, int *size);

// スタック初期化とソート実行
void	init_stack_a(t_node **a, int *arr, int size);
void	do_sort(t_node **a, t_node **b, int size);

#endif
