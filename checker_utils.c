/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 20:41:53 by brouane           #+#    #+#             */
/*   Updated: 2026/02/01 20:55:17 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	is_sorted_stack(t_stack_node *stack)
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

void	free_and_exit(
	t_stack_node **a,
	t_stack_node **b,
	t_data *data,
	int ret)
{
	free_all_stacks(a, b);
	free_pointers(
		data->array,
		&data->sorted_numbers,
		&data->original_numbers,
		data->count);
	if (ret)
		write(2, "Error\n", 6);
}

int	exec_instruction(
	char *line,
	t_stack_node **a,
	t_stack_node **b)
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

int	read_and_execute(
	t_stack_node **a,
	t_stack_node **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!exec_instruction(line, a, b))
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	return (1);
}
