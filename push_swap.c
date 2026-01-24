/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 16:53:12 by brouane           #+#    #+#             */
/*   Updated: 2026/01/24 19:04:06 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_data
{
	char	**array;
	long	*numbers;
	long	*unordered_numbers;
	int		count;
}	t_data;

int	initialize_data(int argc, char **argv, t_data *data)
{
	if (argc == 1 || (argc == 2 && !**(argv + 1)))
		return (1);
	data->count = count_all_nums(argv + 1, argc);
	data->array = array_manager(argv + 1, argc, data->count);
	numbers_manager(&data->array, data->count,
		&data->numbers, &data->unordered_numbers);
	if (data->array == NULL)
		return (1);
	if (check_for_errors(&data->array,
			&data->numbers, data->count))
		return (free_pointers(data->array,
				&data->numbers, &data->unordered_numbers,
				data->count), 1);
	numbers_copy(data->numbers, data->unordered_numbers, data->count);
	return (0);
}

int	push_swap(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	t_data			data;

	if (initialize_data(argc, argv, &data))
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	if (!sort_numbers(data.numbers, data.count)
		|| assign_to_stack(&stack_a,
			data.unordered_numbers, data.numbers, data.count))
	{
		free_all_stacks(&stack_a, &stack_b);
		free_pointers(data.array, &data.numbers,
			&data.unordered_numbers, data.count);
		return (1);
	}
	operations_manager(&stack_a, &stack_b, data.count);
	free_all_stacks(&stack_a, &stack_b);
	free_pointers(data.array, &data.numbers,
		&data.unordered_numbers, data.count);
	return (0);
}

int	main(int argc, char **argv)
{
	push_swap(argc, argv);
}
