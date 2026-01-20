/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:37:28 by brouane           #+#    #+#             */
/*   Updated: 2026/01/20 16:53:48 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack_node_t	*ft_lstnew(long value, int index)
{
	stack_node_t	*node;

	node = (stack_node_t *)malloc(sizeof(stack_node_t));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = index;
	node->next = NULL;
	return (node);
}

int	ft_lstadd_back(stack_node_t **lst, long value, int index)
{
	stack_node_t	*start;
	stack_node_t	*new;

	new = ft_lstnew(value, index);
	if (new == NULL)
		return (1);
	new->next = NULL;
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
