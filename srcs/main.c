/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: homura <homura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:52:53 by homura            #+#    #+#             */
/*   Updated: 2025/11/13 21:44:48 by homura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>

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

void	do_sort(t_node **a, t_node **b, int size)
{
	if (size <= 1 || is_sorted(*a))
		return ;
	else if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
	}
	else if (size == 3)
		sort_three(a);
	else if (size == 4 || size == 5)
		sort_small(a, b, size);
	else
		radix_sort(a, b, size);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		*arr;
	int		size;

	if (argc < 2)
		return (0);
	if (check_args(argc, argv) == ERROR)
		error_exit();
	a = NULL;
	b = NULL;
	if (parse_args(argc, argv, &arr, &size) == ERROR)
		error_exit();
	if (check_duplicate(arr, size) == ERROR)
	{
		free(arr);
		error_exit();
	}
	init_stack_a(&a, arr, size);
	index_stack(a, arr, size);
	do_sort(&a, &b, size);
	free(arr);
	free_stack(&a);
	free_stack(&b);
	return (SUCCESS);
}
