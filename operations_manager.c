/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 20:58:39 by brouane           #+#    #+#             */
/*   Updated: 2026/02/01 20:58:40 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_sorter(t_stack_node **stack_a)
{
	ra(stack_a, 1);
}

void	five_sorter(t_stack_node **stack_a, t_stack_node **stack_b, int count)
{
	push_from_a(stack_a, stack_b, count);
	three_sorter(stack_a);
	push_back_to_a(stack_a, stack_b, count - 3);
}

void	chunk_sorter(t_stack_node **stack_a, t_stack_node **stack_b, int count)
{
	push_to_b(stack_a, stack_b, count);
	push_back_to_a(stack_a, stack_b, count);
}

void	operations_manager(t_stack_node **stack_a, t_stack_node **stack_b,
	int count)
{
	if (count == 2)
		two_sorter(stack_a);
	else if (count == 3)
		three_sorter(stack_a);
	else if (count <= 5)
		five_sorter(stack_a, stack_b, count);
	else
		chunk_sorter(stack_a, stack_b, count);
}
