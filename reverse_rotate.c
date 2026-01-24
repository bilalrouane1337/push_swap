/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:01:27 by brouane           #+#    #+#             */
/*   Updated: 2026/01/24 19:04:30 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*curr;
	t_stack_node	*first;
	t_stack_node	*prev;

	curr = *stack;
	first = *stack;
	if (curr)
	{
		while (curr->next)
		{
			prev = curr;
			curr = curr->next;
		}
		curr->next = first;
		*stack = curr;
		prev->next = NULL;
	}
	return (*stack);
}

t_stack_node	*rra(t_stack_node **stack_a)
{
	ft_print("rra");
	return (reverse_rotate(stack_a));
}

t_stack_node	*rrb(t_stack_node **stack_b)
{
	ft_print("rrb");
	return (reverse_rotate(stack_b));
}
