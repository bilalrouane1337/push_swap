/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 16:37:25 by brouane           #+#    #+#             */
/*   Updated: 2025/12/31 18:07:26 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int free_array(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (0);
}

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

	i = 0;
	word_len = 0;
	int word2 = 0;
	while (word2 < num_words)
	{
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
		word_len = 0;
		word++;
		word2++;
	}
	s2[word] = NULL;
	return (word);
}

int ft_split_c(char const *s, char **s2, char c, int word)
{
	unsigned int	num_words;
	
	if (!s)
		return (0);
	num_words = ft_count_words(s, c);
	int wordd = ft_split_words(s, c, s2, num_words, word);
	printf("aa\n");
	return (wordd);
}
