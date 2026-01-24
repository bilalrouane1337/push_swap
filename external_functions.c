/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 19:51:51 by brouane           #+#    #+#             */
/*   Updated: 2026/01/24 22:36:11 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_words(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

int	find_index(int value, long *sorted_numbers, int c)
{
	int	index;

	index = 0;
	while (c > index)
	{
		if (value == sorted_numbers[index])
			break;
		index++;
	}
	return (index);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
