/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: homura <homura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:20:00 by homura            #+#    #+#             */
/*   Updated: 2025/11/08 18:38:22 by homura           ###   ########.fr       */
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

static void	move_min_to_top(t_node **a)
{
	int	pos;
	int	sz;
	int	steps;

	pos = find_min_pos(*a);
	sz = list_size(*a);
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

static void	sort_remaining(t_node **a)
{
	if (list_size(*a) == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
	}
	else if (list_size(*a) == 3)
		sort_three(a);
}

void	sort_small(t_node **a, t_node **b)
{
	while (list_size(*a) > 3)
	{
		move_min_to_top(a);
		pb(a, b);
	}
	sort_remaining(a);
	while (*b)
		pa(a, b);
}
