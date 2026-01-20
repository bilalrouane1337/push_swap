/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:13:03 by brouane           #+#    #+#             */
/*   Updated: 2026/01/20 18:23:45 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sorter_cases(stack_node_t **stack_a, int a, int b, int c)
{
	if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a);
}

void	three_sorter(stack_node_t **stack_a)
{
	stack_node_t	*second;
	stack_node_t	*third;
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
