/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: homura <homura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:52:59 by homura            #+#    #+#             */
/*   Updated: 2025/11/08 17:53:00 by homura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/stdio/ft_printf/ft_printf.h"

// #include <stdio.h>
#include <stdlib.h>

//先頭2つの要素を入れ替える
void	sa(t_node **a)
{
	t_node	*first;
	t_node	*second;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	second = (*a)->next;
	first->next = second->next;
	second->next = first;
	*a = second;
	ft_printf("sa\n");
}

void	ra(t_node **a)
{
	t_node	*first;
	t_node	*cur;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	cur = *a;
	while (cur->next)
		cur = cur->next;
	*a = first->next;
	first->next = NULL;
	cur->next = first;
	ft_printf("ra\n");
}

void	rra(t_node **a)
{
	t_node	*cur;
	t_node	*prev;

	if (!*a || !(*a)->next)
		return ;
	cur = *a;
	prev = NULL;
	while (cur->next)
	{
		prev = cur;
		cur = cur->next;
	}
	prev->next = NULL;
	cur->next = *a;
	*a = cur;
	ft_printf("rra\n");
}

void	pb(t_node **a, t_node **b)
{
	int	val;

	if (!*a)
		return ;
	val = pop_front(a);
	push_front(b, val);
	ft_printf("pb\n");
}

void	pa(t_node **a, t_node **b)
{
	int	val;

	if (!*b)
		return ;
	val = pop_front(b);
	push_front(a, val);
	ft_printf("pa\n");
}
