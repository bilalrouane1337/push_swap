/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 20:50:46 by brouane           #+#    #+#             */
/*   Updated: 2026/02/01 20:52:30 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	print_result(t_stack_node *a, t_stack_node *b)
{
	if (is_sorted_stack(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}

int	checker(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	t_data			data;

	stack_a = NULL;
	stack_b = NULL;
	if (initialize_data(argc, argv, &data))
		return (1);
	if (sort_numbers(data.sorted_numbers, data.count)
		|| assign_to_stack(&stack_a,
			data.original_numbers,
			data.sorted_numbers,
			data.count))
		return (free_and_exit(&stack_a, &stack_b, &data, 0), 1);
	if (!read_and_execute(&stack_a, &stack_b))
		return (free_and_exit(&stack_a, &stack_b, &data, 1), 1);
	print_result(stack_a, stack_b);
	free_and_exit(&stack_a, &stack_b, &data, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	return (checker(argc, argv));
}
