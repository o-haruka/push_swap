/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: homura <homura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:52:53 by homura            #+#    #+#             */
/*   Updated: 2025/11/08 18:15:05 by homura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"
#include "../libft/stdio/ft_printf/ft_printf.h"
#include <stdlib.h>

/* -------------------------
   main整頓用関数
   ------------------------- */
// int配列からスタックAを逆順で初期化
void	init_stack_a(t_node **a, int *arr, int size)
{
	int	j;

	j = size - 1;
	while (0 <= j)
	{
		push_front(a, arr[j]);
		j--;
	}
}

// ソート処理を分岐して実行
void	do_sort(t_node **a, t_node **b, int size)
{
	if (size == 1)
	{
	}
	else if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
	}
	else if (size <= 5)
	{
		sort_small(a, b);
	}
	else
	{
		radix_sort(a, b, size);
	}
}

/* -------------------------
   main
   ------------------------- */
int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		*arr;
	int		size;

	if (argc < 2)
		return (0);
	if (check_args(argc, argv) == 1)
		error_exit();
	a = NULL;
	b = NULL;
	if (parse_args(argc, argv, &arr, &size) == 1)
		return (1);
	if (check_duplicate(arr, size) == 1)
		error_exit();
	init_stack_a(&a, arr, size);
	index_stack(a, arr, size);
	do_sort(&a, &b, size);
	free(arr);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
