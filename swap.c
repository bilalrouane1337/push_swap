/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 21:36:37 by brouane           #+#    #+#             */
/*   Updated: 2026/01/20 18:23:27 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack_node_t	*swap(stack_node_t **stack)
{
	stack_node_t	*temp;

	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	return (*stack);
}

stack_node_t	*sa(stack_node_t **stack_a)
{
	ft_print("sa");
	return (swap(stack_a));
}

stack_node_t	*sb(stack_node_t **stack_b)
{
	ft_print("sb");
	return (swap(stack_b));
}
