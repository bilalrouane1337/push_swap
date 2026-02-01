/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 16:53:12 by brouane           #+#    #+#             */
/*   Updated: 2026/02/01 21:01:18 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	t_data			data;

	if (initialize_data(argc, argv, &data))
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	if (sort_numbers(data.sorted_numbers, data.count)
		|| assign_to_stack(&stack_a,
			data.original_numbers, data.sorted_numbers, data.count))
	{
		free_all_stacks(&stack_a, &stack_b);
		free_pointers(data.array, &data.sorted_numbers,
			&data.original_numbers, data.count);
		return (1);
	}
	operations_manager(&stack_a, &stack_b, data.count);
	free_stack(&stack_a);
	free_pointers(data.array, &data.sorted_numbers,
		&data.original_numbers, data.count);
	return (0);
}

int	main(int argc, char **argv)
{
	push_swap(argc, argv);
	return (0);
}
