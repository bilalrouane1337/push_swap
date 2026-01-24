/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 21:36:37 by brouane           #+#    #+#             */
/*   Updated: 2026/01/24 19:04:48 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*swap(t_stack_node **stack)
{
	t_stack_node	*temp;

	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	return (*stack);
}

t_stack_node	*sa(t_stack_node **stack_a)
{
	ft_print("sa");
	return (swap(stack_a));
}

t_stack_node	*sb(t_stack_node **stack_b)
{
	ft_print("sb");
	return (swap(stack_b));
}
