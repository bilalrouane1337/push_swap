/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extended_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:19:53 by brouane           #+#    #+#             */
/*   Updated: 2026/01/24 22:10:20 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	assign_to_stack(t_stack_node **stack, long *original_numbers,
		long *sorted_numbers, int count)
{
	int	i;
	int	index;

	i = 0;
	while (i < count)
	{
		index = find_index(original_numbers[i], sorted_numbers, count);
		if (ft_lstadd_back(stack, original_numbers[i], index))
			return (1);
		i++;
	}
	return (0);
}
