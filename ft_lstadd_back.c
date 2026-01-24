/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:37:28 by brouane           #+#    #+#             */
/*   Updated: 2026/01/24 22:22:47 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*ft_lstnew(long value, int index)
{
	t_stack_node	*node;

	node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = index;
	node->next = NULL;
	return (node);
}

int	ft_lstadd_back(t_stack_node **lst, long value, int index)
{
	t_stack_node	*start;
	t_stack_node	*new;

	new = ft_lstnew(value, index);
	if (new == NULL)
		return (1);
	if (*lst)
	{
		start = *lst;
		while (start->next)
			start = start->next;
		start->next = new;
	}
	else
		*lst = new;
	return (0);
}
