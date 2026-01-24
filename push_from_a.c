/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_from_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:37:28 by brouane           #+#    #+#             */
/*   Updated: 2026/01/24 19:03:58 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	which_position_in_a(t_stack_node *stack, int real_len)
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

void	push_using_ra(t_stack_node **stack_a, t_stack_node **stack_b,
		int *position, int *real_len)
{
	while (*stack_a && *position > 0)
	{
		ra(stack_a);
		(*position)--;
	}
	if (*stack_a)
	{
		pb(stack_a, stack_b, *stack_a);
		(*real_len)--;
	}
}

void	push_using_rra(t_stack_node **stack_a, t_stack_node **stack_b,
		int *position, int *real_len)
{
	while (*stack_a && *position <= *real_len)
	{
		rra(stack_a);
		(*position)++;
	}
	if (*stack_a)
	{
		pb(stack_a, stack_b, *stack_a);
		(*real_len)--;
	}
}

void	push_from_a(t_stack_node **stack_a, t_stack_node **stack_b, int c)
{
	int	min_index;
	int	max_index;
	int	position;
	int	right_len;

	min_index = 0;
	max_index = c - 3;
	right_len = c - 1;
	while (*stack_a && min_index < max_index)
	{
		if ((*stack_a)->index == min_index)
		{
			pb(stack_a, stack_b, *stack_a);
			right_len--;
		}
		else
		{
			position = which_position_in_a(*stack_a, min_index);
			if (position <= right_len / 2)
				push_using_ra(stack_a, stack_b, &position, &right_len);
			else
				push_using_rra(stack_a, stack_b, &position, &right_len);
		}
		min_index++;
	}
}
