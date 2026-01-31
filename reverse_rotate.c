/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:01:27 by brouane           #+#    #+#             */
/*   Updated: 2026/01/31 21:26:14 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	t_stack_node	*prev;

	if (stack && *stack && (*stack)->next)
	{
		prev = NULL;
		last = *stack;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}

void	rra(t_stack_node **stack_a, int to_print)
{
	if(to_print)
		ft_print("rra");
	reverse_rotate(stack_a);
}

void	rrb(t_stack_node **stack_b, int to_print)
{
	if(to_print)
		ft_print("rrb");
	reverse_rotate(stack_b);
}

void rrr(t_stack_node **a, t_stack_node **b, int print)
{
    rra(a, 0);
    rrb(b, 0);
    if (print)
        ft_print("rrr");
}