/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:00:46 by brouane           #+#    #+#             */
/*   Updated: 2026/01/31 21:25:42 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*search;

	if (stack && *stack && (*stack)->next)
	{
		temp = *stack;
		*stack = temp->next;
		temp->next = NULL;
		search = *stack;
		while (search->next)
			search = search->next;
		search->next = temp;
	}
}

void	ra(t_stack_node **stack_a, int to_print)
{
	if(to_print)
		ft_print("ra");
	rotate(stack_a);
}

void	rb(t_stack_node **stack_b, int to_print)
{
	if(to_print)
		ft_print("rb");
	rotate(stack_b);
}

void rr(t_stack_node **a, t_stack_node **b, int print)
{
    ra(a, 0);
    rb(b, 0);
    if (print)
        ft_print("rr");
}