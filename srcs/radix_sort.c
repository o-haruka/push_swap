/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: homura <homura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:25:00 by homura            #+#    #+#             */
/*   Updated: 2025/11/10 16:11:47 by homura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_max(t_node *a)
{
	int	max;

	max = a->value;
	while (a)
	{
		if (a->value > max)
			max = a->value;
		a = a->next;
	}
	return (max);
}

void	index_stack(t_node *a, int *arr, int size)
{
	int	i;
	int	rank;
	int	j;

	i = 0;
	while (i < size)
	{
		rank = 0;
		j = 0;
		while (j < size)
		{
			if (arr[j] < arr[i])
				rank++;
			j++;
		}
		a->value = rank;
		a = a->next;
		i++;
	}
}

static int	get_max_bits(int max)
{
	int	max_bits;

	max_bits = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void	sort_by_bit(t_node **a, t_node **b, int bit, int size)
{
	int	j;
	int	num;

	j = 0;
	while (j < size)
	{
		num = (*a)->value;
		if (((num >> bit) & 1) == 0)
			pb(a, b);
		else
			ra(a);
		j++;
	}
	while (*b)
		pa(a, b);
}

void	radix_sort(t_node **a, t_node **b, int size)
{
	int	max;
	int	max_bits;
	int	bit;

	max = get_max(*a);
	max_bits = get_max_bits(max);
	bit = 0;
	while (bit < max_bits)
	{
		sort_by_bit(a, b, bit, size);
		bit++;
	}
}
