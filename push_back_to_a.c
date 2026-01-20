/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:15:27 by brouane           #+#    #+#             */
/*   Updated: 2026/01/20 18:15:26 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	which_position(stack_node_t *stack, int real_len)
{
	int	pos;

	pos = 0;
	while (stack && stack->index != real_len)
	{
		stack = stack->next;
		pos++;
	}
	return (pos);
}

void	push_using_rb(stack_node_t **stack_a, stack_node_t **stack_b,
		int *position, int *real_len)
{
	while (*stack_b && *position > 0)
	{
		rb(stack_b);
		(*position)--;
	}
	if (*stack_b)
	{
		pa(stack_a, stack_b, *stack_b);
		(*real_len)--;
	}
}

void	push_using_rrb(stack_node_t **stack_a, stack_node_t **stack_b,
		int *position, int *real_len)
{
	while (*stack_b && *position <= *real_len)
	{
		rrb(stack_b);
		(*position)++;
	}
	if (*stack_b)
	{
		pa(stack_a, stack_b, *stack_b);
		(*real_len)--;
	}
}

void	push_back_to_a(stack_node_t **stack_a, stack_node_t **stack_b, int c)
{
	int	real_len;
	int	position;

	real_len = c - 1;
	while (*stack_b)
	{
		if ((*stack_b)->index == real_len)
		{
			pa(stack_a, stack_b, *stack_b);
			real_len--;
		}
		else
		{
			position = which_position(*stack_b, real_len);
			if (position < real_len / 2)
				push_using_rb(stack_a, stack_b, &position, &real_len);
			else
				push_using_rrb(stack_a, stack_b, &position, &real_len);
		}
	}
}
