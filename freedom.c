/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:28:25 by brouane           #+#    #+#             */
/*   Updated: 2026/01/24 19:03:17 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_array(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (-1);
}

void	free_pointers(char **array, long **numbers, long **unordered_numbers,
			int len)
{
	free_array(array, len);
	free(*numbers);
	free(*unordered_numbers);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;

	if (!stack)
		return ;
	temp = *stack;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

void	free_all_stacks(t_stack_node **stack_a, t_stack_node **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
}
