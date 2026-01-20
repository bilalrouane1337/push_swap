/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:00:46 by brouane           #+#    #+#             */
/*   Updated: 2026/01/20 18:19:32 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack_node_t	*rotate(stack_node_t **stack)
{
	stack_node_t	*temp;
	stack_node_t	*search;

	if (!stack || !*stack || !(*stack)->next)
		return (*stack);
	temp = *stack;
	*stack = temp->next;
	temp->next = NULL;
	search = *stack;
	while (search->next)
		search = search->next;
	search->next = temp;
	return (*stack);
}

stack_node_t	*ra(stack_node_t **stack_a)
{
	ft_print("ra");
	return (rotate(stack_a));
}

stack_node_t	*rb(stack_node_t **stack_b)
{
	ft_print("rb");
	return (rotate(stack_b));
}
