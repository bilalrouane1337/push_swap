/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:01:27 by brouane           #+#    #+#             */
/*   Updated: 2026/01/20 18:18:43 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack_node_t	*reverse_rotate(stack_node_t **stack)
{
	stack_node_t	*curr;
	stack_node_t	*first;
	stack_node_t	*prev;

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

stack_node_t	*rra(stack_node_t **stack_a)
{
	ft_print("rra");
	return (reverse_rotate(stack_a));
}

stack_node_t	*rrb(stack_node_t **stack_b)
{
	ft_print("rrb");
	return (reverse_rotate(stack_b));
}
