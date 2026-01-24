/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:03:00 by brouane           #+#    #+#             */
/*   Updated: 2026/01/24 19:04:23 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*push(t_stack_node **from_stack,
		t_stack_node **to_stack, t_stack_node *to_push)
{
	if (!from_stack || !to_stack || !*from_stack)
		return (NULL);
	*from_stack = to_push->next;
	to_push->next = *to_stack;
	*to_stack = to_push;
	return (*from_stack);
}

t_stack_node	*pb(t_stack_node **stack_a, t_stack_node **stack_b,
		t_stack_node *to_push)
{
	ft_print("pb");
	return (push(stack_a, stack_b, to_push));
}

t_stack_node	*pa(t_stack_node **stack_a, t_stack_node **stack_b,
		t_stack_node *to_push)
{
	ft_print("pa");
	return (push(stack_b, stack_a, to_push));
}
