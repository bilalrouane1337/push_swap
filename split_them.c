/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_them.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 16:37:25 by brouane           #+#    #+#             */
/*   Updated: 2026/02/03 21:56:58 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putword(char *word, char const *argv, int i, int word_len)
{
	int	j;

	j = 0;
	while (word_len > 0)
	{
		word[j] = argv[i - word_len];
		j++;
		word_len--;
	}
	word[j] = '\0';
}

int	ft_split_words(char const *argv, char ***array, int num_words, int index)
{
	int	i;
	int	word_len;
	int	reached_word;

	i = 0;
	reached_word = 0;
	while (reached_word < num_words)
	{
		word_len = 0;
		while (argv[i] && argv[i] == 32)
			i++;
		while (argv[i] && argv[i] != 32)
		{
			i++;
			word_len++;
		}
		(*array)[index] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!(*array)[index])
			return (free_array(*array, index), -1);
		ft_putword((*array)[index], argv, i, word_len);
		reached_word++;
		index++;
	}
	(*array)[index] = NULL;
	return (index);
}

int	split_them(char const *argv, char ***array, int index)
{
	unsigned int	num_words;
	int				index_reached;

	num_words = ft_count_words(argv, 32);
	index_reached = ft_split_words(argv, array, num_words, index);
	return (index_reached);
}
