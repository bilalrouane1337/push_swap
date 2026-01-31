/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 21:36:37 by brouane           #+#    #+#             */
/*   Updated: 2026/01/31 21:25:11 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_node **stack)
{
	t_stack_node	*temp;

	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}

void	sa(t_stack_node **stack_a, int to_print)
{
	if(to_print)
		ft_print("sa");
	swap(stack_a);
}

void	sb(t_stack_node **stack_b, int to_print)
{
	if(to_print)
		ft_print("sb");
	swap(stack_b);
}

void ss(t_stack_node **a, t_stack_node **b, int print)
{
    sa(a, 0);
    sb(b, 0);
    if (print)
        ft_print("ss");
}