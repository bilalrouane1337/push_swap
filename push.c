/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:03:00 by brouane           #+#    #+#             */
/*   Updated: 2026/01/20 18:17:42 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack_node_t	*push(stack_node_t **from_stack,
		stack_node_t **to_stack, stack_node_t *to_push)
{
	if (!from_stack || !to_stack || !*from_stack)
		return (NULL);
	*from_stack = to_push->next;
	to_push->next = *to_stack;
	*to_stack = to_push;
	return (*from_stack);
}

stack_node_t	*pb(stack_node_t **stack_a, stack_node_t **stack_b,
		stack_node_t *to_push)
{
	ft_print("pb");
	return (push(stack_a, stack_b, to_push));
}

stack_node_t	*pa(stack_node_t **stack_a, stack_node_t **stack_b,
		stack_node_t *to_push)
{
	ft_print("pa");
	return (push(stack_b, stack_a, to_push));
}
