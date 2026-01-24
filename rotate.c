/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:00:46 by brouane           #+#    #+#             */
/*   Updated: 2026/01/24 19:04:36 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*rotate(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*search;

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

t_stack_node	*ra(t_stack_node **stack_a)
{
	ft_print("ra");
	return (rotate(stack_a));
}

t_stack_node	*rb(t_stack_node **stack_b)
{
	ft_print("rb");
	return (rotate(stack_b));
}
