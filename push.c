/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:03:00 by brouane           #+#    #+#             */
/*   Updated: 2026/02/01 20:59:44 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack_node **from_stack,
		t_stack_node **to_stack, t_stack_node *to_push)
{
	if (from_stack && to_stack && *from_stack)
	{
		*from_stack = to_push->next;
		to_push->next = *to_stack;
		*to_stack = to_push;
	}
}

void	pb(t_stack_node **stack_a, t_stack_node **stack_b,
		t_stack_node *to_push, int to_print)
{
	if (to_print)
		ft_print("pb");
	push(stack_a, stack_b, to_push);
}

void	pa(t_stack_node **stack_a, t_stack_node **stack_b,
		t_stack_node *to_push, int to_print)
{
	if (to_print)
		ft_print("pa");
	push(stack_b, stack_a, to_push);
}
