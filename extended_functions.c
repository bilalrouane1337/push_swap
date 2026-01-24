/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extended_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:19:53 by brouane           #+#    #+#             */
/*   Updated: 2026/01/24 19:03:03 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	assign_to_stack(t_stack_node **stack, long *unordered_numbers,
		long *numbers, int c)
{
	int	i;
	int	index;

	i = 0;
	while (i < c)
	{
		index = find_index(unordered_numbers[i], numbers, c);
		if (ft_lstadd_back(stack, unordered_numbers[i], index))
			return (1);
		i++;
	}
	return (0);
}
