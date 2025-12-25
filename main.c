/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouane <brouane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 16:53:12 by brouane           #+#    #+#             */
/*   Updated: 2025/12/24 22:20:34 by brouane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_putword(char const *s, int i, int word_len)
{
	int	j;
    char *word = malloc(word_len + 1);

	j = 0;
	while (word_len > i)
	{
		word[j] = s[i];
		j++;
		i++;
	}
	word[j] = '\0';
	return (word);
}

char **prezero_remover(int count, char **numbers)
{
    int max = 1;
    int j = 0;
    char **array = (char **)malloc(count - 1);
    
    while(count > max)
    {
        int i = 0;
        if (numbers[max][i] == 43 || numbers[max][i] == 45)
            i++;
        while (numbers[max][i] == 48)
            i++;
        array[j] = ft_putword(numbers[max], i, ft_strlen(numbers[max]));
        max++;
        j++;
    }
    return (array);
}

int main(int argc, char **argv)
{
    char **array;
    if (argc > 1)
    {
        int max = 1;
        while (argc > max)
        {   
           
            if (error_checker(argv[max]))
                write(1, "e", 1);
            else
                write(1, "g", 1);
            write(1, "\n", 1);
            max++;
        }
        array = prezero_remover(argc, argv);
        printf("%s\n", array[0]);
        // duplicate_checker()
    }
}
