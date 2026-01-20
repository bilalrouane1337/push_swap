/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:12:21 by brouane           #+#    #+#             */
/*   Updated: 2026/01/20 18:14:34 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_sorter(stack_node_t **stack_a)
{
	ra(stack_a);
}

void	five_sorter(stack_node_t **stack_a, stack_node_t **stack_b, int c)
{
	push_from_a(stack_a, stack_b, c);
	three_sorter(stack_a);
	push_back_to_a(stack_a, stack_b, c - 3);
}

void	chunk_sorter(stack_node_t **stack_a, stack_node_t **stack_b, int c)
{
	push_to_b(stack_a, stack_b, c);
	push_back_to_a(stack_a, stack_b, c);
}

void	operations_manager(stack_node_t **stack_a, stack_node_t **stack_b,
	int c)
{
	if (c == 2)
		two_sorter(stack_a);
	else if (c == 3)
		three_sorter(stack_a);
	else if (c <= 5)
		five_sorter(stack_a, stack_b, c);
	else
		chunk_sorter(stack_a, stack_b, c);
}
