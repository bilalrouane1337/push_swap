/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_them.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 16:37:25 by brouane           #+#    #+#             */
/*   Updated: 2026/01/10 20:15:43 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_putword(char *word, char const *s, int i, int word_len)
{
	int	j;

	j = 0;
	while (word_len > 0)
	{
		word[j] = s[i - word_len];
		j++;
		word_len--;
	}
	word[j] = '\0';
	return (word);
}

int ft_split_words(char const *s, char c, char **s2, int num_words, int word)
{
	int	i;
	int	word_len;
	int reached_index;

	i = 0;
	reached_index = 0;
	while (reached_index < num_words)
	{
		word_len = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			word_len++;
		}
		s2[word] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!s2)
			return (free_array(s2, word));
		ft_putword(s2[word], s, i, word_len);
		reached_index++;
		word++;
	}
	s2[word] = NULL;
	return (word);
}

int split_them(char const *s, char **s2, char c, int word)
{
	unsigned int	num_words;
	
	if (!s)
		return (word);
	num_words = ft_count_words(s, c);
	int wordd = ft_split_words(s, c, s2, num_words, word);
	return (wordd);
}
