/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:18:55 by brouane           #+#    #+#             */
/*   Updated: 2026/02/01 20:25:44 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_max_range(int count)
{
	if (count <= 10)
		return (5);
	if (count <= 100)
		return (16);
	return (32);
}

void	push_to_b(t_stack_node **stack_a, t_stack_node **stack_b, int count)
{
	int				min_range;
	int				max_range;

	min_range = 0;
	max_range = set_max_range(count);
	while (*stack_a)
	{
		if ((*stack_a)->index <= min_range)
		{
			pb(stack_a, stack_b, *stack_a, 1);
			min_range++;
		}
		else if ((*stack_a)->index <= min_range + max_range)
		{
			pb(stack_a, stack_b, *stack_a, 1);
			rb(stack_b, 1);
			min_range++;
		}
		else
			ra(stack_a, 1);
	}
}
