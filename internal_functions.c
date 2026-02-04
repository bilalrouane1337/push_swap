/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:02:43 by brouane           #+#    #+#             */
/*   Updated: 2026/02/04 23:16:22 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_all_nums(char **argv, int argc)
{
	int	i;
	int	count;
	int	holder;

	i = 0;
	count = 0;
	while (i < argc - 1)
	{
		holder = ft_count_words(argv[i], 32);
		if (holder == 0)
		{
			ft_print_error("Error");
			exit(1);
		}
		count += holder;
		i++;
	}
	return (count);
}

char	**array_manager(char **argv, int argc, int count)
{
	int		i;
	char	**array;
	int		index_reached;

	index_reached = 0;
	array = (char **)malloc(sizeof(char *) * (count + 1));
	if (!array)
		exit(1);
	i = 0;
	while (i < argc - 1)
	{
		index_reached = split_them(argv[i++], &array, index_reached);
		if (index_reached == -1)
			exit(1);
	}
	return (array);
}

void	numbers_manager(char ***array, int count, long **sorted_numbers,
			long **original_numbers)
{
	*sorted_numbers = (long *)malloc(sizeof(long) * count);
	*original_numbers = (long *)malloc(sizeof(long) * count);
	if (!*sorted_numbers || !*original_numbers)
	{
		free_pointers(*array, sorted_numbers, original_numbers, count);
		exit(1);
	}
}

void	numbers_copy(long *sorted_numbers, long *original_numbers, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		sorted_numbers[i] = original_numbers[i];
		i++;
	}
}

int	sort_numbers(long *sorted_numbers, int count)
{
	int		i;
	int		j;
	int		flag;
	long	temp;

	flag = 1;
	i = 0;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (sorted_numbers[i] > sorted_numbers[j])
			{
				temp = sorted_numbers[i];
				sorted_numbers[i] = sorted_numbers[j];
				sorted_numbers[j] = temp;
				flag = 0;
			}
			j++;
		}
		i++;
	}
	return (flag);
}
