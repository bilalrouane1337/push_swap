/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:02:43 by brouane           #+#    #+#             */
/*   Updated: 2026/01/20 18:21:23 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_all_nums(char **argv, int argc)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (i < argc - 1)
	{
		c += ft_count_words(argv[i], ' ');
		i++;
	}
	return (c);
}

char	**array_manager(char **argv, int argc, int count)
{
	int		i;
	int		temp_index;
	char	**array;
	int		index_reached;

	index_reached = 0;
	array = (char **)malloc(sizeof(char *) * (count + 1));
	if (count == 0 || !array)
		return (free_array(array, index_reached), NULL);
	i = 0;
	while (i < argc - 1)
	{
		temp_index = index_reached;
		index_reached = split_them(argv[i++], array, index_reached);
		if (index_reached == temp_index || index_reached == -1)
			return (free_array(array, index_reached), NULL);
	}
	return (array);
}

void	numbers_manager(char ***array, int count, long **numbers,
			long **unordered_numbers)
{
	*numbers = (long *)malloc(sizeof(long) * count);
	*unordered_numbers = (long *)malloc(sizeof(long) * count);
	if (!*numbers || !*unordered_numbers)
		free_pointers(*array, numbers, unordered_numbers, count);
}

void	numbers_copy(long *numbers, long *unordered_numbers, int c)
{
	int	i;

	i = 0;
	while (i < c)
	{
		unordered_numbers[i] = numbers[i];
		i++;
	}
}

int	sort_numbers(long *numbers, int c)
{
	int		i;
	int		j;
	int		flag;
	long	temp;

	flag = 0;
	i = 0;
	while (i < c - 1)
	{
		j = i + 1;
		while (j <= c - 1)
		{
			if (numbers[i] > numbers[j])
			{
				temp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = temp;
				flag = 1;
			}
			j++;
		}
		i++;
	}
	return (flag);
}
