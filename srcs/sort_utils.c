/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: homura <homura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:20:00 by homura            #+#    #+#             */
/*   Updated: 2025/11/10 20:53:40 by homura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_node **a)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z && x > z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z && x > z)
		rra(a);
}

int	find_min_pos(t_node *a)
{
	int		pos;
	int		min_pos;
	int		min;
	t_node	*cur;

	pos = 0;
	min_pos = 0;
	min = a->value;
	cur = a;
	while (cur)
	{
		if (cur->value < min)
		{
			min = cur->value;
			min_pos = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (min_pos);
}

static void	move_min_to_top(t_node **a, int sz)
{
	int	pos;
	int	steps;

	pos = find_min_pos(*a);
	if (pos == 0)
		return ;
	else if (pos <= sz / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		steps = sz - pos;
		while (steps-- > 0)
			rra(a);
	}
}

void	sort_small(t_node **a, t_node **b, int size)
{
	if (size == 5)
	{
		move_min_to_top(a, size);
		pb(a, b);
		move_min_to_top(a, size - 1);
		pb(a, b);
	}
	else if (size == 4)
	{
		move_min_to_top(a, size);
		pb(a, b);
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}

int	is_sorted(t_node *a)
{
	t_node	*cur;

	if (!a)
		return (1);
	cur = a;
	while (cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}
