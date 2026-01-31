/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 20:50:46 by brouane           #+#    #+#             */
/*   Updated: 2026/01/31 21:36:35 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

typedef struct s_data
{
	char	**array;
	long	*original_numbers;
	long	*sorted_numbers;
	int		count;
}	t_data;

/* ------------------------------------------------------------ */

static int	is_sorted_stack(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->index > stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/* ------------------------------------------------------------ */

static int	exec_instruction(char *line,
			t_stack_node **a, t_stack_node **b)
{
	if (!ft_strcmp(line, "sa\n"))
		sa(a, 0);
	else if (!ft_strcmp(line, "sb\n"))
		sb(b, 0);
	else if (!ft_strcmp(line, "ss\n"))
		ss(a, b, 0);
	else if (!ft_strcmp(line, "pa\n"))
		pa(a, b, *b, 0);
	else if (!ft_strcmp(line, "pb\n"))
		pb(a, b, *a, 0);
	else if (!ft_strcmp(line, "ra\n"))
		ra(a, 0);
	else if (!ft_strcmp(line, "rb\n"))
		rb(b, 0);
	else if (!ft_strcmp(line, "rr\n"))
		rr(a, b, 0);
	else if (!ft_strcmp(line, "rra\n"))
		rra(a, 0);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(b, 0);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(a, b, 0);
	else
		return (0);
	return (1);
}

/* ------------------------------------------------------------ */

static int	read_and_execute(t_stack_node **a, t_stack_node **b)
{
	char	*line;

	while ((line = get_next_line(0)))
	{
		if (!exec_instruction(line, a, b))
		{
			free(line);
			return (0);
		}
		free(line);
	}
	return (1);
}

/* ------------------------------------------------------------ */

static int	checker(int argc, char **argv)
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
			data.original_numbers,
			data.sorted_numbers,
			data.count))
	{
		free_all_stacks(&stack_a, &stack_b);
		free_pointers(data.array,
			&data.sorted_numbers,
			&data.original_numbers,
			data.count);
		return (1);
	}

	if (!read_and_execute(&stack_a, &stack_b))
	{
		write(2, "Error\n", 6);
		free_all_stacks(&stack_a, &stack_b);
		free_pointers(data.array,
			&data.sorted_numbers,
			&data.original_numbers,
			data.count);
		return (1);
	}

	if (is_sorted_stack(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);

	free_all_stacks(&stack_a, &stack_b);
	free_pointers(data.array,
		&data.sorted_numbers,
		&data.original_numbers,
		data.count);
	return (0);
}

/* ------------------------------------------------------------ */

int	main(int argc, char **argv)
{
	return (checker(argc, argv));
}