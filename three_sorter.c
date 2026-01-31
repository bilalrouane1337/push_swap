/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:13:03 by brouane           #+#    #+#             */
/*   Updated: 2026/01/31 21:31:48 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sorter_cases(t_stack_node **stack_a, int a, int b, int c)
{
	if (a > b && b < c && a < c)
		sa(stack_a, 1);
	else if (a > b && b > c)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a, 1);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a, 1);
}

void	three_sorter(t_stack_node **stack_a)
{
	t_stack_node	*second;
	t_stack_node	*third;
	int				a;
	int				b;
	int				c;

	second = (*stack_a)->next;
	third = second->next;
	a = (*stack_a)->index;
	b = second->index;
	c = third->index;
	three_sorter_cases(stack_a, a, b, c);
}
