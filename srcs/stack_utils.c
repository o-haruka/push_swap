/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: homura <homura@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:53:05 by homura            #+#    #+#             */
/*   Updated: 2025/11/08 18:38:28 by homura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>

/* -------------------------
   基本スタック操作
   ------------------------- */
void	push_front(t_node **stack, int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		exit(1);
	new->value = value;
	new->next = *stack;
	*stack = new;
}

int	pop_front(t_node **stack)
{
	t_node	*tmp;
	int		val;

	if (!*stack)
		return (0);
	tmp = *stack;
	val = tmp->value;
	*stack = tmp->next;
	free(tmp);
	return (val);
}

int	list_size(t_node *a)
{
	int	n;

	n = 0;
	while (a)
	{
		n++;
		a = a->next;
	}
	return (n);
}
