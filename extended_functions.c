/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extended_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:19:53 by brouane           #+#    #+#             */
/*   Updated: 2026/02/01 20:56:06 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	initialize_data(int argc, char **argv, t_data *data)
{
	if (argc == 1)
		return (1);
	data->count = count_all_nums(argv + 1, argc);
	data->array = array_manager(argv + 1, argc, data->count);
	numbers_manager(&data->array, data->count,
		&data->sorted_numbers, &data->original_numbers);
	if (check_for_errors(&data->array,
			&data->original_numbers, data->count))
		return (free_pointers(data->array,
				&data->sorted_numbers, &data->original_numbers,
				data->count), 1);
	numbers_copy(data->sorted_numbers, data->original_numbers, data->count);
	return (0);
}

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
